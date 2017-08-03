#include <iostream>
#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;
//#define NWITEMS 262144
#define  NWITEMS 10
#pragma comment(lib,"OpenCL.lib")

//���ı��ļ�����һ��string��
int convertToString(const char *filename,string& s)
{
	size_t size;
	char* str;
	fstream f(filename,(std::fstream::in | std::fstream::binary));
	if(f.is_open())
	{
		size_t fileSize;
		f.seekg(0,std::fstream::end);		//���ļ���������Ϊ����ַ��ƫ�Ƶ�ַΪ0��ָ�붨λ���ļ�������
		size=fileSize=(size_t)f.tellg();	//sizeΪ��λָ�룬λ���ļ�������������ֵΪ�ļ��Ĵ�С
		f.seekg(0,std::fstream::beg);

		str=new char[size+1];
		if(!str)
		{
			f.close();
			return NULL;
		}

		f.read(str,fileSize);
		f.close();
		str[size]='\0';

		s=str;
		delete[] str;
		return 0;
	}
	printf("Error: Failed to open file %s\n",filename);
	return 1;
}


int main(int argc, char* argv[])
{
	//��host�ڴ��д�������������
	float *buf1=0;
	float *buf2=0;
	float *buf=0;
	buf1=(float *)malloc(NWITEMS *sizeof(float));
	buf2=(float *)malloc(NWITEMS *sizeof(float));
	buf =(float *)malloc(NWITEMS *sizeof(float));
	
	//��ʼ��buf1��buf2������
	int i;
	srand((unsigned)time(NULL));
	for(i = 0;i < NWITEMS; i++)
		buf1[i]=rand()%65535;

	srand((unsigned)time(NULL) + 1000);
	for(i = 0;i < NWITEMS; i++)
		buf2[i] = rand()%65535;

	for(i = 0;i < NWITEMS; i++)
		buf[i] = buf1[i] + buf2[i];

	cl_uint status;
	cl_platform_id platform;
	//����ƽ̨����
	status=clGetPlatformIDs(1,&platform,NULL);


	//��ϵͳ�ж��ƽ̨������ͨ������Ĵ���õ�AMD��OpenCLƽ̨
	cl_uint numPlatforms;
	string platformVendor;		//ƽ̨��Ӧ��
	status = clGetPlatformIDs(0,NULL,&numPlatforms);
	if(status != CL_SUCCESS)
	{
		return 0;
	}
	if(0 < numPlatforms)
	{
		cl_platform_id* platforms = new cl_platform_id[numPlatforms];
		status = clGetPlatformIDs(numPlatforms,platforms,NULL);
		char platformName[100];
		for(unsigned i = 0;i < numPlatforms; ++i)
		{
			status = clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR,sizeof(platformName),platformName,NULL);
			platform = platforms[i];
			platformVendor.assign(platformName);
			if(!strcmp(platformName,"Advanced Micro Devices, Inc."))
			{
				break;
			}
		}
		cout<<"Platform Found: "<<platformName<<endl;
		delete[] platforms;
	}

	cl_device_id device;
	//����GPU�豸
	clGetDeviceIDs(platform,CL_DEVICE_TYPE_GPU,1,&device,NULL);
	//����context
	cl_context context = clCreateContext(NULL,1,&device,NULL,NULL,NULL);
	//�����������
	cl_command_queue queue = clCreateCommandQueue(context,device,CL_QUEUE_PROFILING_ENABLE,NULL);
	//��������OpenCL�ڴ���󣬲���buf1�е�����ͨ����ʽ�����ķ�ʽ������clbuf1��
	//buf2������ͨ����ʾ�����ķ�ʽ������clbuf2
	cl_mem clbuf1 = clCreateBuffer(context,CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, NWITEMS*sizeof(cl_float),buf1,NULL);
	cl_mem clbuf2 = clCreateBuffer(context,CL_MEM_READ_ONLY,NWITEMS*sizeof(cl_float),NULL,NULL);
	status = clEnqueueWriteBuffer(queue,clbuf2,1,0,NWITEMS*sizeof(cl_float),buf2,0,0,0);
	cl_mem buffer = clCreateBuffer(context,CL_MEM_WRITE_ONLY,NWITEMS*sizeof(cl_float),NULL,NULL);
	const char *filename = "add.cl";	//�ں˺�����
	string sourceStr;
	status = convertToString(filename,sourceStr);
	const char *source = sourceStr.c_str();
	size_t sourceSize[] = {strlen(source)};
	//�����������
	cl_program program = clCreateProgramWithSource(context,1,&source,sourceSize,NULL);
	//����������
	status = clBuildProgram(program,1,&device,NULL,NULL,NULL);
	if(status != 0)
	{
		printf("clBuild Failed:%d\n",status);
		char tbuf[0x10000];
		clGetProgramBuildInfo(program,device,CL_PROGRAM_BUILD_LOG,0x10000,tbuf,NULL);
		printf("\n%s\n",tbuf);
		return -1;
	}
	//����Kernel����
	cl_kernel kernel = clCreateKernel(program,"vecadd",NULL);
	//����Kernel����
	cl_int clnum = NWITEMS;
	clSetKernelArg(kernel,0,sizeof(cl_mem),(void*)&clbuf1);
	clSetKernelArg(kernel,1,sizeof(cl_mem),(void*)&clbuf2);
	clSetKernelArg(kernel,2,sizeof(cl_mem),(void*)&buffer);
	//ִ��kernel
	cl_event ev;
	size_t global_work_size = NWITEMS;
	clEnqueueNDRangeKernel(queue,kernel,1,NULL,&global_work_size,NULL,0,NULL,&ev);
	clFinish(queue);
	//���ݿ���host�ڴ�
	cl_float *ptr;
	ptr = (cl_float *)clEnqueueMapBuffer(queue,buffer,CL_TRUE,CL_MAP_READ,0,NWITEMS*sizeof(cl_float),0,NULL,NULL,NULL);
	//�����֤����cpu����Ľ���Ƚ�
	if(!memcmp(buf,ptr,NWITEMS))
		printf("Verify passed\n");
	else printf("Verify failed\n");

	if(buf)
		free(buf);
	if(buf1)
		free(buf1);
	if(buf2)
		free(buf2);

	//ɾ��OpenCL��Դ����
	clReleaseMemObject(clbuf1);
	clReleaseMemObject(clbuf2);
	clReleaseMemObject(buffer);
	clReleaseProgram(program);
	clReleaseCommandQueue(queue);
	clReleaseContext(context);


	return 0;
}
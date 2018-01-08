---
layout: post
title:  "OpenCL Matrix multiply"
date:   2018-01-08 10：59：00
categories:  OpenCL
tags: Matrix Transpose
author: CLH
---

* content
{:toc}

# OpenCL simpleMultiply#
OpenCL（GPU）程序，矩阵相乘：         

![](https://i.imgur.com/mjJL9qT.jpg)      

性能调优时，可以用clGetEventProfilingInfo()函数，前提是在创建命令队列时，设置CL_QUEUE_PROFILING_ENABLE标志：     

	cl_command_queue commandQueue = clCreateCommandQueue(contes,device,CL_QUEUE_PROFILING_ENABLE,NULL);         

若要比较在CPU和GPU两种平台的运行时间，可以创建不同的设备：    

	clGetDeviceIDs(platform,CL_DEVICE_TYPE_GPU,1,&device,NULL);	//use GPU device
	clGetDeviceIDs(platform,CL_DEVICE_TYPE_CPU,1,&device,NULL);	//use CPU device      
    
当矩阵A和B的大小为：1000*1000时，使用GPU OpenCL运算所需的时间：      
GPU：     

![](https://i.imgur.com/h5GRyXX.jpg)    

CPU：      
![](https://i.imgur.com/rTp4MoY.jpg)       

----------
【Ref】：     
[1] [Getting started with OpenCL and GPU Computing](https://www.eriksmistad.no/getting-started-with-opencl-and-gpu-computing/)   
[2] [source code](https://github.com/clhne/simpleMultiply)        
[3] [OpenCL异构计算 第2版 张云泉等，清华大学出版社.](http://www.tup.tsinghua.edu.cn/booksCenter/book_05216401.html)        

	
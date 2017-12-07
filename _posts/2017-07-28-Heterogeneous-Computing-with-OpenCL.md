---
layout: post
title:  "Heterogeneous Computing with OpenCL"
date:   2017-07-28 9：49：00
categories:  OpenCL
tags: OpenCL
author: CLH
---

* content
{:toc}

# Heterogeneous Computing with OpenCL #
## OpenCL异构计算(Heterogeneous Computing with OpenCL) ##

开放计算机语言(Open Computing Language,OpenCL)，是非盈利性技术联盟Khronos Group管理的异构编程框架，用于开发可以在不同厂商所生产的各种设备上运行的应用程序。OpenCL提供了基于任务和数据两种并行计算方式，当前支持的CPU包括x86、ARM、和PowerPC(Performance Optimization with Enhanced RISC-Performance Computing,PPC,是一种精简指令集（RISC）架构的中央处理器)，同时支持AMD，Apple，Intel和NVIDIA的显卡；另外OpenCL是跨平台的。    

并行计算中的粒度定义为计算与通信之比，通信和计算交错出现，通过同步事件明确区分开；并行粒度受限于应用程序算法的内在特性。  
### OpenCL规范 ###
规范由四个模型组成：   

1.平台模型：描述协同执行的单个处理器（宿主机Host）及一个或多个能执行OpenCL代码的处理器（设备Devices）。定义了一个抽象的硬件模型，供编程人员用于编写能够在这些设备上执行的**OpenCL C函数（称作kernel）**。如下图所示：     
![](http://i.imgur.com/UEGdaTO.jpg)    

2.执行模型：定义了在主机上如何配置OpenCL环境以及如何在设备上执行kernel，包括在主机端建立OpenCL上下文，提供主机-设备之间的交互机制，定义一个并发模型供在设备上执行kernel所用。     
主机程序：运行在主机上的应用程序，一般由C/C++编写；   
内核程序：运行在设备上的程序，由OpenCL标准编写，是唯一可以从主机上调用执行的函数。   
![](http://i.imgur.com/d5neEv7.jpg)      

3.内存模型：定义被kernel所用的的抽象内在层次（memory hierarchy),无需考虑实际的底层内存架构，尽管内存模型十分接近当前的GPU内在层次，但同样也适用于其他硬件加速器。      
buffer对象：一块地址连续的区域，类似于数组，可以作为任何与图像处理无关的数据载体；buffer类似于C语言中的数组，由malloc()创建；     
  
subbuffer对象：buffer对象的一部分；      
  
image对象：表示二维或三维的图像数据，仅限于图像数据相关数据类型，image 的数据格式由通道序列和通道类型组成。通道序列定义了通道数以及它们的组织顺序，例如CL_RGB, CL_R或CL_ARGB；通道类型的选择非常多，从CL_FLOAR到非常少用的在内存中组织成16位字的CL_UNORM_SHORT_565。image支持的数据格式可能通过调用clGetSupportedImageFormats函数查询。      
image对象**不能通过指针访问**，只能通过read_image()读，或者write_image()写，但不能同时既可读又可写；image被设计成不透明的对象，以利于进行数据填充和其他可能改善设备性能的优化，使用image的目的是允许硬件利用空间局部性来进行硬件加速。       
      
任何时候，只要是新建的内存对象，它都只在一个上下文中有效。      

OpenCL标准1.0和1.1中，仅支持2D和3D image对象，分别使用命令clCreateImage2D()和clCreateImage3D()创建；在OpenCL1.2标准中，引入了更通用的接口clCreateImage()，并且支持1D image对象。  
##### image对象和buffer对象的区别 #####
* 对设备代码是不可见的，不能通过指针直接访问；
* 多维结构；
* 仅限于图像数据相关数据类型，而不能自由实现任意数据结构
* image提供一个额外的功能，支持buffer所不支持的运行时系统和硬件优化，image数据可通过调用clEnqueueMapImage函数实现到主机的映射。
          
从主机端访问image和buffer的主要区别是对数据格式的支持，buffer支持OpenCL所有的基本数据类型以及它们组成的结构体，image支持的数据类型要少得多。

4.编程模型：定义了如何将并发模型映射到物理硬件上。          

OpenCL C代码（编写的代码在OpenCL设备上执行）称为“程序”（program），是kernel函数的集合，kernel是被调度安排到设备上运行的执行单位。   
OpenCL程序在运行时通过调用一系列API进行编译，编译系统针对具体的设备进行优化，OpenCL应用程序能同时移植到AMD、NVIDIA以及Intel的设备上，不需要对这些平台分别进行编译；OpenCL软件仅链接到一个公共运行层（称ICD），所有平台特定的SDK通过一个动态库接口委托给某个厂商的运行时。       

#### 新建kernel的步骤： ####
1. OpenCL源代码以字符串形式存储，如果代码保存在文件中，则必须读到内存并存储为字符串数组；
2. 源代码通过调用clCreateProgramWithSource()转化为一个cl_program对象；
3. 使用clBuildProgram()在多个支持OpenCL的设备上编译程序对象，如果编译错误，则报告错误信息。    
          
kernel的执行需要通过一个入队函数来进行分发。     

#### 写kernel ####


1. kernel以关键字__kernel开始，返回类型必须是void，必须像C函数一样指定指针所指向的地址空间，即声明使用的内存类型；
2. 通过一些API，比如get_global_id之类的得到线程id；
3. buffer可以声明全局内存（__global)或常量内存(__constant)中；
4. image被分配到全局内存，访问限定符(__read_only, __write_only和__read_write)可以随意指定，因为它们与编译器和硬件优化相关。

#### 内存对象地址空间标识符 ####
	__global					/* memory allocated from global address space */
	__constant					/* a special type of read-only memory */
	__local						/* memory shared by a work-group */
	__private					/* private per work-item memory */
	__read_only || __write_only			/* used for image */
      
kernel函数参数如果是内存对象，那么一定是__global,_local或constant。


----------


#### 数据划分 ####

work-item（线程，OpenCL并发执行单位）:在计算单元上运行的kernel程序的每个实例都称为一个word-item，多个word-item组成一个workgroup；        
 
workgroup：多个work-item构成，每个workgroup之间都是相互独立的，通过一个global id（唯一）或者一个workgroup id和一个workgroup内的local id标定一个work-item；     

----------

#### 内存区域 ####
     

![内存区域](http://i.imgur.com/cdcVHKP.jpg)    

----------

#### OpenCL同步 ####
OpenCL采用宽松的同步模型和内存一致性模型   
  
barrier: 实现同一个workgroup内的work-item同步；     
event:   实现在同一个上下文中命令间的同步；事件回调是指在事件达到指定状态时触发，比如，主机在设备运行时为了提高系统效率，将一个主机程序设定为回调函数；    
clFinishi: 实现设备间数据共享；              

----------
#### OpenCL 数据类型 ####
![](http://i.imgur.com/jse2aNM.jpg)   

----------

#### OpenCL编程步骤 ####
![](http://i.imgur.com/YBPhcaw.jpg)   


----------
【Ref】：     
[1] Heterogeneous Computing with OpenCL, OpenCL 1.2 Edition. OpenCL异构计算 第二版   
[2] [Hadoop权威指南](https://pan.baidu.com/s/1eRKAmdG)  （密码: e27j） 
	
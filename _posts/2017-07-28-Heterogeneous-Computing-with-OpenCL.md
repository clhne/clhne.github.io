---
layout: post
title:  "Heterogeneous Computing with OpenCL"
date:   2017-07-28 9：49：00
categories:  OpenCL Heterogeneous Computing
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
buffer对象：一块地址连续的区域，类似于数组，可以作为任何与图像处理无关的数据载体；  
subbuffer对象：buffer对象的一部分；   
image对象：表示二维或三维的图像数据，仅限于图像数据相关数据类型，**不能通过指针访问**；    

4.编程模型：定义了如何将并发模型映射到物理硬件上。     

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
![](http://i.imgur.com/pXoKBYF.jpg)    

----------

#### OpenCL编程步骤 ####
![](http://i.imgur.com/YBPhcaw.jpg)   


----------
【Ref】：     
[1] Heterogeneous Computing with OpenCL, OpenCL 1.2 Edition. OpenCL异构计算 第二版   
[2] [Hadoop权威指南](https://pan.baidu.com/s/1eRKAmdG)  （密码: e27j） 
	
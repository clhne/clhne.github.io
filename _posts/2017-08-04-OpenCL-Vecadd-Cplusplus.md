---
layout: post
title:  "OpenCL Vecadd Cplusplus"
date:   2017-08-04 20：00：00
categories:  OpenCL
tags: Vecadd Cplusplus
author: CLH
---

* content
{:toc}

# OpenCL Vector addition Cplusplus implementation#
OpenCL（GPU）程序，计算两个向量相加的C++实现，与CPU计算结果相比较，熟悉OpenCL编程流程并验证两者结果的一致性。      
伴随着OpenCL标准，Khronos联盟定义了一套C++封装API，C++ API与C API紧密对应（如 cl::Memory对应cl_mem)，拥有使用高级语言的优势，譬如类和异常处理等。             

注：在进行OpenCL程序开发时要注意环境变量的设置：    


1. 在xx项目属性->“VC++目录”->“常规”->“包含目录”,添加“AMD APP SDK”的include文件的路径“C:\Program Files\AMD APP\include”
2. 在xx项目属性->“ 链接器”->“常规”->“附加库目录”，添加“C:\Program Files\AMD APP\lib\x86”
3. 在xx项目属性->“链接器”->“输入”->“附加依赖项”，添加opencl.lib     
           
如果1错误则编译出错；2和3错误则调试运行报错error LNK2019: 无法解析的外部符号 _clGetPlatformIDs@12       

[source code](https://github.com/clhne/clhne.github.io/tree/master/src/vecadd_c_plus_plus)   

----------
【Ref】：     
[1] Heterogeneous Computing with OpenCL, OpenCL 1.2 Edition. OpenCL异构计算 第二版   
[2] [VS2013-OpenCL 环境搭建 helloworld](http://blog.csdn.net/hermittt/article/details/50668850?locationNum=11&fps=1)
	
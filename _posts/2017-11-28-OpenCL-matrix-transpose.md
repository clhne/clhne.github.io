---
layout: post
title:  "OpenCL Matrix Transpose"
date:   2017-11-28 20：14：00
categories:  OpenCL
tags: Matrix Transpose
author: CLH
---

* content
{:toc}

# OpenCL Matrix transpose#
OpenCL（GPU）程序，矩阵转置，对如下的8*8矩阵进行转置运算：    

![](https://i.imgur.com/7jSBOpP.png)     

分块大小为：2*2，一共有（8/2）*（8/2）个矩阵块，分对角线和非对角线上的矩阵块；对角线上的块是矩阵内部行列互换，非对角线上的块与自己对称的矩阵块行列互换，需要处理的工作项的个数为上三角矩阵块的个数：4*（4+1）/2=10个，程序的运行结果如下：    
 
![](https://i.imgur.com/slWPIic.jpg)     
----------
【Ref】：     
[1] [OpenCL实现矩阵转置](http://blog.csdn.net/u011028771/article/details/52733929)   
[2] [source code](https://github.com/clhne/OpenCL-transpose)
	
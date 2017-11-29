---
layout: post
title:  "OpenCL Samples"
date:   2017-11-29 21：42：00
categories:  OpenCL
tags: OpenCL-Samples
author: CLH
---

* content
{:toc}

# OpenCL Samples#
公司的OpenCL环境是刚入职时师姐给配置的，记得当时是先安装了AMD显卡驱动，然后安装了AMD APP SDK，最后安装的是OpenCL GPU调试工具CodeXL。       
但是问题来了，在自己的笔记本上安装之后，提示找不到GPU硬件，Unable to get platforms，猜想是AMD显卡驱动没有安装好，故重装驱动；在AMD官网上按照显卡的型号查找到自己电脑对应的驱动，安装之。           
注意，显卡不是最新的话，最好不要下载AMD官网自动检测的驱动程序，我之前就是下载了官网自动检测的驱动然后OpenCL和CodeXL就检测不到Platform了！对，就是下面的这个东东：     
![](https://i.imgur.com/I0hDgd1.png)        
要自己指定所用显卡对应的驱动：    
![](https://i.imgur.com/fCYU4CN.png)    

安装好之后，打开CodeXL查看系统信息，可检测到GPU：    
![](https://i.imgur.com/kWZxfLp.png)      
     
运行OpenCL Samples中的HelloWorld，结果是这样的：      

![](https://i.imgur.com/vhG09Ot.png)    

记之。      
      
----------
【Ref】：     
[1] [Download AMD Drivers & Software for Radeon, FirePro, APU, CPU, desktops, and laptops](http://support.amd.com/en-us/download)   
[2] [AMD Display Driver](http://support.amd.com/en-us/download/desktop/legacy?product=legacy3&os=Windows%207%20-%2064)     
[3] [APP SDK – A Complete Development Platform](http://developer.amd.com/amd-accelerated-parallel-processing-app-sdk/)    
[4] [CodeXL](https://gpuopen.com/compute-product/codexl/)
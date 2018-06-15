---
layout: post
title:  "Linux CPU and Memory Info"
date:   2018-06-15 09:17:00
categories:  Linux
tags: CPU_Memory_info
author: CLH
---

* content
{:toc}

# Linuxs查询CPU、内存等信息 #

----------
Linux查看CPU相关信息：       
1、cat命令，不需要sudo权限：      

	cat /proc/cpuinfo | grep name | cut -f2 -d: | uniq -c    #查看CPU信息    
	cat /proc/cpuinfo | grep "physical id"| sort| uniq| wc -l  #查看CPU物理个数       
	cat /proc/cpuinfo | grep "cpu cores"| uniq           #查看每个物理CPU中core的个数，即核数
	cat /proc/cpuinfo | grep "processor"| wc -l			 #查看逻辑CPU个数    

结果：   
CPU信息：       		  
![](https://i.imgur.com/8VjY6dK.png)         
![](https://i.imgur.com/IbPw4GC.png)       
物理CPU个数：       
![](https://i.imgur.com/kMQQfbg.png)      
![](https://i.imgur.com/tCMNYQK.png)      
每个物理CPU中的core个数：     
![](https://i.imgur.com/gKsv2JC.png)     
![](https://i.imgur.com/KBGdxSp.png)         
逻辑CPU个数：     
![](https://i.imgur.com/Bn3ZGpw.png)	        
![](https://i.imgur.com/GIZZrN5.png)      

【Ref】  
[1] [Linux查看物理CPU个数、核数、逻辑CPU个数](https://www.cnblogs.com/emanlee/p/3587571.html)      
[2] [查看linux系统的cpu个数线程数量以及型号](https://blog.csdn.net/qq_20641565/article/details/72832273)
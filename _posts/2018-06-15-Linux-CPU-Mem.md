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
1、CPU相关信息，cat+grep 命令，不需要sudo权限：      

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

2、内存相关信息, dmidecode（sudo用户）命令，可用lshw查看所有硬件摘要信息：     

	lshw   #ls hardware       

结果如下：      
![](https://i.imgur.com/Ix1IbtC.png)     
![](https://i.imgur.com/8GGpiA1.png)      
注： lshw must be run as super user or it will only report partial information.          
类似的，有lscpu:     

	lscpu        

结果：     
![](https://i.imgur.com/7xLq8Pi.png)       
![](https://i.imgur.com/1AaNqkV.png)       

【Ref】  
[1] [Linux查看物理CPU个数、核数、逻辑CPU个数](https://www.cnblogs.com/emanlee/p/3587571.html)      
[2] [查看linux系统的cpu个数线程数量以及型号](https://blog.csdn.net/qq_20641565/article/details/72832273)    
[3] [CPU Info source](https://github.com/clhne/Tools/blob/master/Sys_tools/cpu_info_server.sh)     
[4] [lshw](https://linux.die.net/man/1/lshw)      
[5] [Linux下lshw,lsscsi,lscpu,lsusb,lsblk硬件查看命令](https://www.cnblogs.com/clphp/p/6399119.html)          

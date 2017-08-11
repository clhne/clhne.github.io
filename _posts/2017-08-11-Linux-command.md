---
layout: post
title:  "ln command"
date:   2017-08-11 13：42：00
categories:  Linux
tags: Command
author: CLH
---

* content
{:toc}

# ln 命令 #
ln命令用来为文件创建硬链接和符号链接，默认的链接类型是硬链接；如果要创建符号链接必须使用“-s”选项。      

注：符号链接文件不是一个独立的文件，它的许多属性依赖于源文件，所以以符号链接文件设置存取权限是没有意义的。   

## 语法 ##
ln (选项)(参数)

### 选项 ####
-b或--backup:删除，覆盖目标文件之前的备件；     
-d或-F或--directory:建立目录的硬链接；     
-f或--force:强行建立文件或目录的链接，否认文件或目录是否存在；     
-n或--no-dereferenc:把符号链接的目标目录视为一般文件；    
-s或--symbolic:对源文件建立符号链接；
--help
--version:显示版本信息。     

      
注：硬链接只能引用同一文件系统中的文件，它引用的是文件在文件系统中的物理索引（inode），当移动或删除原始文件时，硬链接不会被破坏，因为它所引用的是文件的物理数据而不是文件在文件结构中的位置，硬链接的文件不需要用户有访问原文件的权限，也不会显示原文件的位置，有助于文件的安全；如果删除的文件有相应的硬链接，那么这个文件依然会保留，直到所有对它的引用都被删除；            
   
符号链接是一个指针，指向文件在文件系统中的位置，符号链接可以跨文件系统，甚至可以指向远程文件系统中的文件，符号链接只是指明了原文件的位置，用户需要对原文件的位置有访问权限才可以使用符号链接；若原文件被删除，所有指向它的符号链接也就都被破坏了，它们会指向文件系统中并不存在的一个位置；两种链接都可以通命令ln来创建，默认创建硬链接，使用-s选项创建符号链接。    
     
符号链接与硬链接的区别？    
硬链接记录的是目标的inode，符号链接记录的是目标的path；硬链接好比是备份，软链接好比是快捷方式，符号链接可以做跨分区的link，符号链接的使用频率要高。

----------

     
附：涛哥演示lc_opencl_demo 
 
	ndk
	echo %path%			//显示环境变量
	ndk-build			//是否安装ndk
	cls					//清屏
	dir					//显示当前目录
	cd ..				//返回上一级目录
	cd ../..			//返回上级目录的上级目录（返回2级目录）
	cd dir				//进入dir目录
	adb devices			//list all connected devices
	adb root			//restarts the adbd daemon with root permissions
	adb shell			//run remote shell interactively
	adb root
	adb remount			//重新挂载文件系统  
  
注：运行adb shell和adb root时提示 “error: more than one device/emulator"时    


- 运行adb devices，如果有多个设备，需要指定设备的序列号：adb -s  *** device shell
- 如果只有一个设备，可能是adb本身的bug，可以运行：adb kill-server，若不行，则运行: taskkill /f /im adb.exe  


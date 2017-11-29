---
layout: post
title:  "ldd command"
date:   2017-11-29 11：17：00
categories:  Linux
tags: Command
author: CLH
---

* content
{:toc}

# ldd 命令 #
List Dynamic Dependencies (ldd)，用来查看程序运行所依赖的共享库，常用来解决程序因缺少某个库文件而不能运行的问题。(ldd prints the shared libraries required by each program or shared library on the command line.)     
帮助：   

	ldd --help    
	man ldd     

Usage:     
	
	ldd  [Option]... File...     

eg;    
![](https://i.imgur.com/gH1bnTP.png)     

第一列：程序所依赖的库；    
第二列：系统提供的与程序需要的库所对应的库；      
第三列：库加载的开始地址。    
ldd命令是依靠设置一些环境变量而实现的，也就是说ldd的作用只是设置一些环境变量的值。       
如：LD_TRACE-LOADED_OBJECTS,只要设置其值非空即可：    

	$ export LD_TRACE-LOADED_OBJECTS=1     
	$ ls /usr

运行结果：      
![](https://i.imgur.com/GIx6mOi.png)     

撤销该环境变量，ls即可恢复正常使用：    

	$ unset LD_TRACE-LOADED_OBJECTS      
	$ ls /usr/          

运行结果如下：     

![](https://i.imgur.com/2kKROwd.png)      

从上可知，ldd默认开启的环境变量是：LD_TRACE-LOADED_OBJECTS=1    


【Ref】    
[1] [ldd命令](https://www.cnblogs.com/wanghetao/p/3779611.html)    
[2] [ldd 查看程序依赖库](http://linuxtools-rst.readthedocs.io/zh_CN/latest/tool/ldd.html)
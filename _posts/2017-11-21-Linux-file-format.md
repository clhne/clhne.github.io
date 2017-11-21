---
layout: post
title:  "Linux file format."
date:   2017-11-21 11:41:00
categories:  Deep_learning_Library
tags: Linux
author: CLH
---

* content
{:toc}

# Linux文件格式问题 #
在Linux环境下编程需要注意到文件的格式问题，例如文件xor_keras.py，若其编码格式为dos，则在Linux环境下执行时会出现如下错误：    

![](https://i.imgur.com/uZA6wmO.png)    
   
即解译错误，找不到文件或路径，这是xor_keras.py的编码格式为dos引起的，可以在vim编辑器通过下面的命令来查询文件的格式：     

	:set ff?   

即此文件的格式为：      
![](https://i.imgur.com/j5C86jI.png) 
    
通过下面的命令将文件的编码格式修改为unix:     

	:set ff=unix      

然后存盘退出即可，再运行xor_keras.py文件：     

	#当file.py文件具有可执行的权限时(x)，同时.py文件包含了Python的路径，如：#!/usr/bin/python2.7
	#此时可以用下面两种方式来执行
	./xor_keras.py
	python xor_keras.py     

运行结果如下：     
![](https://i.imgur.com/e1GUson.png)      

【Ref】  
[1] [执行脚本出现bin/bash: bad interpreter: No such file or directory](http://blog.csdn.net/red10057/article/details/8051650)      
[2] [vim set 功能设定](http://blog.sina.com.cn/s/blog_7ae240850100x7ov.html)     

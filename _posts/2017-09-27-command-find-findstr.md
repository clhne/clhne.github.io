---
layout: post
title:  "find/findstr command"
date:   2017-09-27 13：56：00
categories:  Win_Linux
tags: Command
author: CLH
---

* content
{:toc}

# find 命令 #
Windows和Linux下都有find命令，但是区别较大；Windows下find命令用于文本搜索，而Linux下的find命令用于文件搜索。
### Windows系统下 ###
    
1.在当前目录的”test.txt“文本文件中不区分大小写（/i）查找字符串”abc“，并显示行号（/n）:    

	find /i /n "abc" test.txt	

2.将DOS下的find命令用于查找文件，如不区分大小写，查找并列出当前目录下文件名中含有“open"的所有（包含隐藏文件）（/a）文件，并列出文件所有者（/q）：

	dir /a/q | find /i "open"

3.DOS命令下findstr为find的升级版，但find命令可以统计文本文件中所包含特定字符串的行数，如统计文本文件“test.txt"中所包含的字符串”abc”的行数（/c）：

	find /c "abc" test.txt
4.findstr命令，在当前目录和所有子目录（/s）中查找含有”command“字符串的所有文本文件（*,findstr支持正则表达式）：    

	findstr command *

5.findstr支持正则表达式，而find不支持；find搜索的字符串必须要加英文的双引号，而findstr可加可不加。

----------

### Linux系统下 ###
1.Linux系统下只有find命令，没有findstr命令，在根目录下搜索“data”文件:    

	find . -name data
	or
	find . -maxdepth 1 -name data

2.Linux下的find命令是支持正则表达式的；另外需要注意的是Linux下的find命令是**匹配全路径**，如data文件的全路径是 ./data（一级目录）和./data/rt-polaritydata（二级目录），搜索：  

	find . -maxdepth 1 -iregex .*data
	or
	find . -maxdepth 2 -iregex .*data

3.Linux下的find命令搜索的关键字可加双引号也可不加   
【Ref】    
[1] [Linux新手入门：通过chmod改变文件权限](http://www.letuknowit.com/topics/20120408/change-file-attributes-on-linux.html/)    
[2] [chmod wikipedia](https://zh.wikipedia.org/wiki/Chmod)
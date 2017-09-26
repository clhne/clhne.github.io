---
layout: post
title:  "Install-software-on-your-server-with-the-permission-of-the-current-user"
date:   2017-09-26 10：15：59
categories:  Software-Install
tags: Software
author: CLH
---

* content
{:toc}

# 如何在服务器（Ubuntu 14.04.5 LTS）上以当前用户身份安装软件？ #
公司电脑的服务器大家都在用，大家用户组内往往都是没有root权限的，因此就没有权限安装软件了！然而想要使用一款“个性化”的软件，就需要想办法把软件安装到当前用户下了。    
以非root用户身份安装软件时，当然不能使用“sudo apt-get install”命令安装了；但是可以下载安装包离线安装，以Linux下比较常用的"tree"软件来说明；一般情况下是没有安装这个软件的：    
![](https://i.imgur.com/XB3Negh.jpg)      
可以看到系统没有安装tree    
下载好之后解压：

	tar -xf tree_1.7.0.orig.tar.gz    
	cd tree_1.7.0  
	tree -a > tree.txt    
目录结构如下：        
![](https://i.imgur.com/b6ZYWJI.jpg)      
修改“Makefile”文件中的以下内容：     
![](https://i.imgur.com/oJDeQmE.jpg)          
	
Done！       
安装：       

	make
	make install       
无错误提示后，安装完成：        

	tree --version       
![](https://i.imgur.com/9tVSDs3.jpg)        
Enjoy it!      
	
注：伪终端下清屏命令：       

	clear
	Ctrl + L
	reset   
【Ref】    
[1] [tree_1.7.0.orig.tar.gz](https://launchpad.net/ubuntu/+source/tree/1.7.0-5)    

---
layout: post
title:  "chmod command"
date:   2017-09-1 14：10：00
categories:  Linux
tags: Command
author: CLH
---

* content
{:toc}

# chmod 命令 #
chmod命令用来改变linux文件的权限，通常情况下文件有四种用户类型和六种用户权限：
四种用户类型：   
 
	1. u user 文件所有者    
	2. g group 文件所属组    
	3. o others 其他用户    
	4. a all 所有用户  


----------

	
六种用户权限：    

	1. w write 写   
	2. r read 读
	3. x execute 执行   
	4. X 特殊执行权限，只有当文件为目录文件，或者其他类型的用户有可执行权限时，才将文件权限设置为可执行    
	5. s setuid/gid 当文件被执行时，根据who参数指定的用户类型设置文件的setuid或者setgid权限    
	6. t 粘贴位 设置粘贴位，只有超级用户可以设置该位，只有文件所有者u可以使用该位。   


## 语法 ##
    chmod [options] mode[,mode] file1 [file2 ...]

### mode ####
可为符号模式或者八进制语法，chmod的八进制语法如下：  

    r 4    
	w 2    
	x 1    
	- 0    

      
eg：   
①设置权限：  
  
	chmod u+x filename.sh   为file脚本文件所有者设置可执行权限   

----------

②执行：      
   
	./filename.sh    
	or  bash filename.sh    
	or source filename.sh    
	or . filename.sh

【Ref】    
[1] [Linux新手入门：通过chmod改变文件权限](http://www.letuknowit.com/topics/20120408/change-file-attributes-on-linux.html/)    
[2] [chmod wikipedia](https://zh.wikipedia.org/wiki/Chmod)
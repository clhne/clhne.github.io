---
layout: post
title:  "Linux Command"
date:   2017-08-02 9：34：00
categories:  Linux
tags: Command
author: CLH
---

* content
{:toc}

# sync 命令 #
        
     
sync命令用来强制将内存缓冲区中的数据立即写入磁盘中，并释放该数据对应的buffer，常用来在写磁盘后输入sync命令来将数据真正的写入磁盘。    
##### buffer:为了解决写磁盘的效率 #####
##### cache：为了解决读磁盘的效率 #####

----------

Linux系统为了提高读写磁盘的效率，先将数据放在一块buffer中，在写磁盘时并不是立即将数据写到磁盘中，而是先写入这块buffer中了；此时如果重启系统，就可能造成数据丢失。   
sync命令用来flush文件系统buffer，这样数据才会真正的写入磁盘，buffer才能释放出来，即flush用来清空buffer。    
如果不手动的输入sync命令去真正的写入磁盘，Linux系统也会周期性的去sync数据。	

----------
【Ref】：     
[1] [Linux命令大全](http://man.linuxde.net/sync)  
[2] [Repo命令参考资料](https://source.android.com/source/using-repo?hl=zh-cn)
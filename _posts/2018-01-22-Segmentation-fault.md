---
layout: post
title:  "Segmentation fault"
date:   2018-01-22 16：11：00
categories:  Linux
tags: Programming
author: CLH
---

* content
{:toc}

# 执行程序时遇到段错误的解决方法 #
今天在研究结构体指针时，遇到了段错误：      

![](https://i.imgur.com/rjpBs5e.png)      

![](https://i.imgur.com/bX96Wza.png)     

发现问题是在使用指针时未分配空间而引起的，因此没有分配空间而访问非法的内存：     

	ws = (point *)malloc(sizeof(struct point));    


分配内存后，可以正常运行：     

![](https://i.imgur.com/Lq6WRWc.png)      



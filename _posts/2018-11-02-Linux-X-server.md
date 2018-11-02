---
layout: post
title:  "Linux X server"
date:   2018-11-02 16:55:00
categories:  Linux
tags: X-server
author: CLH
---

* content
{:toc}

# Linuxs X server连不上的解决方法 #

----------
Xshell远程操作服务器出现如果报错：     
: cannot connect to X server      

解决方法：     

	export DISPLAY=:0.0      

【Ref】  
[1] [export DISPLAY=:0.0的解释](https://blog.csdn.net/rivarola/article/details/41041931)      

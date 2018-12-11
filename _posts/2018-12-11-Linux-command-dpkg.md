---
layout: post
title:  "dpkg command"
date:   2018-12-11 15：18：00
categories:  Linux
tags: Command
author: CLH
---

* content
{:toc}

# dpkg 命令 #
“dpkg ”是“Debian Packager ”的简写。为 “Debian” 专门开发的套件管理系统，方便软件的安装、更新及移除。所有源自“Debian”的“Linux ”发行版都使用 “dpkg”，例如 “Ubuntu”、“Knoppix ”等。    
dpkg是Debian软件包管理器的基础，它被伊恩·默多克创建于1993年。dpkg与RPM十分相似，同样被用于安装、卸载和供给.deb软件包相关的信息。        

## 语法 ##

1.Install software. dpkg -i <.deb file name> eg: dpkg -i avg71flm_r28-1_i386.deb      
2.Install all software. eg: dpkg -R /usr/local/src       
3.查看已安装的所有软件： dpkg -l | grep ***    
4.帮助： dpkg -help     
5.显示包的具体信息： dpkg -p package-name eg: dpkg -p cacti        


----------

【Ref】
1.[dpkg百度百科](https://baike.baidu.com/item/dpkg/9944168)     
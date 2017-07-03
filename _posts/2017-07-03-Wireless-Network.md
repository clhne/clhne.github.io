---
layout: post
title:  "Wireless Network"
date:   2017-07-03 18：31：00
categories: Wireless
tags: Wireless
author: CLH
---

* content
{:toc}

# Wireless Network #

## 问题描述： ##
1. 今天无线网络连接出现故障，显示“此计算机已将连接限制为***，有限的访问权限”；
2. 连接上之后又显示“无线网络已连接上，无Internet访问”。

## 解决方案 ##
试了手机仍然可以连上，在电脑上重置winsock目录，在CMD命令提示符中输入以下命令：  
`netsh winsock reset`  
然后重启电脑，在“控制面板”－“管理无线网络”中删除所存在的无线网络，重新输入密码连接。


  
   

----------

注：   
winsock是Windows网络编程接口，它工作在应用层，提供与底层传输协议无关的高层数据传输编程接口，是系统内部目录，netsh winsock reset可将其恢复到默认状态。   
   
`netsh winsock reset`命令可以解决由于软件冲突、病毒原因造成的参数错误问题。netsh命令行可以操作与网络相关设置的接口，比如设置IP，DNS，网卡，无线网络等。

----------
[Ref]：  
[1]. [winsock 百度百科](http://baike.baidu.com/item/netsh%20winsock%20reset)
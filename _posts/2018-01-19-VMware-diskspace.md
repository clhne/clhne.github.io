---
layout: post
title:  "VMware Ubuntu Diskspace Bigger"
date:   2018-01-19 15：35：00
categories:  Linux
tags: VMware
author: CLH
---

* content
{:toc}

# 增加VMware虚拟机Ubuntu磁盘空间大小 #
之前扩容之后没有写总结，现在又发现磁盘空间殆尽，把扩容过程记录下来，方便下次使用！       
### 方法一 ###
利用VMware->虚拟机设置->磁盘->实用工具扩容，无奈我的显示是灰色，应该是VMware Tools没有安装成功：      

![](https://i.imgur.com/CPiE50S.png)

此方法固然简单，但是在我这里不太实用，弃之（之前重装过VMware Tools，没有成功，就没有再管了……）      

### 方法二 ###
只能寻找适合自己情况的方法，先是在网上搜索了各种方法，最终选定如下：      
1.先在虚拟机Ubuntu下安装GParted工具；     
2.关闭VM！在Windows的VM安装目录下执行下面的语句：     


	vmware-vdiskmanager -x “调整后的总空间” D:\ubuntu\ubuntu.vmdk         

虽然这次执行后报错了，但是好像不影响，报错如下：      

![](https://i.imgur.com/OG9aujZ.png)     

3.启动VM，进入Ubuntu系统，打开GParted工具：     

![](https://i.imgur.com/LGSb4dG.png)          


![](https://i.imgur.com/IKj0iqP.png)      

![](https://i.imgur.com/YSkCkCT.png)       

增加了14G！！！

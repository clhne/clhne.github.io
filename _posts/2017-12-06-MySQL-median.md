---
layout: post
title:  "MySQL median"
date:   2017-12-06 15：48：00
categories:  MySQL
tags: median
author: CLH
---

* content
{:toc}

# MySQL Median #
MySQL求中位数。
环境：windows7 32bit，MySQL version:5.7.20.
准备工作：启动MySQL并创建table：               
1.启动MySQL服务：     
	
	net start mysql
	
2.登录mysql：

	mysql -uroot -p  回车输入密码      

3.查看当前所有数据库：    
  
	show databases;

如下：    
   
![](https://i.imgur.com/uvu7DD2.jpg)     

4.创建数据库：      

	create database lcl;    

5.进入数据库：    
	
	use lcl;    

建 table：   

![](https://i.imgur.com/Llcf8vN.jpg)       

插入数据：    

![](https://i.imgur.com/HxAAoPE.jpg)     

①：将数据排序，并给每一行数据给出其在所有数据中的排名：    

![](https://i.imgur.com/PgrCPol.jpg)      

找出中位数的排名数字，但是这种方法只能找到行数为奇数时的中位数：    

![](https://i.imgur.com/Ef4bNVy.jpg)      


无意在stackoverflow上看到了别人优化后的方法：    

![](https://i.imgur.com/1r4PIFO.jpg)      

![](https://i.imgur.com/ToQVnJB.jpg)     

上面只是对一组数据求中位数，如何对多组数据操作呢？    
待优化……    
      
----------
【Ref】：     
[1] [在MySQL中，如何计算一组数据的中位数？](http://www.cnblogs.com/jxlwqq/p/5868206.html)   
[2] [MySQL Calculate Median](http://www.zedwood.com/article/mysql-calculate-median)     
[3] [Simple way to calculate median with MySQL](https://stackoverflow.com/questions/1291152/simple-way-to-calculate-median-with-mysql/7263925#7263925)    
[4] [code](https://github.com/clhne/MySQL-Learning/tree/master/median)
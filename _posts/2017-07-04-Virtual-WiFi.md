---
layout: post
title:  "Virtual WiFI"
date:   2017-07-04 14：55：00
categories: Virtual WiFi
tags: WiFi
author: CLH
---

* content
{:toc}

# Virtual Wifi #
Win7系统自带微软虚拟WiFi迷你适配器（Microsoft Virtual WiFi Miniport Adapter），允许其它网络用户连接此电脑的网络连接，开启方法，在CMD命令提示符下输入： 
  
    netsh wlan set hostednetwork mode=allow ssid=VirtualNetworkName  key=Password		//启用承载网络  
    netsh wlan start hostednetwork														//启用虚拟WiFi承载网络   

	netsh wlan show hostednetwork														//查看所连接的设备     

	netsh wlan stop hostednetwork														//关闭虚拟WiFi承载网络   

	netsh wlan set hostednetwork mode=disallow											//禁用承载网络    






----------
注：查看所电脑所连接过的所有WiFi的用户名和密码：      
   `for /f "skip=9 tokens=1,2 delims=:" %%i in ('netsh wlan show profiles') do @echo %%j | findstr -i -v echo | netsh wlan show profiles %%j key=clear`    
 
	pause	
	
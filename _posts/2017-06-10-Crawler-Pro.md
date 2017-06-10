---
layout: post
title:  "爬虫实例－Spider Pro"
date:   2017-06-10 23:44:10 
categories: Crawler
tags: 爬虫实例 Crawler
author: CLH
---

* content
{:toc}

# Crawler Project #
## 爬虫问题的求解流程： ##
 
![](http://i.imgur.com/FEjiSnf.jpg)

----------

目标：百度百科Python词条相关词条网页-标题和简介 

入口页：http://baike.baidu.com/item/Python 

URL格式：词条页面URL：/item/Python 

数据格式：

1. 标题：`<dd class="lemmaWgt-lemmaTitle-title"><h1>***</h1></dd> `
2. 简介：`<div class="lemma-summary"></div>`

页面编码：UTF-8


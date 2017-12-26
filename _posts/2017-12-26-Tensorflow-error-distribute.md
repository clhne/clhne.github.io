---
layout: post
title:  "Tensorflow-error"
date:   2017-12-26 11：30：00
categories:  Deep_Learning
tags: Tensorflow
author: CLH
---

* content
{:toc}

# Tensorflow import error#
今天在Ubuntu14.04下运行Tensorflow时报出以下错误：    

![](https://i.imgur.com/LhEk57L.png)    

通过一番搜索，发现是distribute包的问题，原来的distribute版本是0.6.3，更新为0.7.3后问题解决：     

![](https://i.imgur.com/vvYkWIP.png)      

搞了将近一上午！


【Ref】    
[1] [Exception: Versioning for this project requires either an sdist tarball，问题解决方法](http://blog.csdn.net/wuruiaoxue/article/details/78891935)    

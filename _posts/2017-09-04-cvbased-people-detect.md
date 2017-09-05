---
layout: post
title:  "cvbased people detect"
date:   2017-09-04 10：11：00
categories:  People_detect
tags: Algorithm
author: CLH
---

* content
{:toc}

# 基于OpenCV的行人检测 #
研究OpenCV2.4.2/samples/cpp/peopledetect.cpp项目，分别在VS2015+OpenCV3.2和Linux（Ubuntu）环境下测试，最终都运行成功了；测试过程中遇到的问题及解决方法整理如下：   
1. 提示“Error on line 2648 (ocl.cpp): svmCapabilities is empty.”，这里可以理解为warning, svmInitialized = true；不影响检测结果；  
2. VS2012 + OpenCV3.2环境下运行出错，在VS2015下正常运行，应该是OpenCV3.2和VS版本兼容性问题；   
3. Linux下是在服务器（Ubuntu）下进行测试的，首先要配置OpenCV环境，然后链接，编译，运行程序，用到的知识有CMake, Makefile, Vim, bash等；由于服务器没有图形界面，只能将检测的结果写入另一幅图像，然后查看检测结果图。


注：OpenCV遇到图像无法imshow时，可以将结果用imwrite写入另一张图片，然后进行查看。加强Linux下bash命令练习，HOG+SVM行人检测算法。   
    
【Ref】    
[1] [OpenCV2.0 peopledetect 学习体会](http://www.opencv.org.cn/forum.php?mod=viewthread&tid=9146&extra=&page=1)    
[2] [peopledetect 行人检测_windows](https://github.com/clhne/cvbased_peopledetect)   
[3] [行人检测(Pedestrian Detection)资源](http://blog.csdn.net/alada007/article/details/8088868)
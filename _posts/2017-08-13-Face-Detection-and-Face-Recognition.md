---
layout: post
title:  "Face Detection and Face Recognition"
date:   2017-08-13 15：35：00
categories:  Face_Recognition
tags: Algorithm
author: CLH
---

* content
{:toc}

# Face Detection and Face Recognition#
人脸检测（Face Detection)是定位图像中人脸的过程，主要任务是检测人脸，不关心是谁的人脸；     
人脸识别（Face Recognition)是对已知人脸进行分类，比如看到一张人脸能判断出是否是他/她是否为自己的朋友，人脸识别通常包括以下步骤：   
1. 人脸检测：定位图像中人脸的过程，根据眼睛、眉毛、鼻子等器官的特征以及相互之间的几何位置关系来检测人脸，即在一幅图像或一系列图像（如视频）中判断是否有人脸，若有则返回人脸的大小、位置等信息；  
2. 人脸预处理：调整人脸图像，使其看起来更加清楚，比如早期阶段的灰度校正、去噪等；人脸图像预处理主要包括人脸对准、人脸图像增强以及归一化等：人脸对准是为了得到人脸位置端正的人脸图像；人脸图像增强是为了改善人脸图像的质量，不仅在视觉上更加清晰，而且使图像更利于计算机的处理与识别；归一化是为了使得人脸图像尺寸一致，灰度取值范围相同的标准化人脸图像；    
3. 人脸图像特征提取：对人脸图像进行特征建模；   
4. 人脸图像匹配与识别：将待识别的人脸特征与已得到的人脸的特征模板进行比较，根据相似度对人脸的身份信息进行判断，分为两类：一是人脸确认，是一对一图像比较，根据相似度阈值判断是否为同一个人；二是人脸辨认，是一对多图像对比，将特定的人脸与数据库中的多张人脸进行对比，根据对比结果鉴定此人的身份，或找到其中最相似的人脸，按照相似程度的大小输出检测结果；乌镇互联网大会中的刷脸注册系统，百度大厦的闸机，人停留1s到2s就可以通过，就是1：N的人脸识别。
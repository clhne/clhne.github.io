---
layout: post
title:  "Dark Image Enhancement"
date:   2017-12-08 10：11：00
categories:  Computer_Vision
tags: CV
author: CLH
---

* content
{:toc}

# 暗光增强 #

部分双摄手机支持夜间拍照的暗光增强技术，如华为P9的“超级夜景”模式，暗光增强涉及到图像配准和图像融合，最近整理该算法，在此做下总结。     
图像配准和融合的方法主要分为三种：   
1.基于像素的配准，特点计算量小，用于初步配准；    
2.基于特征的配准，特点计算量大，先进行特征提取，如SIFT、SURF等；定位准确；    
3.基于模型的配准，用于精细配准。    

      
----------
【Ref】：     
[1] [Darkness Lighting](https://www.sensetime.com/edit/#Darkness lighting)      
[2] [图像融合中的图像配准方法研究](http://nysrsp.cqvip.com/bitstream/123456789/1213794/1/%E5%9B%BE%E5%83%8F%E8%9E%8D%E5%90%88%E4%B8%AD%E7%9A%84%E5%9B%BE%E5%83%8F%E9%85%8D%E5%87%86%E6%96%B9%E6%B3%95%E7%A0%94%E7%A9%B6)    
[3] [OpenCV探索之路（二十四）图像拼接和图像融合技术](https://www.cnblogs.com/skyfsm/p/7411961.html)      
[4] [图像金字塔](http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/pyramids/pyramids.html)      
[5] [OpenCV图像金字塔：高斯金字塔、拉普拉斯金字塔与图片尺寸缩放](http://blog.csdn.net/poem_qianmo/article/details/26157633)     
[6] [SURF算法与源码分析、上](https://www.cnblogs.com/ronny/p/4045979.html)

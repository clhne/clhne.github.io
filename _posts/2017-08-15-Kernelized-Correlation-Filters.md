---
layout: post
title:  "Kernelized Correlation Filters"
date:   2017-08-15 9：09：00
categories:  Computer_Vision
tags: Machine_Learning
author: CLH
---

* content
{:toc}

# Kernelized Correlation Filters(KCF) #
核相关滤波（Kernelized Correlation Filters, KCF) 是一个高速目标跟踪算法，目前存在的目标跟踪系统其核心组成是一个判别分类器，主要思想是通过给出的样本训练一个判别分类器，判别跟踪到的是目标还是背景，KCF目标跟踪算法利用循环行列式/矩阵（circulant matrices）表示图像块，对样本进行采集，用快速傅里叶变换对算法进行加速计算。        
  
相关滤波(Correlation Filter, CF)是对[MOSSE算法](http://www.cs.colostate.edu/~vision/publications/bolme_cvpr10.pdf)的改进，是后来CSK、STC、Color Attributes等Trackers的鼻祖，CF源于信号处理，后被用于图像分类；CF用于Tracking的思想是：两个信号越相似，其相关值越高；通过滤波模板，当作用于跟踪目标时，得到的响应最大，最大响应值的位置就是目标的位置([参考](http://www.cnblogs.com/hanhuili/p/4266990.html))。    
     
[CSK](http://www.robots.ox.ac.uk/~joao/publications/henriques_eccv2012.pdf)是CF算法改进的初级版本，[KCF](https://arxiv.org/pdf/1404.7584.pdf)是对CSK进一步的改进。将只能用单通道的灰度特征改进为可以使用多通道的HOG特征，使用核函数计算偶相关滤波。   

运行环境：VS2015 + OpenCV3.2.0_withsource，首先配置环境变量：   
1. “项目属性页”->“VC++目录”->“包含目录”，添加三个库目录：D:\opencv-3.2.0_withsource\build\install\include、D:\opencv-3.2.0_withsource\build\install\include\opencv、D:\opencv-3.2.0_withsource\build\install\include\opencv2；      
2. “项目属性”->“VC++目录”->"库目录“，添加库目录：D:\opencv-3.2.0_withsource\build\install\x86\vc14\lib；    
3. “调试”->“命令参数”中输入要跟踪视频的文件名；      
4. “链接器”->“输入”—>“附加依赖项”，添加依赖项: opencv_world320.lib(Release版本）或opencv_world320d.lib(debug版本）     
报错   
1>------ 已启动生成: 项目: KCF _VS2015, 配置: Debug Win32 ------   
1>main.obj : error LNK2019: 无法解析的外部符号 "public: bool __thiscall cv::Tracker::init(class cv::Mat const &,class cv::Rect_<double> const &)" (?init@Tracker@cv@@QAE_NABVMat@2@ABV?$Rect_@N@2@@Z)，该符号在函数 _main 中被引用      
1>main.obj : error LNK2019: 无法解析的外部符号 "public: bool __thiscall cv::Tracker::update(class cv::Mat const &,class cv::Rect_<double> &)" (?update@Tracker@cv@@QAE_NABVMat@2@AAV?$Rect_@N@2@@Z)，该符号在函数 _main 中被引用    
1>main.obj : error LNK2019: 无法解析的外部符号 "public: static struct cv::Ptr<class cv::Tracker> __cdecl cv::Tracker::create(class cv::String const &)" (?create@Tracker@cv@@SA?AU?$Ptr@VTracker@cv@@@2@ABVString@2@@Z)，该符号在函数 _main 中被引用    
1>E:\opencv project\KCF _VS2015\Debug\KCF _VS2015.exe : fatal error LNK1120: 3 个无法解析的外部命令   
========== 生成: 成功 0 个，失败 1 个，最新 0 个，跳过 0 个 ==========

解决方法：“链接器”->“输入”—>“附加依赖项”，添加依赖项: opencv_tracking320d.lib     
 
注：常用按键的ASCII码：   
Esc ： 27  
Enter ： 13     
Ctrl + Enter : 10     
空格 ： 32   
显示视频时，一般用cvWaitKey(delay)delay是延迟的ms数，表示显示一帧，然后等待delay ms,再显示下一帧，如果没有cvWaitKey()的话，循环里面的每个指令执行的时间为0.0000000001s，趋于0；如果capture有10000帧图像，那么只需要0.000001s就播放完了，几乎看不到画面。    
显示图像时，一般在cvShowImage()函数后加一个cvWaitKey(0),显示图像后将暂停，等待接收一个键盘输入；没有这条语句的话，显示图像的代码很快就执行完了，看不到输出的图像。
     
【Ref】:     
[1] [High-speed tracking with kernelized 
correlation filters.Pattern Analysis and Machine Intelligence, IEEE 
Transactions on 37.3 (2015): 583-596.](https://arxiv.org/pdf/1404.7584.pdf)    
[2] [目标跟踪-KCF高速跟踪详解](http://blog.csdn.net/shenxiaolu1984/article/details/50905283)     
[3] [Kernelized Correlation Filters](http://www.robots.ox.ac.uk/~joao/circulant/)       
[4] [Exploiting the Circulant Structure of Tracking-by-detection with Kernels](http://www.robots.ox.ac.uk/~joao/publications/henriques_eccv2012.pdf)        
[5] [Visual Object Tracking using Adaptive Correlation Filters](http://www.cs.colostate.edu/~vision/publications/bolme_cvpr10.pdf)     
[6] [GitHub_opencv_contrib](https://github.com/opencv/opencv_contrib/tree/master/modules/tracking)
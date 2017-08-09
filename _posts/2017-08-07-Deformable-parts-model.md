---
layout: post
title:  "Deformable Parts Model"
date:   2017-08-07 17：23：00
categories:  Face Detection and Alignment
tags: Algorithm
author: CLH
---

* content
{:toc}

# Deformable Parts Model#
DPM是一个比较成功的目标检测算法，被应用到姿态估计、人脸识别、表情识别和场景分类等问题；是HOG(Histogram Orientd Gradients)的改进版本。HOG的计算方法如下：   

1. 预处理，早期的行人检测HOG特征描述符处理的图像大小是64×128，因此需要将原始图像调整为64×128大小：    
![](http://i.imgur.com/g01hmvI.jpg)

2. 计算梯度图像，首先计算水平和垂直梯度，可以通过下面的kernels对图像滤波实现：     
![](http://i.imgur.com/xeEeA07.jpg)  
也可以通过OpenCV中的Sobel算子来实现:   
                     
     
    //C++ Gradient calculation    
	//Read image    
    Mat img = imread("xxx.jpg");   
	img.convertTo(img,CV_32F,1/255.0)        
 

[source code](https://github.com/clhne/clhne.github.io/tree/master/src/vecadd)   

----------
【Ref】：     
[1] [Object Detection with Discriminatively Trained
Part Based Models](https://cs.brown.edu/~pff/papers/lsvm-pami.pdf)  
[2] [Cascade Object Detection with Deformable Part Models∗](https://cs.brown.edu/~pff/papers/cascade.pdf)   
[3] [source code](http://www.rossgirshick.info/latent/)      
[4] [The representation and matching of pictorial structures](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.118.7951&rep=rep1&type=pdf)      
[5] [Image Recognition and Object Detection : Part 1](https://www.learnopencv.com/image-recognition-and-object-detection-part1/)
	
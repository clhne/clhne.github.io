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

----------

    //C++ Gradient calculation

    //Read image        
    Mat img = imread("xxx.jpg"); 
	img.convertTo(img, CV_32F, 1/255.0);
     
	//Calculate gradients gx, gy
	Mat gx,gy;
	Sobel(img, gx, CV_32F, 1, 0, 1);
	Soble(img, gy, CV_32F, 1, 0, 1);    


然后，计算梯度的幅度的方向：  
![](http://i.imgur.com/fe5k1Zl.jpg)
同样也可以利用OpenCV自带的cartToPolar函数：

----------
	Mat mag, angle;
	cartToPolar(gx, gy, mag, angle, 1);
   
梯度图像示意图：
![](http://i.imgur.com/dZ3bFOY.jpg)   
梯度图像去除了大量的不必要的信息，突出了图像的轮廓    
3. 计算8×8cells的梯度直方图   
首先将图像分成8×8大小的图像块，并计算每个图像块的梯度直方图； 
![](http://i.imgur.com/vBgCe52.jpg)     
为什么将图像分成大小为8×8的图像块？这是为了利用特征描述符对图像块进行压缩表示，一个8×8图像块包含8×8×3=192个像素值，图像块的每个像素的梯度又包含2个值（幅度和方向），总共8×8×2=128numbers；图像块表示法对噪声具有更强的鲁棒性。    
为什么是8×8，不是32×32？因为HOG最初用于行人检测，行人图像的8×8图像块扩展到64×128后就足以捕捉感兴趣的特征（如人脸，头顶等）。    
梯度直方图实质上是一个9bin的向量/数组，对应角度0，20，40，60，...，160。    


注：直方图中bin的含义，颜色直方图将颜色空间划分成若干小的颜色区间，即直方图的bin，通过计算颜色在每个小敬意内的像素得到颜色直方图，bin越多，直方图对颜色的分辨率越强，但增加了计算机的负担；下图所分的5个竖条区域，每个竖条区域称为一个bin。      
![](http://i.imgur.com/goPB5kl.jpg)        


8×8图像块和梯度如下图：    
![](http://i.imgur.com/BZ6cpGm.png)     

Center: The RGB patch and gradients reprented using arrows.    
Right:  The gradients in the same patch represented as numbers.  

梯度直方图的图解如下：   
![](http://i.imgur.com/VOSkq60.png)     

注：如果角度大于160，即在160~180之间，由于0和180是等价的，因此角度为165的像素按比例分配给0bin和160bin（距离0bin为15，距离160为5，分配为1：3）    
![](http://i.imgur.com/Uc8iC0W.png)      

8×8cells中所有像素的贡献叠加，最终形成了9bin的直方图，对上面的图像块，直方图类似下图：     
![](http://i.imgur.com/gRXwTf6.png)
4. 16×16 Block 标准化   
标准化可以消除比例的影响，从而对亮度更具鲁棒性；比如v1=[3, 4]，向量的长度为5（L2 norm，2范数），标准化后为v1'= [0.6, 0.8]；v2 = 2*v1 = [6, 8]，标准化后也是v2'= [0.6, 0.8]。

![](http://i.imgur.com/QSKpqkn.gif)



----------

[source code](https://github.com/clhne/clhne.github.io/tree/master/src/vecadd)   

【Ref】：     
[1] [Object Detection with Discriminatively Trained
Part Based Models](https://cs.brown.edu/~pff/papers/lsvm-pami.pdf)  
[2] [Cascade Object Detection with Deformable Part Models∗](https://cs.brown.edu/~pff/papers/cascade.pdf)   
[3] [source code](http://www.rossgirshick.info/latent/)      
[4] [The representation and matching of pictorial structures](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.118.7951&rep=rep1&type=pdf)      
[5] [Image Recognition and Object Detection : Part 1](https://www.learnopencv.com/image-recognition-and-object-detection-part1/)
	
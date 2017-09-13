---
layout: post
title:  "Convolution Neural Network"
date:   2017-08-14 9：09：00
categories:  Computer_Vision
tags: Machine_Learning
author: CLH
---

* content
{:toc}

# Convolution Neural Network#
Convolution Neural Network(CNN,卷积神经网络）广泛应用于计算机视觉领域，如图像分类、人脸识别等；CNN是一种前馈神经网络，是深度学习中极具代表的网络结构之一，ImageNet数据集上许多成功的模型都是基于CNN的；与传统的图像处理算法相比，CNN的优点是避免了对图像复杂的前期预处理过程（提取人工特征等），它可以直接输入原始图像。CNN采用局部连接、权值共享等方法减少训练参数和训练时间。    
经典的CNN结构为LeNet-5网络，结构如下：      

![](https://i.imgur.com/cgLi85X.png)     

CNN主要有两种类型的网络层，即卷积层和池化/采样层（Pooling），卷积层的作用是提取图像的各种特征；池化层的作用是对原始特征信号进行抽象，大幅度减少训练参数，减轻模型过拟合的程度。    
## 卷积层  ##
卷积过程如下：     
![](https://i.imgur.com/z2cuaVu.png)     

![](https://i.imgur.com/oQrecXW.gif)     
# 池化/采样层 ##
卷积层获取图像特征后，理论上可以用这些特征训练分类器，但计算量比较大，容易产生过拟合现象；为了降低网络训练参数及模型的过拟合程度，对卷积层进行池化/采样（Pooling）处理，有两种方式：

- Max-Pooling:选择Pooling窗口中的最大值作为采样值；
- Mean-Pooling:选择Pooling窗口中的平均值作为采样值。
     
如下图所示：     
![](https://i.imgur.com/2SogSQG.png)     

## 经典的CNN模型：LeNet-5 ##
![](https://i.imgur.com/nS11KcL.png)    
![](https://i.imgur.com/GiCcBnb.png)    
![](https://i.imgur.com/F4xfoTJ.png)    
![](https://i.imgur.com/zqs4Ztz.png)    
![](https://i.imgur.com/Q140oTj.png)    
![](https://i.imgur.com/OkBnNyA.png)     
![](https://i.imgur.com/mVjAIuU.png)

**LeNet-5在MNIST数据集上的结果：**   
![](https://i.imgur.com/leYCwcI.png)

----------

【Ref】:     
[1] [Joint Face Detection and Alignment using Multi-task Cascaded Convolutional Networks.](https://arxiv.org/ftp/arxiv/papers/1604/1604.02878.pdf)   
[2] [卷积神经网络(CNN)学习笔记1：基础入门](http://www.jeyzhang.com/cnn-learning-notes-1.html)
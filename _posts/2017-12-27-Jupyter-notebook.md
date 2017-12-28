---
layout: post
title:  "Jupyter-notebook"
date:   2017-12-27 15:42:00 
categories: Python
tags: Jupyter_notebook ipython_notebook
author: CLH
---

* content
{:toc}

# Jupyter Notebook #

----------
Jupyter Notebook(早期的IPython notebook）是一个交互式笔记本，支持运行40多种编程语言。本质为一个Web应用程序，便于创建和共享程序文档，支持实时代码，数学方程，可视化和markdown。用于：数据清理和转换、数值模拟、统计建模、机器学习等。数据挖掘领域最热门的比赛Kaggle里的资料都是Jupyter格式。    
今天在学习Tensorflow-cookbook时有.ipynb的说明文档，要乃至Jupyter notebook，因此有必要安装此工具，在此总结下安装过程中遇到的问题。           

## 安装方法一 ##
官网推荐的安装方式是最简单的，对于新手比较方便。        

![Jupyter notebook推荐安装方式](https://i.imgur.com/DUEBYfS.jpg)     

我的机子上同时安装了Anaconda2（Python2.7.14）和Anaconda3（Python3.6.1），在Anaconda的终端下运行下面的指令即可启动Jupyter notebook:     

	Jupyter notebook   

![windows下Jupyter notebook启动页面](https://i.imgur.com/hAETvYj.jpg)    

![windows下Jupyter启动后Web页面](https://imgur.com/glztwO3)     

## 安装方法二 ##
官网推荐的第二种方法，即Python和IPython用户可选择的方法：    

![Alternative for experienced Python users: Installing Jupyter with pip](https://i.imgur.com/4v19lCJ.jpg)     

## Ubuntu14.04 Python2.7.6下安装 ##
发现安装Jupyter notebook启动不了：    

![](https://i.imgur.com/5YHMrF5.jpg)    

发现通过下面的命令：    

	ipython notebook    

可以正常启动：      

![](https://i.imgur.com/3TRx0ym.jpg)     

可见Jupyter早期是存在IPython 中的。启动起来后的Web页面：     
 
![](https://i.imgur.com/sIm5kIu.jpg)      

End...  

----------

Ref：    
[1] [Installing Jupyter Notebook](https://jupyter.readthedocs.io/en/latest/install.html)    
[2] [install Jupyter for Python 2.7 in Ubuntu 14.04](https://askubuntu.com/questions/847263/install-jupyter-for-python-2-7-in-ubuntu-14-04)    
[3] [ipython notebook 如何打开.ipynb文件？](https://www.zhihu.com/question/45498930/answer/110452414)    
[4] [Jupyter Notebook快速入门](https://www.cnblogs.com/nxld/p/6566380.html)     
[5] [The Home of Data Science & Machine Learning](https://www.kaggle.com/)
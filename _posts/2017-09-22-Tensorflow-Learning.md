---
layout: post
title:  "Tensorflow-Learning"
date:   2017-09-22 09：30：00
categories:  Deep-Learning
tags: Tensorflow
author: CLH
---

* content
{:toc}

# Tensorflow #
## Introduction ##
Tensorflow是一个使用数据流图进行数值计算的**开源软件库**(An open-source software library for Machine Learning)，图的节点代表数学运算，边代表节点间传递的多维数组（张量）。最初由Google机器智能研究部门的Google Brain团队中的研究人员和工程师开发，用于机器学习和深度神经网络研究；它是一个基础的系统，可用于众多领域。 深度学习开源框架在GitHub上的统计：    
![](https://i.imgur.com/AnNFTOQ.jpg)    
## Installing ##
详细安装过程可参考官方安装说明。注意：离线（或公司内网）情况下可选择安装各种依赖包完成Tensorflow的安装，过程比较麻烦，最好是在Linux下进行安装，因为Tensorflow是基于Python的，windows下可能会遇到各种报错；Python的安装路径中最好不要有中文，否则可能会遇到GBK和UTF-8编码兼容性问题。    
安装完成之后运行./tensorflow/bin/activate激活环境，测试程序：    

	'''
	HelloWorld example using Tensorflow library.   
	Author : Chenglin L.   
		
	import subprocess
	import tensorflow as tf 
	import os
		
	hello = tf.constant('Hello, Tensorflow!')
	sess = tf.Session()
	sess.run(hello)
	a = tf.constant(10)
	b = tf.constant(32)
	sess.run(a + b)
	
	sess.close()

    
输出：    
Hello, Tensorflow!   
42    
## Get Started with Tensorflow ##
Tensorflow用计算图（Computational Graphs）的方式建立网络。    
### 构造阶段（Construction phase）:组装计算图（管道） ###
组装计算图（类比管道）：    

- 计算图（graph）由许多操作组成。
- 操作（ops）接受零个或多个输入，返回零个或多个输出。
- 数据类型，有为张量（tensor）、变量（variable）和常量（constant）   

##### 数据类型 #####
**张量**：多维array或list（管道中的液体），创建语句：    

    tensor_name=tf.placeholder(type, shape, name)   
**变量**：同一时刻对图中所有其他操作都保持静态的数据（管道中的阀门），创建语句：     
	
	name_variable = tf.Variable(value, name)    
初始化语句：    

	#个别变量
	init_op=variable.initializer()
	#所有变量
	init_op=tf.initialize_all_variables()
	#注意：init_op的类型是操作（ops），加载之前并不执行    
更新语句：   

	update_op=tf.assign(variable to be updated, new_value)    

**常量**：无需初始化的变量，创建语句：    

	name_constant=tf.constant(value)

### 执行阶段（Execution phase）：使用计算图（获取液体） ###
**会话**：执行构建的计算图。可执行设备：单个电脑的CPU、GPU，或电脑分布式甚至手机；创建语句：    

	#常规
	sess = tf.Session()
	#交互
	sess = tf.InteractiveSession()
	#交互方式可用tensor.eval()获取值，ops.run()执行操作
	#关闭
	sess.close()    
**执行**：    

	sess.run(op)


【Ref】    
[1] [Tensorflow官网](https://www.tensorflow.org/)    
[2] [Tensorflow安装](https://www.tensorflow.org/install/)      
[3] [Hello Tensorflow](https://github.com/clhne/Tensorflow-projects/tree/master/Tensorflow-Examples/examples)    
[4] [Get Started with Tensorflow](https://www.tensorflow.org/get_started/get_started)    
[5] [干货|Tensorflow的55个经典案例](https://zhuanlan.zhihu.com/p/27577246)    
[6] [如何高效的学习 TensorFlow 代码?](https://www.zhihu.com/question/41667903)     
[7] [Tensorflow Example](https://github.com/aymericdamien/TensorFlow-Examples)     
[8] [YJango的TensorFlow整体把握](https://zhuanlan.zhihu.com/p/23932714)     
[9] [TFLearn](http://tflearn.org/)     
[10] [TensorFlow和Caffe、MXNet、Keras等其他深度学习框架的对比](https://www.leiphone.com/news/201702/T5e31Y2ZpeG1ZtaN.html)
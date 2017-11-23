---
layout: post
title:  "Keras First Network."
date:   2017-11-23 9：10:00
categories:  Deep_learning_Library
tags: Keras
author: CLH
---

* content
{:toc}

# 基于Keras的神经网络构建 #
Keras构建神经网络的步骤如下：     


1. Load Data.
2. Define Model
3. Compile Model
4. Fit Model
5. Evaluate Model
6. Tie it all together    


代码如下：    

	import time
	from keras.models import Sequential
	from keras.layers import Dense
	import numpy
	start = time.time()
	# fix random seed for reproducibility
	numpy.random.seed(7)
	#load pima indians dataset
	dataset = numpy.loadtxt("pima-indians-diabetes.csv",delimiter=",")
	#split into input(x) output(y) variables
	x = dataset[:,0:8]
	y = dataset[:,8]
	#create model
	model = Sequential()
	model.add(Dense(12,input_dim=8,activation='relu'))
	model.add(Dense(8,activation='relu'))
	model.add(Dense(1,activation='sigmoid'))
	#compile model
	model.compile(loss='binary_crossentropy',optimizer='adam',metrics=['accuracy'])
	#fit the model
	model.fit(x,y,epochs=150,batch_size=10)
	#evaluate the model
	scores = model.evaluate(x,y)
	print("\n%s: %.2f%%" %(model.metrics_names[1],scores[1]*100))
	end = time.time()
	print 'Run time: '
	print end - start     

运行结果：    
![](https://i.imgur.com/FCMlu52.png)

【Ref】  
[1] [Develop Your First Neural Network in Python With Keras Step-By-Step](https://machinelearningmastery.com/tutorial-first-neural-network-python-keras/)      
[2] [Keras常用层](http://keras-cn.readthedocs.io/en/latest/layers/core_layer/)     

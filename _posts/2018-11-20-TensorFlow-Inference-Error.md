---
layout: post
title:  "TensorFlow Inference Error"
date:   2018-11-20 17:05:00
categories:  Computer_Vision
tags: TensorFlow
author: CLH
---

* content
{:toc}

# TensorFlow Inference Error #
When run Tensorflow_Inference.ipynb in ipython, an error occurred:      
> ValueError: Variable resnet_v1_50/conv1/weights already exists, disallowed. Did you mean to set reuse=True or reuse=tf.AUTO_REUSE in VarScope? Originally defined at:

  >File "/home/lc/lcl/py3/lib/python3.6/site-packages/tensorflow/contrib/framework/python/ops/variables.py", line 277, in variable
    aggregation=aggregation)
  File "/home/lc/lcl/py3/lib/python3.6/site-packages/tensorflow/contrib/framework/python/ops/arg_scope.py", line 182, in func_with_args
    return func(*args, **current_args)
  File "/home/lc/lcl/py3/lib/python3.6/site-packages/tensorflow/contrib/framework/python/ops/variables.py", line 350, in model_variable
    aggregation=aggregation)      
Solution:     
Insert the following code at the beginning of the block.    
	tf.reset_default_graph()     

![](https://i.imgur.com/ZUuXSOk.jpg)         
     
### Ref ###
[1] [DeepLearningFrameworks](https://github.com/ilkarman/DeepLearningFrameworks/blob/master/notebooks/Tensorflow_Inference.ipynb)    
[2] [TensorFlow-Slim image classification model library](https://github.com/tensorflow/models/tree/master/research/slim)     
[3] [Error in notebook: "ValueError: Variable conv1/weights already exists, disallowed. Did you mean to set reuse=True in VarScope" #8](https://github.com/kratzert/finetune_alexnet_with_tensorflow/issues/8)           
[4] [code](https://github.com/clhne/colab_demo)  
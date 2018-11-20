---
layout: post
title:  "TensorFlow Inference Error"
date:   2018-11-20 17:05:00
categories:  Deep_learning
tags: TensorFlow
author: CLH
---

* content
{:toc}

# TensorFlow Inference Error #
When run Tensorflow_Inference.ipynb in ipython, an error occurred:      
> ValueError: Variable resnet_v1_50/conv1/weights already exists, disallowed. Did you mean to set reuse=True or reuse=tf.AUTO_REUSE in VarScope? Originally defined at:    
File "/home/lc/lcl/py3/lib/python3.6/site-packages/tensorflow/contrib/framework/python/ops/variables.py", line 277, in variable
    aggregation=aggregation)   
File "/home/lc/lcl/py3/lib/python3.6/site-packages/tensorflow/contrib/framework/python/ops/arg_scope.py", line 182, in func_with_args    
    return func(*args, **current_args)    
File "/home/lc/lcl/py3/lib/python3.6/site-packages/tensorflow/contrib/framework/python/ops/variables.py", line 350, in model_variable     
    aggregation=aggregation)      
  
Solution:      
Insert the following code at the beginning of the block.   
 
	tf.reset_default_graph() # To clear the default graph 重置当前的张量图，即清空所有的张量，在ipython中run jupyter notebook代码时，需要重置张量图，否则会报错        

![](https://i.imgur.com/ZUuXSOk.jpg)         
     
注：在training的时候，如果是在ipython中运行jupyter notebook，提示如下错误：     

>ValueError: Variable output/kernel already exists, disallowed. Did you mean to set reuse=True or reuse=tf.AUTO_REUSE in VarScope? Originally defined at:    
File "<ipython-input-87-b55ee4064880>", line 24, in create_symbol
    logits = tf.layers.dense(drop3, n_classes, name='output')     
File "<timed exec>", line 8, in <module>     
File "/home/lc/lcl/py3/lib/python3.6/site-packages/IPython/core/magics/execution.py", line 1238, in time     
    exec(code, glob, local_ns)      

同样需要加上述代码。    

### Ref ###
[1] [DeepLearningFrameworks](https://github.com/ilkarman/DeepLearningFrameworks/blob/master/notebooks/Tensorflow_Inference.ipynb)    
[2] [TensorFlow-Slim image classification model library](https://github.com/tensorflow/models/tree/master/research/slim)     
[3] [Error in notebook: "ValueError: Variable conv1/weights already exists, disallowed. Did you mean to set reuse=True in VarScope" #8](https://github.com/kratzert/finetune_alexnet_with_tensorflow/issues/8)       
[4] [TF API r1.12](https://www.tensorflow.org/api_docs/python/tf/reset_default_graph)
[5] [Remove nodes from graph or reset entire default graph](https://stackoverflow.com/questions/33765336/remove-nodes-from-graph-or-reset-entire-default-graph)     
       
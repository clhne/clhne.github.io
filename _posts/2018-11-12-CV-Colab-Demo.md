---
layout: post
title:  "Google Colab Demo"
date:   2018-11-12 12:47:00
categories:  Computer_Vision
tags: CV
author: CLH
---

* content
{:toc}

# Google Colab Demo #
About: Google Colab, Google’s free cloud service for AI developers. With Colab, you can develop deep learning applications on the GPU for free.    
## Colab info ##
	import tensorflow as tf
	import keras as ks
	from tensorflow.python.client import device_lib
	print('TensorFlow version:',tf.__version__)
	print('TensorFlow path:',tf.__file__)
	print('keras version:',ks.__version__)
	print('keras path:',ks.__file__)
	print
	#!ls ../../
	#!cat /proc/cpuinfo
	#!cat /proc/meminfo
	print('--------------meminfo---------------------')
	!free -mh
	print('------------------------------------------')
	print('--------------disinfo---------------------')
	!df -lh
	print('------------------------------------------')
	#!uname -a
	print('--------------sysinfo---------------------')
	!lsb_release -a
	print('------------------------------------------')
	
	print('--------------GPUinfo---------------------')
	!nvidia-smi
	device_lib.list_local_devices()
	print('------------------------------------------')
	
	print('--------Is GPU Working?-------------------')
	print(tf.test.is_gpu_available(cuda_only=False,min_cuda_compute_capability=None))
	print(tf.test.gpu_device_name())
	print('------------------------------------------')   

#### neofetch info ####

	#ipython
	!apt-get install neofetch
	neofetch    
![](https://i.imgur.com/p0o3EOX.jpg)      


Result:     
![](https://i.imgur.com/EpgJ6qv.jpg)     



### Ref ###
[1] [Google Colab Free GPU Tutorial](https://medium.com/deep-learning-turkey/google-colab-free-gpu-tutorial-e113627b9f5d)    
[2] [Training and serving a realtime mobile object detector in 30 minutes with Cloud TPUs](https://medium.com/tensorflow/training-and-serving-a-realtime-mobile-object-detector-in-30-minutes-with-cloud-tpus-b78971cf1193)     
[3] [Google Colab 免费GPU服务器使用教程](https://blog.csdn.net/cocoaqin/article/details/79184540)     

   
[3] [code](https://github.com/clhne/colab_demo)  
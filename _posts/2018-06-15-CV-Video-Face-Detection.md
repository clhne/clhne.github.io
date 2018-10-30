---
layout: post
title:  "Face Detection of Video"
date:   2018-10-30 15:20:00
categories:  Computer_Vision
tags: CV
author: CLH
---

* content
{:toc}

# A mobilenet SSD Face Detection of Video #

----------
A mobilenet SSD(single shot multibox detector) based face detector with pretrained model provided, powered by tensorflow object detection api, trained by WIDERFACE dataset.     
       		  
## Features ##
Robust, adapt to different poses, this feature is credit to WIDERFACE dataset, I manually cleaned the dataset to balance the precision and recall trade off.     

Parallel, multiple process video processing, can inference multiple input simultaneously, I tested to process 4 videos on a single GPU card at the same time, the speed is still competitive, and there's still room to accommodate more processes.     

## Dependencies ##
Tensorflow > 1.2    

Tensorflow object detection api (Please follow the official installation instruction, otherwise, I cannot guarantee that you can run the code)    

OpenCV python    
     

【Ref】  
[1] [Tensorflow Face Detector](https://github.com/clhne/face_jlq/tree/master/face_detection/code/video_face_detection)      
[2] [Video Face Detection](https://github.com/clhne/face_jlq/tree/master/face_detection/code/video_face_detection) 
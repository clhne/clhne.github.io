---
layout: post
title:  "Python ClearWindow"
date:   2017-06-10 20:15:00 
categories: Python
tags: 清屏 ClearWindow
author: CLH
---

* content
{:toc}

# Python ClearWindow #

----------
Python 是一门强大的语言，奈何IDLE中没有清屏的功能，可通过扩展来实现，具体的步骤如下：


1. 下载[ClearWindow.py](http://bugs.python.org/issue6143)
将其放在Python的安装目录：Lib/idlelib/ClearWindow.py下面；
2. 修改	Lib/idlelib/config-extensions.def 文件，在其结尾处添加如下代码：

    [ClearWindow]
    enable=1
    enable_editor=0
    enable_shell=1
    [ClearWindow_cfgBindings]
    clear-window=<Control-Key-;>

----------
Ref：[1] [Issue6143](http://bugs.python.org/issue6143)
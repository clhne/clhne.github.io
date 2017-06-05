---
layout: post
title:  "Jekyll 搭建静态博客"
date:   2017-06-05 23:35:20
categories: jekyll
tags: jekyll RubyGems
---

* content
{:toc}

最近在学习了GitHub Pages，因此也很想搭建一个自己的博客，但是一直忙于毕业论文，所以一直也没弄好。Google了一番之后，选择了GitHub的Jekyll模板来搭建自己的博客。


## 搭建过程

在jekyll的官网上 [http://jekyllrb.com/](http://jekyllrb.com/) 其实已经说得比较明白了，我在这里还是简单的说一下吧。我用的是Windows系统。    
主要环节有：安装Ruby，安装RubyGems，安装jekyll，安装代码高亮插件，安装node.js

### 安装Ruby

ruby官网下载安装：[https://www.ruby-lang.org/en/downloads/](https://www.ruby-lang.org/en/downloads/)

安装完成后配置环境变量

在命令提示符中，得到ruby版本号，如下图，即安装成功

![](http://ww4.sinaimg.cn/large/7011d6cfjw1f2ue0e393vj20cu00t748.jpg)

### 安装RubyGems

官网下载 [http://rubygems.org/pages/download](http://rubygems.org/pages/download) rubygems-2.4.5.zip   

cd到RubyGems目录   

![](http://ww1.sinaimg.cn/large/7011d6cfjw1f2ue1l2yscj20gk02amxj.jpg)

执行安装   

![](http://ww1.sinaimg.cn/large/7011d6cfjw1f2ue1w8eqnj20bx00hglg.jpg)  

### 用RubyGems安装Jekyll

执行下面的语句安装   

![](http://ww4.sinaimg.cn/large/7011d6cfjw1f2ue2g2p3uj207x00ft8j.jpg)

安装结束画面   

![](http://ww4.sinaimg.cn/large/7011d6cfjw1f2ue32drwhj20hv09xq5m.jpg)

至此jekyll就已经安装完毕了，后续就是个性化的自己设定了。

### 创建博客

在d盘新建一个工作区jekyllWorkspace

cd到jekyllWorkspace   

执行jekyll new name创建新的工作区   

![](http://ww3.sinaimg.cn/large/7011d6cfjw1f2ue3lt31nj20cj02nt8u.jpg)

文件结构如下：   

![](http://ww1.sinaimg.cn/large/7011d6cfjw1f2ue3ujsybj20ek06wabh.jpg)

cd到博客文件夹，开启服务器   

![](http://ww1.sinaimg.cn/large/7011d6cfjw1f2ue47y9lgj20ao00f0sl.jpg)

watch为了检测文件夹内的变化，即修改后不需要重新启动jekyll

我的环境下启动报错(你的可能没有)，再安装yajl-ruby和rouge  

![](http://ww4.sinaimg.cn/large/7011d6cfjw1f2ue4nelnxj20dd077q49.jpg)

再次启动服务器成功

![](http://ww4.sinaimg.cn/large/7011d6cfjw1f2ue4v42koj20g505bdgy.jpg)

访问 http://localhost:4000/   

![](http://ww1.sinaimg.cn/large/7011d6cfjw1f2ue56ckwoj20je0eumz3.jpg)

详细文章页面   

![](http://ww2.sinaimg.cn/large/7011d6cfjw1f2ue5f3j9cj20je0gyq7a.jpg)



关于，[hitimes](https://rubygems.org/gems/hitimes/versions/1.2.2) 是一个快速的高效的定时器解决方案库，详情可以去官网查看。

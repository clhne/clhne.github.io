---
layout: post
title:  "MarkdownPad2 Error"
date:   2017-12-27 17:20:00 
categories: Editor
tags: MarkdownPad2
author: CLH
---

* content
{:toc}

# MarkdownPad2 Error Uploading Image #
----------
今天在写博客（.md文件）时，MarkdownPad2竟然不能上传图片：    
     
![](https://i.imgur.com/p1CR8Kq.jpg)    

在研究了之前用MarkdownPad2上传图片的快捷键生成的图片格式后，发现其由三部分组成：  

	![]()
	![图标题](图片地址，如利用图床生成链接)    

所以，问题的关键就是找一个可靠的图床，MarkdownPad2利用的是美国的imgur图床，国内的如新浪微博、七牛等；为了和MarkdownPad2保持一致，也采用imgur图床，不过其稳定性和能否永久保存还有待研究。    
具体的使用方法就是：    
1、 将图片上传到https://imgur.com；    
2、 在新标签页中打开图片；    
3、复制新标签页中的网址到MarkdownPad2中。    

      
**更新**    
无奈imgur在上传图片时总是出问题，今天又尝试了下MarkdownPad2的图片上传功能，竟然可以使用了！可以使用了！了！上次辛苦寻找图床的时间算是浪费了！应该是MarkdownPad2和imgur合作，因为软件并没有更新，突然就可以上传图片了。但是通过这种方式上传的图片不知道是不是永久保存的？！    

更新于2017年12月29日 17时31分     

----------

Ref：    
[1] [图床](https://baike.baidu.com/item/%E5%9B%BE%E5%BA%8A/10721348?fr=aladdin)   
[2] [imgur](https://imgur.com)         
[3] [有哪些适合开发人员的图床？](https://www.zhihu.com/question/21349585)        
[4] [WeiboPicBed](https://github.com/suxiaogang/WeiboPicBed)     
[5] [Weibo-Picture-Store](https://github.com/Aqours/Weibo-Picture-Store)      


---
layout: post
title:  "Caching your Github password in Git"
date:   2018-02-24 14：24：00
categories:  Git
tags: Git_push
author: CLH
---

* content
{:toc}

# Git push 时免输入账号密码的方法 #
在做项目时，发现使用Git push每次都要输入账号和密码，如此机械性的重复输入大大降价了工作效率，因此有必要找到免输账号和密码的方法！       

修改配置文件，打开Git Bash：

	cd ~    //进入根目录
	touch .git-credentials
	vim .git-credentials
	https://username:password@github.com
	git config --global credential.helper store

完。
此时文件 ~/.gitconfig末尾处会多出两行：        

![](https://i.imgur.com/Zp0nOIF.png)       


----------
【Ref】：     
[1] [Git Push 免输用户名和密码](https://www.jianshu.com/p/f54053afecf2)              

	
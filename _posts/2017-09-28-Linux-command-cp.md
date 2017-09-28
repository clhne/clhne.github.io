---
layout: post
title:  "cp command"
date:   2017-09-28 10：41：00
categories:  Linux
tags: Command
author: CLH
---

* content
{:toc}

# cp 命令 #
Linux下在cp命令的用法：    
 
	cp [option]... [-T] source_dir dest_dir

使用时，遇到以下错误提示：

	cp: omitting directory ***

错误，这是因为 source_dir下含有子目录，需要加“-r” option，即copy directories recursively :    

	cp -r source_dir dest_dir

---
layout: post
title:  "OpenCL Config"
date:   2018-01-03 10：30：00
categories:  OpenCL
tags: OpenCL-config
author: CLH
---

* content
{:toc}

# OpenCL 环境配置#
OpenCL2.0 + VS2012 环境配置（工作）：    
C/C++ -> 附加包含目录：

	C:\Program Files\AMD APP\include    


链接器 -> 附加库目录：     

	C:\Program Files\AMD APP\lib\x86    

链接器 -> 输入 ->附加依赖项：      

	opencl.lib       

头文件如下：     

	#include <CL/cl.h>    


备之。      
      

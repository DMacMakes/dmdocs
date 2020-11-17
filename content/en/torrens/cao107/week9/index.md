---
title: "Week 9: GPUS - Graphics Processing Units" 
linkTitle: "9: GPUs 1"
weight: "90"
description: >
  Introducing GPUs and GPU software development.
---

## GPUs

Graphics processing units. These are at the heart of your modern graphics cards. Discrete cards are mostly Nvidia or AMD, integrated and mobile graphics by intel, apple, arm (Mali), Imagination (PowerVR) (licensed by Apple), others.

{{< imgproc gpu_s3_trio Resize "800x" Link "gpu_s3_trio.jpg" >}}
S3 Trios were popular cards in the mid 90s. This one has 1MB of video ram.
{{< /imgproc >}}

{{< imgproc gpu_asus_geforce3 Resize "800x" Link "gpu_asus_geforce3.jpg" >}}
Asus V8200 Pure GEForce 3, 128MB VRAM. 150nm process. 200MHz clock.{{< /imgproc >}}

{{< imgproc gpu_geforce7600 Resize "800x" Link "gpu_geforce7600.jpg" >}}
Galaxy GEForce 7600 GS. A fan! Flames! 256MB of VRAM!  
{{< /imgproc >}}

{{< imgproc gpu_build_geforce7600 Resize "800x" Link "gpu_build_geforce7600.jpg" >}}
This rig is the one used to test the card in a <a href="https://www.guru3d.com/articles_pages/geforce_7600_gs_256mb_gddr3_with_hdmi,14.html">14 page review</a>.
{{< /imgproc >}}

See a lot more goofy history in [this forum post.](https://forum.overclock3d.net/showthread.php?t=53027)

{{< imgproc gpu_evga_1070_ports_body Resize "800x" Link "gpu_evga_1070_ports_body.jpg" >}}
The card I bought about 4 years ago, the evga GTX 1070 superclocked with 8GB of VRAM. 1.7GHz clock.
{{< /imgproc >}}

{{< imgproc gpu_evga_1070_pipes Resize "800x" Link "gpu_evga_1070_pipes.jpg" >}}
Pipes beneath the fan and heatsink are part of the cooling solution. The 8 pin port delivers power from the PSU. The circuit board is sandwiched between two sturdy metal plates.
{{< /imgproc >}}

{{< imgproc gpu_evga_1070_flashy Resize "800x" Link "gpu_evga_1070_flashy.jpg" >}}
In a build.
{{< /imgproc >}}

### Capabilities
Push a lot of pixels and polygons. Because this is a hugely parallel task (many pixels rendered to buffer simultaneously before flashing it all to screen) using lots of math, GPUs are now also used for general purpose computing, (somewhat) like a cpu, often referred to as **GPGPU** or **GPU compute**.

### Purpose

#### Graphics
Cpus initially did a lot of the graphics work.
{{< imgproc pc_arch_early_vga Resize "800x" Link "pc_arch_early_vga.png" >}}
Earlier (80s?) PC architecture with VGA graphics.
{{< /imgproc >}}

Part of it initially moved off to a separate floating point unit, but Nvidia brought out the GPU, a dedicated card compining lots of floating point units, threaded in parallel, along with memory, schedulers, video output ports and codecs, etc.
{{< imgproc pc_arch_modern_gpu Resize "800x" Link "pc_arch_modern_gpu.png" >}}
Modern AMD and Intel x64 architecture
{{< /imgproc >}}

#### General purpose computing, 

{{< imgproc quad_gpu_3 Resize "800x" Link "quad_gpu_3.jpg" >}}
A scientist, researcher or animator might use a quad GPU workstation for massively parallel calculations.
{{< /imgproc >}}

GPUs offer so much power for massively paralell processing of lots of data that people started trying to use it for non graphics purposes, but it was hard with the graphics specific APIs. Enter cuda, openCL, effectively general purpose programming (cuda is C for nvidia gpus) for GPUs.

{{< imgproc quad_gpu_5 Resize "400x" Link "quad_gpu_5.jpg" >}}
Not in it for the xteen video outpus.
{{< /imgproc >}}

Application        | Examples
-----------        | --------------------------------------------------
Signal processing  | Denoising, upscaling
Game Physics       | Nvidia PhysX simulating destruction, ragdoll etc.
Machine learning   | Image/speech/facial recognition, language translation, etc
Simulation         | Protein folding (vaccine research), weather etc
Other Graphics     | Baking lighting maps for games
Cryptographic     | Cracking codes, mining cryptocurrency

{{< imgproc evga_1070_mining Resize "800x" Link "evga_1070_mining.jpg" >}}
A mining rig.
{{< /imgproc >}}

#### Denoising real time renders

{{< youtube "OC637pfAJs8" >}}

#### Civilian gpus vs covid vs supercomputers

200,000 home users = a distributed supercomputer with the power of the top 12 known supercomputers combined.

{{< youtube "jiMZYJ--cT8">}}

## Survey: Who has Nvidia cards, who doesn't?

Nvidia, AMD, intel integrated?
Solutions: 
  1. Head into your local campus (I'll check first Cuda SDK install status)
  2. I'll discuss remote campus machine access with IT
  3. Work in AMDs own language/SDK
  4. Work in OpenCL or OneAPI for Intel graphics.
   
## Nvidia GPU Architecture

### WATCH: Nvidia GPU programming intro presentation

From 2013 but still relevant: same architectural ideas underlying the new generations.
Start at 2:38, watch through to 18:46.

{{< youtube nRSxp5ZKwhQ >}}

### All that in print

For the last two years we've been on Nvidia's _Turing_ TU102 architecture, which followed on from the _Pascal_-based 10 series. There are new types of cores (RT, Tensor) and also much more, much tinier silicon.

Here's an NVidia blog post introducing the tech, containing many of the specs, the definitions and the images you'll see in video intros/presentations of Nvidia GPU architecture.

<https://developer.nvidia.com/blog/nvidia-turing-architecture-in-depth/>

{{< imgproc evga_1070_nude Resize "800x" Link "evga_1070_nude.jpg" >}}
evga 1070 sc gaming minus all the cooling
{{< /imgproc >}}

### Progress: Gamers Nexus 20 series deep dive 

This is a vlog/deep dive take on the information in the Nvidia blog post above, but with luscious warrior hair.

time  | Topic
----- | -----------------------------------------------------
12:00 | Top to bottom: GPC down through streaming processors
10:00 | Big Turing
7:25  | Begins talking about cache and memory (Pascal vs Turing)

{{< youtube "fpTzkrBUnGo" >}} 

### Glossary  
  
_Gamers Nexus:_ Explain explain  
_Everyone:_ What??  

Term              | Definition
----------------  | ------------------------------------------
Turing (TU102)    | Architechture of RTX 20 series (2080 etc) Nvidia cards
Pascal (TU102)    | Architechture of GTX 10 series (1080 etc) Nvidia cards
GPC               | Graphics Processing Clusters
TPC               | Texture Processing Cluster
SMP               | Streaming Multi Processor
L1/L2 cache       | fast, low latency, small memory close to processors. L1 best, smallest.
FPU               | Floating point unit or Cuda core.
FP32, FP16 etc    | Floating point precision
SDK               | Software development kit
RTX               | Nvidia cards with raytracing hardware
RT Cores          | Raytracing cores
Tensor Cores      | Machine learning acceleration cores

## Homework

**1. Read the material!** It'll be critical to understand the architecture and different ideas of parallel processing like SIMD and MIMD in order to write our own CUDA code next week!
**2. Install CUDA 11.1**

### Read!

{{< imgproc coad_cover Resize "300x">}}
{{< /imgproc >}}

Appendix C sections: C.1 and C.2
Chapter 6 sections: 6.1, 6.3 (sections on distinction between SIMD, MIMD etc), 6.6 GPUs.

Read it online with [ebook Central](https://ebookcentral-proquest-com.ezproxy.laureate.net.au/lib/think/reader.action?docID=5376640)

.. or download the chapters below if you are a registered Torrens student.

Chapter                              | Topic
-----------------------------------  | -----------------------
[Append.C](../resources/coad_appendix_c_gpu.pdf)  | Graphics and computing GPUS
[Chap.6](../resources/coad_chap_6_Parallel.pdf)   | Paralell processors from client to cloud

### Install!

Download and install the Cuda Toolkit version 11.1. Following is the direct link to the downloads page, and a video by nvidia showing the install process and use of samples.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://developer.nvidia.com/cuda-downloads" target="_blank">Cuda Toolkit Download Page<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

{{< youtube cL05xtTocmY>}}

##  notes from textbook

![simd etc](simd_etc.png)


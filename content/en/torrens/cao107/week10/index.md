---
title: "Week 10: Coding for CUDA GPUS" 
linkTitle: "10: CUDA"
weight: "100"
description: >
  GPU general computing with CUDA.
---


## Learning this week

You learned, in broad terms, the nvidia GPUs architecture over the last week. This week we learn how to think about and write a basic program with the CUDA general purpose programming toolkit.
First, how do you..
* create a CUDA project in Visual Studio 2019?
* define a kernel, or thread in CUDA c/c++?

The GPU is a whole extra card containing the processing silicon along with plenty of it's own RAM in several layers. To run kernels/threads on the device (gpu) you need to copy over the contents of variables from host memory (regular DDR4 ram your cpu and main.cpp is using) over to the device's own (possibly GDDR5 or higher) RAM.


Nice starter resource on NVidia's website, from install through your first tutorial and onto their High Performance Computing (HPC) courseware.

<https://developer.nvidia.com/how-to-cuda-c-cpp>

The more extensive guide for programmers:

<https://developer.nvidia.com/how-to-cuda-c-cpp>

## Glossary

term | meaning
----------- | ----------------------------------------------------
CUDA | Umbrella term for general computing on an NVidia GPU and the individual thread execution cores on the GPU chip. "CUDA Api", "CUDA Core", "CUDA Toolkit".
Kernel | A function that will become a thread on the gpu. Instructions that one thread will run. Gpu will usually run it in thousands of parallel threads.
streaming multiprocessor | runs one (or more?) kernel in many threads
Thread | A hardware path running a single instance of the kernel function
Block | A group of threads
Grid | A group of blocks
(Warps) | Less important, it's some threads running in lockstep in a block
Thread ID | For referring to a single thread, allows you to access its input/output
Latency | The time it takes to get instructions and data (work) from memory
Host | The regular pc brain: cpu and main memory
Device | The gpu and its memory
Bus | How info is shuttled from host to device. PCIE3 x16 or PCIE3 x8 usually.
Asynchronous | doing different work at the same time. CPU sends work to GPU, keeps working on other stuff. You go to the phone store while I pick up some mangos.

### Execution

Thinking of syncronous vs aysncronous is easier if you think shopping. It's faster if you don't watch me shop for soldering gear, then I watch you shop for photography gear. Let's split up.
  
{{< imgcard serial_async>}}
* Asyncronous: Cpu happily executes its main thread while the GPU runs its own thousands of threads (of the kernel)
{{< /imgcard >}}

Hardware: 
For the CPU we launched n threads one at a time.
You ask the gpu to execute a **_grid_ of _blocks_ of _threads_**. Give it the amount and the kernel and off it goes.

{{< imgcard blocks>}}
Blocks of threads
{{< /imgcard >}}


## A kernel becomes a thread

A kernel is some code defined to run in a hardware thread on the GPU. It serves the same role as the functions we used in regular C++ threads. 

SOURCE CODE OF REGULAR THREAD CREATE

The kernel exists to be processed by the gpu cores, so it needs to be defined in the GPUs own on-board GDDR memory, the so called _global_ memory. Not to be confused with global scope in C++. Of course not.

{{< alert title="Global, __global__" color= "primary" >}}
_Global_, in the CUDA cinematic universe, means the top level GDDR RAM on the gpu device. It has other levels of RAM like L2 cache, and bits of ram avaiable to streaming multiprocessors (SMPs) which aren't considered global.
{{< /alert >}} 

### Defining a kernel

First, we need a CUDA project to define it in.

DOWNLOAD OR CREATE NEW PROJECT IN VS

Defining a kernel is like defining a function, but you need the `__global__` keyword.

Source: Defining a simple kernel that does not much. How do we give them IDS in simplest way?

### Preparing data for a kernel

It's in the device's global memory, and it needs data there to process it.

#### Cuda Malloc and Memcopy

* From host to device. 

Keeping track of what's in our host ram and what's on the gpu device ram:
* Variables for each: pointers to pointers! 

{{< alert title="Use the `_d` prefix" color= "primary" >}}
Pointers will always provide a bit of mental work, sensible naming will help keep it manageable. 

**Prefix the names of your device variables with a 'd_'** and you'll be able to keep them straight. This is a common _convention_.
{{< /alert >}}

### Running a kernel

* Each hardware thread executes the _kernel_
Hardware threads can only run in warps (for later) inside blocks, so we'll need to ask for one or more blocks and kick off the kernel.


* **Within a block** you can communicate.
* There's **no defined order** to how the blocks execute, so don't count on any.
* **No context switching cost**. That's the thing that was slowing us down during _oversubscription_: too many _C++_ threads running on our limited CPU hardware threads.
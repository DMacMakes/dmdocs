---
title: "Week 10: Coding for CUDA GPUS" 
linkTitle: "10: CUDA"
weight: "100"
description: >
  GPU general computing with CUDA.
---


## Learning this week

You learned, in broad terms, the nvidia GPUs architecture over the last week. This week we learn how to use a GPU for regular, general purpose programming.

## GP..GPU

That's right, **GPGPU**. It's a super awkward acronym, but let's learn it: General Purpose GPU programming

If you're sitting down to write code to render real time game graphics on your GPU, it's probably because you want to offload some super parallel, very heavy work from your CPU.You're not going be writing GLSL, DirectX or OpenGL today.

{{< alert title="Enter CUDA and nvcc" color= "primary" >}}
You need a way to tell the GPU to do.. well C++ type stuff you'd normally do on the CPU. Do maths, sort things, map your face into a movie you should have been cast in, or calculate the ideal attack strategies for different team comps on different game maps.

_**CUDA**_ is a sort of umbrella term for hardware and software, and _**nvcc**_ is the _**NVidia C/C++ Compiler**_.
{{< /alert >}}

Al Pachino is Ace Ventura:

{{< youtube zWpv3hxeqq4>}}

At 1:13 Bill Hader remembers meeting Tom Cruise on the set of _Tropic Thunder_.

{{< youtube "VWrhRBb-1Ig" >}}

At 0:43 Mark Zuckerberg recites a poem about Data's cat.. in a Star Trek the Next Generation episode from 1991.

{{< youtube  "lRgf18VExvo?t=43">}}

### NVidia resources 

Here's a nice starter resource on NVidia's website, from install through your first tutorial and onto their High Performance Computing (HPC) courseware.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://developer.nvidia.com/how-to-cuda-c-cpp" target="_blank">How to Cuda in C/C++ @Nvidia<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

The more extensive guide for programmers:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html" target="_blank">Cuda Programming Guide @Nvida<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### Exercise: Create and compile CUDA project

We did this the other day in work review, we'll do it again real quick and have a look at what's generated.

## What does CUDA code look like?

It looks like regular C++ with some extra language features like **extra scoping keywords**, **special variables** and ways to play nicely when working **in parallel** with the GPU and its thousands of threads.

First, how do you..
* define a kernel, or thread in CUDA c/c++?

### Coding your GPU in a nutshell

1. Write your regular C++ cpu code (includes, main func etc)
2. Write a C++ style function for the job you want done (many many times in many threads, ideally) by your GPU, say a face-remapping thing. Use some special keywords.
3. Load some data into variables in C++, like a video file and your face photo files.
4. Move the data to the gpu and, with some special magical nvidia C++ syntax (many angle brackets) get it going!  

{{< imgcard coding_cpu_to_gpu Link "https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#from-graphics-processing-to-general-purpose-parallel-computing">}}
Click for the non-annotated version of this graphic on NVidia's Programming guide.
{{< /imgcard >}}

## Real CUDA C++ details

The GPU is a whole extra card containing the processing silicon along with plenty of it's own RAM in several layers. To run kernels/threads on the device (gpu) you need to copy over the contents of variables from host memory (regular DDR4 ram your cpu and main.cpp is using) over to the device's own (possibly GDDR5 or higher) RAM.

### Your program that uses cuda
1. Define some data (in system(host) memory)
2. Define a function you want the gpu to run, and that's in gpu(device) memory. It's called a kernel, and there's a special keyword for defining them in gpu memory.
3. COPY the data (you defined in system(host) memory) over to the gpu (device) memory.
4. Tell the GPU to start running kernel on N number of threads. They will then look for the data in the GPU memory.

### How does a thread know what work to do?
1. It calculates an id from it's place in the GPU.. which streaming multiprocessor? Which block? etc.
2. It uses that id to access that data in a collection, like the index to a vector. thread `0` accesses `BigCollectionOfFloats[0];` thread `22` accesses `BigCollectionOfFloats[22];`


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

{{< imgcard gpu_scaling>}}
Different cards with different numbers of streaming multiprocessors handle the work.. differently.
{{< /imgcard >}}


## A kernel becomes a thread

A kernel is some code defined to run in a hardware thread on the GPU. It serves the same role as the functions we used in regular C++ threads. 



The kernel exists to be processed by the gpu cores, so it needs to be defined in the GPUs own on-board GDDR memory, the so called _global_ memory. Not to be confused with global scope in C++. Of course not.

{{< alert title="Global, __global__" color= "primary" >}}
_Global_, in the CUDA cinematic universe, means the top level GDDR RAM on the gpu device, and in code both the host and device know about it. The GPU also has other levels of RAM like L2 cache, and bits of ram avaiable to streaming multiprocessors (SMPs) which aren't considered global.
{{< /alert >}} 

### Defining a kernel

First, we need a CUDA project to define it in.

Defining a kernel is like defining a function, but you need the `__global__` keyword.

Source: Defining a simple kernel that does not much. How do we give them IDS in simplest way?

#### Cuda Malloc and Memcopy

* From host to device. 

Keeping track of what's in our host ram and what's on the gpu device ram:
* Variables for each: pointers to pointers! 

{{< alert title="Use the `dev_` prefix" color= "primary" >}}
Variables across different memory on multiple devices won't be east to keep track of if the names don't give us a hint.

**Use the CUDA convention of naming your device variables with a 'dev_'**.

I also use '_p" at the end (suffix) of pointers.
{{< /alert >}}

### Running a kernel

* Each hardware thread executes the _kernel_
Hardware threads can only run in warps (for later) inside blocks, so we'll need to ask for one or more blocks and kick off the kernel.

* **Within a block** you can communicate.
* There's **no defined order** to how the blocks execute, so don't count on any.
* **No context switching cost**. That's the thing that was slowing us down during _oversubscription_: too many _C++_ threads running on our limited CPU hardware threads.

## _Cuda Add_ without the error checks

Here's the cuda template I modified in class to focus attention on the steps taken to run code on the GPU. While it's definitely a better program with the error checking left in, this version might be less cluttered and easier to understand.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="cuda-add-no-checks.zip" target="_blank">Download cuda-add-no-checks.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## Homework

Finish this code:


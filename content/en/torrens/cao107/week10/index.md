---
title: "Week 10: Coding for CUDA GPUS" 
linkTitle: "10: CUDA"
weight: "100"
description: >
  GPU general computing with CUDA.
---

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

* Each hardware thread executes the _kernel_
* There's **no defined order** to how the blocks execute, so don't count on any.
* **Within a block** you can communicate.
* **No context switching cost**. That's the thing that was slowing us down during _oversubscription_: too many _C++_ threads running on our limited CPU hardware threads.
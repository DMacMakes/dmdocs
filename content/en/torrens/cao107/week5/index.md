---
title: "Week 5: Operating Systems overview"
linkTitle: "5. The OS"
weight: "50"
description: >
  The operating system takes many single pieces and turns them into a working, programmable, customisable beast. How's it done? How are operating systems different, how are they the same?
---

## Weeks 5-8: 

{{< alert title="What will we learn?" color= "primary" >}}

Lots about _Operating Systems._

* How the operating system gives us access to our hardware, bought from all over the place and thrown in a box with a window and rgb. 
* How we can program in a way that compiles on different operating systems, and to what extent that's even possible.
* How to run another operating system inside a virtual machine.
* **Linux:** What it's like to work and compile in another operating system.
{{< /alert >}}

## Why Operating Systems?

We need to know about hardware, because it _is_ the computer. But we don't really program the computer, because it's just a bunch of different bits: we program the computer's manager, and that's the OS. It's sort of like you don't ask someone's body to do something for you.. you ask their "self", their personality, the software in their brain that controls everything. If their self is inclinde, it puts the brain and body into motion.

## Materials

### Slides

{{< imgproc osc_cover Resize "300x">}}
Rargh
{{< /imgproc >}}

<!--
![OSC](https://codex.cs.yale.edu/avi/os-book/OS10/slide-dir/images/os10-cover.jpg)
_Operating System Concepts 10th edition_-->

CHAP        | TOPIC          | LINK  
----------  |------------    |-------  
1           | Introduction   | [ch1.pptx](https://codex.cs.yale.edu/avi/os-book/OS10/slide-dir/PPTX-dir/ch1.pptx)  
2           | OS Structures  | [ch2.pptx](https://codex.cs.yale.edu/avi/os-book/OS10/slide-dir/PPTX-dir/ch2.pptx)  


### A Linux virtual machine

Install **VMWare workstation** player 16:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://my.vmware.com/en/web/vmware/downloads/details?downloadGroup=PLAYER-1600&productId=1039&rPId=51984k" target="_blank">Download VMWare Player 16<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

**Download this virtual machine** and unzip it into a virtual_machines folder on your pc:

{{< imgcard linux_mint_vm >}}
A screenshot from our Linux Mint virtual machine.
{{< /imgcard >}}

**If you know how to unpack 7z (7zip)** files, grab this smaller 3.2 GB file:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/EWFZ0tYV4D1MqOeXTIsD2rcBGhIlOi-LCCLuhdvjFJBLBQ?e=Bnj2hQ" target="_blank">Download Linux VM in 7z Archive (3.2GB)<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/ERUaIyk5nP9Fgsacv5dRKMgBJOYQ7mpmrWf-B_LGnDrxGQ?e=tQALgo" target="_blank">Download Linux VM in Zip archive (4.4GB)<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

1. _File -> Open_ the virtual machine in _VMWare_.  
2. If your pc only has 8GB of ram you can enter the virtal machine settings and lower the vm's ram to 3 or 4 GB. 
3. **Run/play** the vm, then select "copied" when it asks if you copied or moved it.
4. At times you'll be asked for a password for the user "student". There's a pinned message in the **#general_cao107** discord chat. 
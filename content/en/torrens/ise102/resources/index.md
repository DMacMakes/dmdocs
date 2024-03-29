---
title: "ISE102 Resources"
linkTitle: "Resources"
weight: 1
description: >
  Resources that we'll use in **ise102** throughout this trimester.
---

## ISE102 Textbook

We don't just have a pretty good textbook, _**"Beginning C++ Through Game Programming"**_, we have free access to it.

You can read it online or download PDF chapters from Ebook Central:

{{< imgproc book_cpp_through_games Resize "250x" Link "https://ebookcentral-proquest-com.ezproxy.laureate.net.au/lib/think/detail.action?docID=3136727" >}}
Click to read
{{< /imgproc >}}

**Download the first 5 chapters** below in PDF format:

 Link       | Topics/features covered    
---- | ----   
[Chapter1 ](cpp_through_games_1.pdf)  | Types, Variables, Input and Output   
[Chapter2 ](cpp_through_games_2.pdf) | Truth, Branching, `while` Looops, `do` loops, logical operators, random numbers     
[Chapter3 ](cpp_through_games_3.pdf) | `for` Loops and nesting, String objects, `array` (collections), multi-dimensional arrays, word jumble.  
[Chapter4](cpp_through_games_4.pdf) | `vector` collections, algorithms library, planning with pseudocode (hangman).  
[Chapter5](cpp_through_games_5.pdf) | Functions, including scope, arguments, overloading.  

## Subject Software Installs  

{{% alert title="Important: Windows Required" color="primary" %}}
The software and projects in this subject require the _Windows Operating System_.

If you run a different operating system on your laptop/home machine read the instructions at the [end of this page](#windows-options).
{{% /alert %}}

## C++: Microsoft Visual Studio Community 2019
We'll write C++ in a free version of Microsoft's industry standard development environment. Take care to select the **Community** edition for **Windows**.
<div class="mx-auto">
	<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://visualstudio.microsoft.com/vs/" target="_blank">Visual Studio 2019 Downloads<i class="fas fa-arrow-alt-circle-right ml-2"></i>
	</a>
</div>

For help with installation and getting started, visit Microsoft's [walkthrough documentation](https://docs.microsoft.com/en-gb/visualstudio/get-started/visual-studio-ide?view=vs-2019) or watch [their videos](https://visualstudio.microsoft.com/vs/getting-started/).

What's critical for us is that, when asked what `Workloads` you want to install, you **select _Desktop development with C++_** and _Install while downloading_. Then click _install_ or _modify_, whatever the bottom right button is.

![Desktop development with C++](visual_studio_cpp_desktop.png)

### Coding in the Cloud: Repl.it
This isn't an install, but instead a on online IDE where you can write out and compile c++ without having to open Visual Studio. It has syntax hilighting and some auto completion too. 

{{< imgproc replit Resize "600x" Link "https://repl.it/">}}
Online c++ IDE at repl.it
{{< /imgproc >}}

<div class="mx-auto">
	<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://repl.it/" target="_blank">Repl.it online coding environment<i class="fas fa-arrow-alt-circle-right ml-2"></i>
	</a>
</div>

Here's something I wrote in a class (demoing functions) and then shared via repl.it.

<div class="mx-auto">
	<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://repl.it/@dmacmakes/TatteredFamiliarLesson#main.cpp" target="_blank">C++ code: A function that makes you taller.<i class="fas fa-arrow-alt-circle-right ml-2"></i>
	</a>
</div>


<!-- 

## Flowgorithm

Flowchart-based programming with Flowgorithm.

If you have **your own machine**, pick "Flowgorithm Setup" and download the Windows 64 version.
If you're on a uni PC, click "Flowgorithm Portable".

<div class="mx-auto">
	<a class="btn btn-lg btn-primary mr-3 mb-4" href="http://flowgorithm.org/download/index.htm" target="_blank">Flowgorithm Setup<i class="fas fa-arrow-alt-circle-right ml-2"></i>
	</a>
  <a class="btn btn-lg btn-primary mr-3 mb-4" href="flowgorithm_portable.zip" target="_blank">Flowgorithm Portable<i class="fas fa-arrow-alt-circle-right ml-2"></i>
	</a>
</div>

{{% alert title="Using Portable Software" color="primary" %}}
Portable software can run straight from its folder, no install required.

1. Create a folder called `portable` in your home folder (`c:\Users\yourname\portable`) where `yourname` is whatever username you use in Windows.
2. Unzip `flowgorithm_portable.zip` into there. It'll create a Flowgorithm folder.
3. Go into that folder and double click `Flowgorithm.exe` to run it.

![](portable_folder_flowgorithm.png)

{{% /alert %}}
 
-->  

## Sololearn C++ Tutorial

Sololearn provides a system for learning a new programming language: It's structured to both teach and quiz you at each stage progress, helping to confirm understanding and lock in what you learn.

![Sololearn](../week4/sololearn_cpp.png)

Download from the [iOS App Store](https://apps.apple.com/us/app/sololearn-learn-to-code/id1210079064) (iPhone) or [Google Play](https://play.google.com/store/apps/details?id=com.sololearn&hl=en_AU) (Android). 
- You want just _SoloLearn_, not a specialised older version. 
- Create an account to log in
- Under _My Courses_ Grab the _C++ Tutorial_
- Put the app on your phone's home screen and start doing it today! Do not put it off or you'll forget it exists.
- After you answer a question, read the comments to see how other people fared or what tips they offer. 
- Read up to and including data types: you can stop when you reach arrays.

## Windows on Mac or Linux machines

### 1. Install Inside/Alongside Your OS

If you are on an **Mac or Linux** laptop you'll need to either install Windows 10 into a virtual machine or dual boot it. 

1. [Download the Windows iso here](https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_torrens_edu_au/EUs2E8Oj_-dNroXMb_tg0O8BhM4nTzv3g98UZ4VPnlmRCQ?e=digodN) (free unactivated). 

2. If you're on an Intel machine, either:
   a. Install** Windows in a **virtual machine** using [Virtual Box](https://www.virtualbox.org/wiki/Downloads) (free) **or**  
   b. Install Windows alongside your main OS and **dual boot** using bootcamp (Mac) or grub (Linux)  
  
3. If you're on an M1 mac you only have once option, and that is to acquire and install [Parallels Desktop 17 for MacOS](https://www.parallels.com/au/products/desktop/). There is a 14 day trial, but we'll need it for 4 weeks, and you'll need Windows in subjects further down the road. I recommend buying [the Academic version (50% off)](https://www.parallels.com/au/landingpage/pd/education/) if you intend continue your studies on the M1 mac.
### 2. Use A Lab Computer  

The lab computers run Windows.

Okay, back to [Subject Sofware Installs](#subject-software-installs)


<!--
### Text-Mode Game Template

This will add _**ise102 text mode game**_ to your _new project_ window.

_text_mode_game_template.zip_

<a class="btn btn-lg btn-primary mr-3 mb-4" href="/torrens/ise102/resources/text_mode_game_template.zip">
  Download<i class="fas fa-arrow-alt-circle-right ml-2"></i>
</a>

## Starter Projects

**ADD STARTER PROJECTS FOR WEEKLY CODE ALONG**?
-->
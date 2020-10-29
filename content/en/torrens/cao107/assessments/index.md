---
title: "cao107 Assessments"
linkTitle: "Assessments"
weight: 5
description: >
  Assessment dates, briefs, deliverables etc.
---

## Assessment 1

Three coding, observation and analysis tasks (referred to as labs) in which we'll explore the challenges of writing code that executes in parallel.

_Submitted for this trimester_

<!--

> We won't be working from the Blackboard brief for this. See the instructions below.

### Lab 1

Complete.

### Lab 2

Download the following zip file, containing the _cinema\_seats_ source code. The task **instructions are** written in comments **at the top of the main.cpp** file. You will need to **read** sections _3.1.1, 3.1.2, 3.2, and 3.2.1_ of _Concurrency In Action_; grab chapter 3 from [the resources page](../resources/).

<a class="btn btn-lg btn-primary mr-3 mb-4" href="cinema_seats.zip" target="_blank">Download Project: cinema_seats<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

{{< imgcard comments_instructions>}}
The <b>instructions for this task</b> are at the top of main.cpp
{{< /imgcard >}}

**Deliver to:**  
Danny via email (available on Discord or auto completing in outlook).  

**Due before:**  
Attempt to complete it **before work review** (Tuesday's 4pm). Final submission by email due **end of Wednesday**, week 4. 

I won't be giving answers at the work review: it'll be a chance to answer questions you have from _reading the textbook_ and your attempts to collect data. The work review answers won't mean a lot if you haven't done the reading.
  
{{< alert title="What to submit" color= "primary" >}}  

A **zip file** containing:

1. The Visual Studio project folder (NO cache folders, size < 100KB) of your multi-threaded cinema_seats program.
2. Screenshots of anomalies you discover in the threaded version.
3. A plain text (txt) or markdown (md) file with Answers to the questions, including your pseudocode.

<i>If you don't know how to delete the cache files, watch week 3's class recording.</i>
{{< /alert >}}

### Lab 3

Implement the peaceful version of threaded cinema. Use what you learned from chapter 3 and the week 4 lecture.

- Prevent multiple sales of a single seat
- Prevent garbled output by interrupted threads
- Prevent missing entries in order completed
- Do it without completely removing all parallelism.
- In a README file, explain what you've tried to implement. Reflect on how it went. Where did you succeed? Where did you fail? Can you see a path forward if you'd had more time?

{{< alert title="Delivery" color= "primary" >}}

**Elements:**

* Visual Studio solution folder containing your final cinema_seats project, minus the cache folders (.vs, x64, Debug, Release)  
* Your README.txt (or README.md) file. Put it in the solution folder along with the project files.

**Submission:**
1. Do NOT refer to the pdf brief on blackboard for what you should deliver. Go by this page's instructions to avoid confusion. Ask Danny if this page and the week 4 class don't answer your questions.
2. Zip up the Visual Studio solution folder (containing the readme as well) and name the zip file **CAO107_Assessment1_LastName_FirstName.zip**.
3. Submit the zip file to Blackboard at the link below.
4. I already have your previous labs, so don't include them.
{{< /alert >}}

Ignore the **correct naming** and leave out the **readme** file ONLY IF YOU WANT TO LOSE MARKS.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_9219125_1&course_id=_94382_1" target="_blank">Submit Assessment 1 on Blackboard<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

-->

---

## Assessment 2: Multi threaded loader

**Due:** End of Week 8 (Sunday 11:55pm)

> Load images and sound in parallel, and then display/play multiple images and sounds. Using threads, solve the problems that emerge when we load large/many images/sounds. Keep the interface responsive, and keep the user informed. Allow the user to decide how many threads to use during loading.  
>  
> Use what you're learning in class (and through your own research) to theorize about and test solutions to the delays you see when using different numbers of threads.  

{{< imgproc Base_imgui_running Resize "550x" Link "../week6/#code-your-imgui-base-project" >}}
Click to see visit the project base section of the week 6 notes.
{{< /imgproc >}}

### Brief and submission on Blackboard

You can refer to [the brief found on the Blackboard Assessment 2 page](https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_9219126_1&course_id=_94382_1) but don't use the old MultiThreadedLoader Starting Template.zip provided there. Instead, use the [base provided in week 6](../week6/#code-your-imgui-base-project). 

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_9219126_1&course_id=_94382_1" target="_blank">Submit Assessment 2 on Blackboard<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

{{< alert title="The details" color= "secondary" >}}

**Load multiple images**
  - open by default
  - top left and cascading (try adding n pixels to the x and y position of new window first creation)
  - list with buttons
  - allow multiple image select in dialog
  - can you add jpg/tif support?

**Load multiple sounds**
  - use SDL mixer
  - ready to play on load (don't play)
  - a button for each to play
  - extra features
    - per sound mute
    - per sound volume
    - overall system volume

**Large files!**
  - Immediate mode gui runs at 60 fps.
  - Loading a large image or sound, loading many images at once.. 
    - does that make interface responsive?
    - how long does it take?
  - If so, how can we fix that with threads?
    - Can try with regular threads
    - Can try with boost pooled threads
    - The user needs to be able to select the number of threads used during loading. So do you for testing. Add an imgui control/widget supporting this. One good place might be a new/existing menu in the Media Loader window.
    - How do you avoid accessing images/sounds before they're fully loaded? Think about those data races!
    - Does the solution lock the entire vector of images/sounds? How can you avoid that
{{< /alert >}}

# Assessment 3: Cuda + Cpu threads Mandelbrot

Due to end of week 12
Mandelbrot fractals using the CPU and GPU together.

* Build your program on the base provided, built with imgui and SDL2.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="" target="_blank">Base link will be here.<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

More info soon. 

<!-- 
Look at GPR202. Also maybe noman slides from weeks 8-11.
Try to give them a base that lets them test it. Show knowledge not so much by writing their own cuda code but instead testing and choosing the write amounts of data to distribute across the right amount of threads. If they can do a good job of picking ranges of numbers to test, and come out with ones that optimize it well, then they're showing enough understanding.

Notes incoming from noman when he looks through ICG and GPR202.

* Cuda example fits all the criteria! Use imgui to compare how it uses 
* Make the subject about how you write guis to explore and measure these system capabilities, not understanding them in and out.
* What matters is showing you can test difference between CPU and GPU, finally how to use both.

Look for available resources: Cpu cores and Cuda hardware on a capable Nvidia Gpu. Create an interactive image of the mandelbrot set using these resources.

Zoom in and out.

Split work appropriately between available resources to maximise speed.

**Qs**
** What windowing/multimedia library? SFML? SDL2?
-->


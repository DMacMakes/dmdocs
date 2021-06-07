---
title: "cao107 Assessments"
linkTitle: "Assessments"
weight: 5
description: >
  Assessment dates, briefs, deliverables etc.
---

---

## Assessment 1

Three coding, observation and analysis tasks (referred to as labs) in which we'll explore the challenges of writing code that executes in parallel.

> We won't be working from the Blackboard brief for this. See the instructions below.

### Lab 1

Complete (see [homework in week 2 notes](../week2/#homework---assessment-1-lab-1))

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

--- 

## Assessment 3: Cuda programming

We're implementing and adding to a "game" in which you are a magic user surround by many small but nasty _Creepers_. We want to optimise it using the GPUs general compute capabilities and take some work off the CPU. We can't just asssume it works though, we need to measure and to understand!

**Due:** Sunday December 6 (end of week 12, T3 2020)
**Deliverable:** Your solution/project folder, zipped. Details below.

{{< imgcard a3_creeper_sample>}}
Some of the Assessment 3 features
{{< /imgcard >}}

{{< alert title="Meteor Strike base" color= "primary" >}}
In **week 10** you're given a project in that uses an **_Nvidia GPU_** with **_Cuda_** capabilites to run a a function on many threads. Your homework is to trigger the _**meteorStrike**_ spell that does great damage in the center of its circular area of effect, falling off toward the edges and finally nothing. 

You use ImGui_ and _SDL2_ as in assessment 2, to control and display the results of events in a windowed graphical user interface.
{{< /alert >}} 

### Add features and analyse!

Read the textbook's GPU appendix C, section C.3, _Scalable programming with CUDA_ around **page C-17**.
Create a folder called analysis in your project. Edit a text file called ANALYSIS.md, and include all your answers to the questions below, plus any observations you'd like to make. 

Task                                        | Details
--------                                    |----------
1: **Display** creepers distance, health        | Do this graphically so it's fast to read. Use tools like imgui's plotting widgets, the implot plugin, or your own approach (say, SDL2 to generate a 2D diagram/3d scene)
2: **Sort** the creepers by distance.           | Consider std::sort in the algorithms library.
3: Increase creeper count to **1024**.          | You will need to consider the number of threads and blocks to acquire on the GPU, and how to get the right creeper index for each thread.
4: **Time** the castMeteorStrikeCuda function.  | Use the timer class from a2 to time the function (this includes memory allocs, copies) in milliseconds. Make sure you don't include the first initialisation time of Cuda library (goes away in subsequent spell castings). Display it in an easy to read way in the UI.
5: Write a **CPU version** of meteorStrike | A function that does the same thing as the CUDA spell using a single loop on the CPU (no threads). It can operate on the same local Creeper collection. Time how long this takes to run.
6: Try **4,096** Creepers. **8,192**. **16,384**.  | More?  Process them all. If/when imgui struggles to plot them displaying representative group of them (selected across the population).
7: Compare+contrast GPU/CPU performance. | Run on each for small and very large numbers of Creepers. Is the GPU version ever faster? The CPU version? What accounts for the times when the CPU is faster (if ever), and slower(if ever)? Give a well considered answer of a few sentences, taking into account the architecture of the pc and gpu, and perhaps scheduling?
8: Change the Creepers to x,y location. | Generating x and y location instead of distance. 
9: Change rollCreepers to distribute randomly in a circle. | Use a radius of 20m (diameter40m). If you can't get that working, second best option is a 40m x 40m square.
10: Make Cuda and CPU meteor strike calculate creeper dist from (0,0). | That is, the center of the spell aka where you are. This distance should be calculated fresh each time in case they, you know, crept. Write the code to find the distance between the creeper and center using the formula for the distance between two points, using sqrtf and powf. Don't use an existing point class with its own super optimised distance thingy - we want the maths in there to make the cpu/gpu work a bit on the arithmetic!
11: Compare the cpu and gpu results | You're doing it again for small and very large numbers of Creepers. Has anything changed? If so, what's behind the new results? Predict how this would go with a) more creepers and b) more complex calculations.

#### Add more features:

1: Controls! Widgets to input the number of creepers, the sample size. Graph control options? 
1: More spells!
1: Increase the number to Creepers to 1125. | How will you acquire enough threads while not attempting to access non-existent creepers past the end of the array?

{{< alert title="Code base and IDE Requirements" color= "secondary" >}}

* Build your program on the base provided for _Cuda 11.1_ in _Visual Studio 2019_. Libraries are supplied and tested.
* Based is introduced in the [week 10 class]<week10/#homework> with a homework task.
{{< /alert >}} 

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/ERBkakUq8_FDkMI2m0H0zlUBwFPGWZ0GzQ2sfSg493u53A?e=V0csJ2" target="_blank">Direct link to Week10 cuda-creepers-homework.7z<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### Submitting A3

* 7zip the folder that contains the libraries_cpp and the cuda folder with your project inside. Delete all those cache folders first as usual, including `build` and `obj` folders. Name the file `cao107_a3_lastName_firstName.7z`
* Don't forget, your project should include the analysis folder with your responses and any images.
* Upload to torrens LFS in uploads section under CAO107 (if visible) or CAO201. Try [this link](https://laustu.sharepoint.com/:f:/r/sites/lfs/2020/T3/CAO107?csf=1&web=1&e=SizAHd) for CAO107 if you weren't able to find it.
* Submit the link on the Blackboard assessment 3 page.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_9219127_1&course_id=_94382_1" target="_blank">Blackboard submission<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://lfs.torrens.edu.au" target="_blank">Torrens Large File Submission<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>


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


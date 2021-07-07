---
title: "ISE102 Assessments"
linkTitle: "Assessments"
weight: 5
description: >
  Assessment dates, briefs, deliverables etc.
---


## Assessment 1: Exam

**Completed:** Monday, June 28

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_9917265_1&course_id=_112961_1" target="_blank">ONLINE: Exam and brief on Blackboard<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

<!--

Testing your understanding of the **ideas in programming**, along with knowledge of C++ **data types**, **operators**, **evaluation** and more. 

### Deliverable

An online exam you will complete **on Blackboard**. The exam will be available to start at any point from (and including) Friday June 25 **until 11:55pm Monday, June 28**.   

* Once started, you have to complete it the time specified.  
* You can **return** to the exam **during** that time if your machine/internet goes down, but **not after**.  
* If a serious technical issue stops you from returning to it, please contact me.   
* The uni will require a legitimate reason, so make sure that when you sit down you have time to complete it without interruption from family/friends/responsibilities.  

{{< alert title="Preparation" color= "secondary" >}}
You will need to have 
1. Attended and/or watch recordings of **ALL of EVERY class**, and worked through the **exercises and homework**
1. Carefully read and understood the **first three chapters of the textbook up to and including for loops** (available on the resources page)
1. Worked through sololearn up to and including data types (tute 3).
1. Reading and quizzes won't get you far on their own: for these principles to stick you need to have written, **tested and experimented/played with code** from the textbook and the weekly lectures. 

Coding is like any other craft or science: if you don't practise, if you don't break it apart and put it back together, if you don't switch it around to see what happens, you won't learn it.

**#1 tip:** If you think you really understood the example you typed out and toyed with, close the project, create a new one and **rewrite it from memory.** If you don't get anything wrong first go, it's not a hard enough exercise!
{{< /alert >}}
-->

## Assessment 2: Slot Machine

**Due:** End of week 8

A text based slot machine using the C++ *console* template. A _prompt and response_ game loop.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_9917266_1&course_id=_112961_1" target="_blank">Online Assessment 2 on Blackboard<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## Assessment 3: Realtime Game

**Due:** End of week 12

Make Snake! See the **brief provided on Blackboard** (in the assessments section discussed in *submission* below) but **also watch classes and reviews** to get all the important details. 

<!--

> It's not enough to simply read the brief and make a program - your work has to reflect and demonstrate profiency with practises taught in class and should use code provided to you. This assessment must be built on the base code provided in class (weeks 10/11).

### Deliverables 

1. Weekly homework submission contributes to your marks.
2. **Week 11 homework** submission is **required.**
   **Due:** Midnight, Sunday, end of Week 11 (May 2 in Trimester 1 2021).
3. Your **entire** Visual Studio solution must be cleaned of unnecessary folders, zipped and submitted on Blackboard. You must follow the method taught in class and described/demonstrated in [Delivering Visual Studio Solutions](#delivering-visual-studio-solutions) below.

### Submission

Submit your assessment by:
1. Visiting your subject's page on Blackboard
2. Selecting *Assessments* in the left nav 
3. Clicking on *Assessment 3 - OOP Principles Program*
4. Optional but wise: check your work fulfills the brief
5. Click *Assessment 3 - Submission* and follow the instructions.
   
-->

## Delivering Visual Studio solutions
<a name="deliverable"> </a>

You'll deliver a **zip file** containing your Visual Studio solution. You DO NOT need to submit a build (with executable) as mentioned in the brief. Just a zip of your solution/project folder, as described below.

Work through the steps shown in the video carefully: if you miss submission requirements it will cost you easy marks.

{{< alert title="Correct zip name" color= "danger" >}}
**Ignore** the naming in the video. Use this, which matches the brief pdf:

**ISE102_AssessmentX_Lastname_Firstname.zip** where X is the assessment number (1, 2 or 3).
{{< /alert >}}

{{< youtube H44emolQCz4 >}}

{{< alert title="Where Is My Project Folder?" color= "secondary" >}}
With your project open in Visual studio:
  * Right click the project in the _solution explorer_
  * Click _Open folder in file explorer_. 
  * You'll see several files there, including your `.cpp` file.

If you have **a subfolder** in there with the name of your project, message me on Discord! **Do not move its contents or delete it**.
{{< /alert >}}

### What You Should Delete
Your project file might be several hundred MB in size! Meanwhile, the files you actually need are about 30-50KB in size. Let's delete what we don't need.

In your solution/project folder (same thing for us) you can **delete all** of these folders:
* _.vs_ 
    * visual studio will probably have to be closed for this one
    * If you can't see it, **turn on "hidden items"** in Windows explorer's *view* ribbon.
* _Debug_
* _Release_
* _x64_

{{< imgcard folder_cleaning>}}
Here are some of the folders you'd delete. DO NOT MOVE YOUR FILES if your folder is missing the proj files and cpp files. Contact me.
{{< /imgcard >}}

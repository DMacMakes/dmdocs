---
title: "7: Redrawing the screen, Debugging."
linkTitle: "W.7 Screen refresh"
weight: 70
description: >
  *Clearing the screen* the difference between scrolling chatbot and switching between screens, menus, viewpoints. *Debugging* tells us what the machine is thinking.
---

## Code from the review

Written during yesterday's review, it's the base we're moving forward on (or an equally functional base you wrote for homework).

If you haven't watched the review and don't have this code ready, stop watching now and do that first. Watch the rest of this class recording afterwards

{{< imgproc pokey_dokey_base_w7 Resize "200x" Link "pokey_dokey_base_w7.png" >}}
Middle click to view in new tab
{{< /imgproc >}}


## Exercise 1: Refreshing the console

Our game is scrolling off down the screen like a chatroom. It's not a natural fit for our game, with its distinct screens.

Run the windows command prompt by pressing <kbd>win</kbd> and typing `cmd`, then press <kdb>enter</kbd>. When the command prompt/console window appears:
1. Type `dir`&#8629; 
2. Type `cls`&#8629; to clear the directory listing from the screen.

![cls in the console](cls_console.png)
Here's what happens if you type <i>cls &#8629;</i>  in a regular windows command prompt. Don't worry, in c++ we won't see the `c:\Users\username` prompt.

### Clearing in C++

C++ doesn't know a lot about the console, and doesn't have its own way to clear it. That's considered Window's own problem. We can get around it by running "cls" from inside C++ using `system()` like so:

```cpp
#include <cstdlib>   // Access the `system` command in the cstdlib header.
...

cout << "Line 1" << endl;
system("cls");
cout << "Line 2" << endl;
```

Why does that work?

{{< alert title="cls: Clear Screen" color= "secondary" >}}
`system("cls");` wipes the console clear and puts the cursor top left, because that's what `cls` would have done in the console. 

We're using the special `system()` function in *C++*, it can run an external command if it it's available wherever our program runs. With a console program we could use `system` to run more than just `cls` - `dir` or `echo hello` for example.

{{< /alert >}}

## Add screen clear to Slots

Adding `system("cls")` between screens.

`main()`, the boss, controls what's showing next on screen by calling functions. 
- functions don't know what happens before or after they're done. They just output stuff and pause.
- This makes it `main()`'s job to trigger the clear.

**Demo** adding clear.

### A bug appears

> Our game returns to the main menu at random points? Why?

We have theories, and some of you know this answer right away. That might come from a bit of coding experience, or reading ahead, or just seeing the problem.

**We can't always rely on intuiting the problem.** We need a way to see what's happening, to slow things down or stop them, to see inside our program as it runs on our cpu.

## Making the computer wait

We need to **wait for people to read before clearing the screen**. We could wait for:

{{< alert title="Time" color= "secondary" >}}

Waiting for x seconds might work.
  * When a screen is done, we tell the program to wait or sleep for the right amount of time.. but do we know it?
  * what about slow readers? 
  * Or fast readers?
{{< /alert >}}

{{< alert title="Input" color= "primary" >}}
Let the user decide.
  * RPGs have lots of text to read, and they let you tap a button to move on. That's a better fit.
  * How do we ask the computer to wait for a single key to be pressed?
  * Where do we put the code?
{{< /alert >}}

### Wait for key press: _getch()
`_getch` is a function available in `<conio.h>` that pauses the program until a key is pressed. It stands for _get character_ and returns a code for the key/character.

If your program only needs to wait for any key press there's no need to save the return value. The waiting is useful in itself.

### Who's in charge of pausing? 

There are a few places `_getch()` could go now and get us the right result.. for the moment.

If you don't think about which functions should do the job, you can come unstuck later.

**Does main need to know** which screens need key press pausing and which don't? 
  * What if some already have a natural pause at the end?
  * What if some _do_ work better with timer, like maybe the exit screen?
**Do the functions know** when they've displayed something that needs to be seen before returning to main?
  * Yes, they do.

Let's put them at the end of the functions, where our breakpoints went.

## Delivering code assessments

How to delete cache files (big, unneeded), zip your project and name it correctly.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://dmdocs.netlify.app/torrens/ise102/assessments/#deliverable-1" target="_blank">Cleaning and delivering projects<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## Fleshing out pseudocoded functions

Display menu loop.

Pseudocode more detailed PlaySlots.

## The menu loop

I want the menu to **handle bad input gracefully**. This isn't just because it's good practice: **in the brief, 15%** of the marks go toward user testing and data validity checks:

![](brief_data_validity.png)

So we'll catch mistakes and prompt the user to try again. At a minimum, if they enter a number that isn't a menu choice, should be caught and an error message shown.

![](menu_input_check.png)

First, here's a simple bullet list breakdown.

* Display cash total (argument)
* Display choices
* Ask for a choice
* Check if their choice is valid (in the range of choices)
* Show them an appropriate error and make them choose again until they succeed.
* return choice

### Planning

Note, firstly, I've changed the name from displayMenuGetChoice. It's consistent with other functions now. The function signature and intellisense (little popup on hover) tell us the return value.

The main problem to solve is checking input and showing errors to the player. 
  * Multiple attempts (and showing errors) requires a loop
  * Screen isn't scrolling so redraw the whole menu to show errors. Whole menu is inside the loop then.  
  * Since we clear and redraw screen to show error, we'll need to remember the error. (Can't just write it to screen as soon as it's discovered)

<!--

## TODO :rework with last week's in-line pseudocode
Write it based on the code i ended up writing in class, but throw in a bug or two to show how to work through them?
Add homework!

-->

## Pseudocode 

{{< alert title="First pass" color= "primary" >}}
Thinking about the problem in a high level way, but with coding structure (A halfway point between bullet list and pseudocode).

```
start DISPLAY_MENU_SCREEN ( with playerCash )
  Things to store:
    A valid range of menu choices.
    Their choice
    A relevant error message we can print.

  Processing to do:
  loop..
    Show the player's cash
    Tell user the menu options and number them
    If there's an error to show (from a previous loop), show it.
    Get their choice
    If their choice is in range, clear any errors
    else set an error message for next loop.
  keep looping while there's an error message
    
```
{{< /alert >}}

{{< alert title="Second pass" color= "secondary" >}}
Time to plan the structure properly, with variable names (storage), output, conditionals (processing) and input.

```
start DISPLAY_MENU_SCREEN ( playerCash )
  error = ""
  choice = 0;
  
  do
    
    print "You have " $playerCash
    print menu choices
    if error isn't empty print error
    print "Enter 1 2 or 3 >"
    
    choice = player input
    if choice is in range
      error = ""  // clearing the error
    else
      error = "Nope, just press a number and hit enter."
    end if
  while error isn't empty
    
end DISPLAY_MENU_SCREEN
```
{{< /alert >}}

### `displayMenu()`

This is a little different from what I taught on stream. Instead of checking that the choice was *out of range* first, it checks if the choice was *in range* first, matching the pseudocode above. I also added `TOO_LOW` and `TOO_HIGH` to the MenuChoices enum. If you were in the class: do you think it's more readable this way? Tell me in the Discord ise102 chat.

{{< imgcard "code_displayMenu" Link "code_displayMenu.png">}}
Updated displayMenu, click to expand.
{{< /imgcard >}}

## Summary

This week we:
* Learned to create screen-based program flow with `system("cls")` and `_getch()`;
* Learned about the debugger

## Homework

### What to do

The goal this week is to practise cleaning and submitting a project, along with showing your progress on the slot machine (simple program) assessment which is due shortly. 

1. At a minimum, you should have the class-demonstrated features in your program: screen clearing, waiting for the any key and an error-checking main menu.
2. Given the assessment is due next week, there should be other functionality coded by now and hopefully any remaining tasks at least noted in your comments if not pseudocoded.
3. Close Visual Studio and clean up your project for submission as taught in week 7 class, then zip it. You can use the name `ise102_slots_week7_lastname_firstname.zip`. There is a short guide on the subject [resources page](https://dmdocs.netlify.app/torrens/ise102/assessments/#deliverable) and the full 25 minute walk through with all the reasoning behind the process in the [Class 7.2 recording here](https://au-lti.bbcollab.com/recording/87d7fbef0fc94cfe85032a2b01850e1c)

### Delivery

**Check the size of your zip file is <50KB**. If not, you haven't deleted all the cache folders and need to watch the video again. Do not send me an over-sized zip file. Did you turn on *show hidden files* in your Windows file explorer? 

**Email me** your zip file (`ise102_slots_week7_lastname_firstname.zip`) to me  by Midday monday. 

<!-- 

More info coming, rework the code in the homework 7 page.
Type out and complete the code. Submit it as you were shown today.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../homework7/" target="_blank">Week 7 Homework Page<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

-->

## Extra learning: The _Debugger_

Killing bugs with the debugger!

The debugger is a few things. For one, it's a **special interface mode** of Visual Studio that:
* Lets you stop and start program exection
* Shows you the contents of variables without having to use `cout`

{{< imgcard debugger_outcomes Link "debugger_outcomes.png">}}
No cout required: the <i>debugger</i> halting and looking inside the program in real time
{{< /imgcard >}}

In the background it's also a program that is running and seeing into our program's memory, like Neo in the Matrix.
   * It has special permission to **access and change** your program's data and instructions **in memory**
   * It relies partly on code that visual studio compiles into your program

{{< imgproc see_code_agents Resize "700x">}}
Hello, Mr Smith.
{{< /imgproc >}}

### Breakpoints

The first way we'll use it by **setting breakpoints**: points at which to take a break.
  * Set a breakpoint in the credits screen function, just before it returns.
  * Set a breakpoint in the play slots screen too.

{{< imgcard debug_breakpoint_controls >}}
Execution controls and the breakpoint marker
{{< /imgcard >}}

{{< alert title="The takeaway" color= "primary" >}}
our program didn't start randomly going back to the menu screen. It was always displaying main after drawing screens, it just hadn't been wiping everything else away when it did. 
{{< /alert >}}

## Squashing other bugs

There are enough variations on mistakes that the bugs we can create are effectively infinite.
Infinity is too many items to check, we need a smaller list. We need to use the power of **ABSTRACTION!**

### Categorising bugs

We need some categories (a form of abstraction) that almost all our bugs will fit in. Here are 3 

Design bugs:
Your way of solving the problem has logic issues.
* The math doesn't actually solve the problem 
  * eg: your formula for cylinder surface area actually gives cone surface area
* Your test isn't testing what you think it's testing:
  * Your logic is testing a smaller or larger range than you realise
  * The order in which you test things misses certain cases

#### Implementation bugs:

A) Random mistakes (attention, coordination, lack of sleep)
* Typing errors
* Inconsistent upper/lower case

B) Translation fail
* Your design was solid. Your code doesn't actually do what the design does.
* Overlaps a lot with C)

C) C++ inexperience/knowledge shortfalls:
* Your structure doesn't send 
* We think an operator/keyword/function does one thing, in truth it does another.

#### 'External' bugs:
Things that either A) we didn't do, or B) that we did but not in the code or design.
A) things:
* Placing things in the wrong directory
* Not informing Visual Studio that we put something in a  directory
B) things:
* Bugs in Visual Studio
* Bugs in libraries we're using

## Looking for bugs

### Look at the output symptoms
This helps best when you have a rough idea of the problem and you're not too far wrong.

1) What is the output?
2) What output did you expect in this case?
3) What other outputs to you expect in other cases? Plan them and test them.
4) Add more outputs with `cout <<` or other methods. Called **debug outputs**.

### Step through with debugger
Watch it happen, find the unexpected. 
* This is great for problems you've completely misunderstood from the symptoms. 
* You'll often misunderstand the bugs from design errors and inexperience/knowledge shortfall 

1) You still have to have expectations at each point of the program as you watch it run.
2) When it does something totally unexpected, you have a new possible culprit!
3) Form a new theory about the bug and test it.

<!--

## Coding Conventions

Agreeing on a style of code formatting and capitalisation.

In my old week 6 notes:
[https://dmcgits.github.io/mds/ISE102/week6_notes.html](https://dmcgits.github.io/mds/ISE102/week6_notes.html)
-->
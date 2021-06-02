---
title: "1: Beginnings"
linkTitle: "W.1 Beginnings"
weight: 10
description: >
  What is programming? Making our first programs.
resources:
  - src: "dad_car.jpg"
    params:
      byline: "Credit: http://annx.asianews.network"
---
## Software Requirements

Before we can do any programming, you need to have the right software on hand. If you haven't installed *Visual Studio* and *Flowgorithm* you need to follow the link and do so! 

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../resources">ISE102 Resources</a>

## Communication

Stay on top of *announcements* and *torrens emails*. 

Announcements: On blackboard, under each subject, is the announcements section. 
Torrens Emails: Emails sent

### Don't miss critical messages

It's every student's responsibility to regularly check for any correspondence from the University and their lecturers. Due dates, extensions, chances to resubmit, changes of class time. Consider it the same as a notice from your real estate, a call to jury duty or an expiring car registration: events are in motion whether you read it or not, so read the emails and avoid surprises.

#### Set up Outlook
Set up Outlook on your phone with your uni address and leave notifications on. Don't miss any critical messages.

### The Discord server
Let's jump on Discord Join the Torrens class discord server if you haven't already. I'll be making announcements there but we'll be using the subject channels to post our work during class, ask questions when we get stuck, etc. *(PS - don't show your code in the channel, just screenshots)*

#### Quick intros

Introduce yourself in our #class-ise102 channel.

1. Name
2. Degree you're doing here
3. Uni, school or job you went to before taking this course
4. Favourite game ever and favourite current game. Include platform you played it on (Switch, XBone, PS5, PC, phone etc)
5. Have you ever programmed or scripted before? Python, javascript, scratch, maybe even html? Was it for yourself or at work? Did you get far?
6. Have you ever opened up your computer and changed/added parts? Have you ever built your own pc from parts?

## Programming is just recipes

First, good news. Programming is something you have been doing your whole life, it's just that for many of you it's not on computers. For those people, programming might sound a bit offputting because it evokes the idea of computers and code and zeros and ones; but that's just the details at the end of the process, the execution. 

What you'll learn in this class is that programming at its heart is something much more basic: **a recipe for completing a task**. 

{{< alert color="secondary">}}
If a baker writes down a recipe for her chocolate ganache, she's **writing a program** that enables another human to do one specific task: reproduce her tasty dessert. Again: A program is just a recipe for completing a task.
{{< /alert >}}

### Recipes are simple

A recipe is usually just:
1. A bunch of ingredients and their quantities
2. A list of instructions for preparing and cooking them.

If you've never seen or followed a recipe, here's an example.

{{< alert title="Good Old Pancakes" color= "secondary" >}}

*Credit: Dakota Kelly, allrecipes.com*


![Pancakes](pancakes.png)

**Ingredients:**
* 1 1/2 cups plain flour
* 3 1/2 teaspoons baking powder
* 1 teaspoon salt
* 1 tablespoon white sugar
* 1 1/4 cups milk
* 1 egg
* 3 tablespoons butter, melted

**Directions:**

1. In a large bowl, sift together the flour, baking powder, salt and sugar. 
2. Make a well in the center
3. Pour in the milk, egg and melted butter.
4. Mix until smooth.
5. Heat a lightly oiled griddle or frying pan over medium high heat. 
6. Pour or scoop the batter onto the griddle, using approximately 1/4 cup for each pancake. 
7. Brown on both sides and serve hot.
{{< /alert >}}

### Instructions: you've all given them.

Maybe you haven't written a recipe, but **you've given someone instructions**. Maybe you asked your dad to drive you to your friend's house. When you told him the time to leave and your friend's address, you could say you did some *Parental Programming*.

{{<imgproc instructions_eng Resize "600x" Link "https://www.english-at-home.com/giving-instructions/">}}
Giving instructions is something we learned at school and at home.
{{</imgproc>}}

## New program: Dad drives me to my friends house

Say you want dad to drive you to Charlene's house at 7:30 tonight, for reasons he doesn't need to know. You're going to need to *instruct* him.
* He's old so you need to have a **plan**.
* You'll need to use just the **right phrases** or he won't run the program.

Let's break it down.

{{<imgproc dad_car Resize "900x">}}
Dad loves helping out.
{{</imgproc>}}

### What Do We Need For Dad Programming To Work?

1. **Dad**, so we can program him
1. Ingredients: 
  * A car: Dad's car
  * A destination address: Charlene's address
  * A time: 7:30pm
2. A recipe or list of **instructions** for him to follow
    - When the time is 7:30
    - Drive me in your car
    - to Charlene's address
    - Go home!
    - Wait for my call
3. A common **language**:  
    - Something you both speak to people in general  
    - Better: particular phrases and keywords known to.. *motivate* dad.  
4. A setting this can all happen in: in this case it's a city on planet earth with **roads** to drive on.
  
```
PROGRAM driveMeToCharlenes

car = yourCar
goTime = 7:30
charlenesAddress = 14 Stampy Rd, Fairfield

START
  if it's goTime and I get in your car
    look up directions to charlenesAddress
    drive until we get there
    let me out
    go home!
    wait for my call
END
```

## Requirements for giving orders  

We'll be writing different programs for different tasks, and dads+cars won't always be involved. 
If we remove the dad, the car and the route, we end up with a handy, general way of thinking about getting a human *or* a device to solve a problem. 

| Requirement        | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| *Helper*           | A subject (human, computer, smart speaker) we can order to do the work. |
| *Language*         | A language you can both speak, with words-in-common and grammar(rules). |
| *Context*/Platform | A setting where the work can take place.                     |
| *Information!*     | Info needed to get the work done: names, addresses, numbers, lists. |
| *Instructions*     | Steps/actions which, performed correctly and with good info, will lead to a well-done task. |

## Giving orders to a computer with c++

The same table applied to **our in-class coding**.

| Requirement     | Description                           |
|-----------------|---------------------------------------|
| *Helper*        | Windows PC                            |
| *Language*      | C++ (in Microsoft Visual Studio 2019) |
| *Context*       | Windows Console application           |
| *Ingredients*   | Data, including *variables*           |
| *Instructions*  | Our English recipe instructions converted into lines of code |

### Helper: PC

This is easy. The subject is a computer. In our case a **PC with an Intel Processor**, with all the usual bits and peripherals (keyboard, mouse etc)

### Language  

We'll be using **C++**, a programming language first created in the early 1980s.  

* Built on a language called C
* "Close to the hardware"
* In some ways dated
* At the same time it's the most relied on programming language on PCs. Where you'll find it:
    - Huge amounts of the code in Windows and Linux (more on MacOS later)
    - Major applications like Word, Photoshop and Chrome,
    - The game engines behind any AAA and most indie titles.
* Used in Planes, fridges, satellites, watches, particle colliders. (picture)
* Quite familiar to `Java`, `C#`, `ActionScript` programmers.
* Somewhat familiar to `Python` coders, and in some ways strange.
  

We'll use Visual Studio to write our source code and turn that into programs (though other environments exist).

## Context: The windows command prompt

We're going to make a text-based program. To do that we'll write a program that runs in the  *Windows Command Prompt*:

![Command Prompt](command_prompt_new.png)
<br /><br />
Windows, at its heart, is an **operating system**. It takes all those bits of silicon, gold, copper and plastic, and makes them work together. The thing you're used to using, with *Explorer* windows and the *Start Menu* is a thing that sits on top, called a **window manager**.

Under that lives the beast that actually controls network cards, drives the monitor, moves files around drives, sends sound to the speaker etc. It's the **kernel**. *Windows*, *MacOS* and *Linux* all have one.

Before we had fancy graphical window managers,regular users were met with a black screen with some text on it. You typed in commands to run programs, and they controlled the kernel:

![Command Prompt](command_prompt_programs.png)
<br /><br />

`cd` (*change directory*) is a program for changing into a folder, `dir` (*directory*) lists the contents of a folder and so on.

Why is it still in Windows? Because that's how a large portion of serious system administration is still done, by calling lots of programs in the command prompt!

#### Exercise

Open the Command Prompt and **try out the commands** above for yourself.

1. Press the `Windows` key, next to `Alt`.  

2. Type `Command Prompt` and hit `Enter`.  

3. Type the commands in the screenshot, hitting `Enter` after each.  

4. Also try these commands:  
    1. `echo I am a computer`  

    2. `echo %PROCESSOR_IDENTIFIER%`  

    3. `ping www.reddit.com`  

{{<alert title="Many names" color="warning" >}}
You might come across (or he me say) any of these things, all meaning the  **command prompt**.

* console

* the DOS prompt

* a terminal

* cmd

  {{</alert>}}

## Instructions.

The rest of this class is going to be about turning a task into instructions for our PCs, then getting them to execute them. To give instructions though, we'll need a task for them to complete.  

### Our first program: Knight's Journey

![Knighting](knighting.png)

_**Knight's Journey**_ is going to be a game where you give your name, and are immediately made a Knight.

**The Computer's Task:** It has to know our name and then use the right ceremonial words to make us into knights. How do we instruct it to complete that task?

### Instructing The Computer

Before we write computer language, let's write the instructions in a language we know, English. 

> "Dear computer, please..
> 1. Ask us for our name  
> 2. Receive our name via keyboard  
> 3. Remember our name  
> 4. Know the special knighting words  
> 5. Combine our name with the knighting words  
> 6. Point out the resulting sentence, so we know we're knights. " 

## Exercise: Knights Journey in C++

### Setting up

Visit the [ise102 Resources page](/torrens/ise102/resources/) and: 
1. Install *Visual Studio Community 2019* with Desktop development in C++ (if you haven't already)
2. Create a new *C++* `Console App` with the project name `knights_journey`, in a location you'll remember, for example  `c:\Users\You\Documents\torrens/ise102/week1`. Make sure you **tick the checkbox** to *Place solution and project in the same directory*. 
![](new_proj_knights_journey.png)
3. Run the project to make sure it works by hitting <kbd>ctrl</kbd>+<kbd>F5</kbd> 

### Enter The Code

1. Select and delete all the code in `knights_journey.cpp`
2. Type in the following code, including the *comment* lines starting with `//`
![KnightsJourney No Input](cpp_knightsJourney_noInput.png)
3. Run the program with <kbd>ctrl</kbd>+<kbd>F5</kbd>

## Don't Panic: Four Basic Features

People, like computers, feature *input, storage, processing and output*.

**Harvey's mum:**
  * Receives **input** via her ears, eyes and other senses
  * Her brain **stores** instructions and remembers events
  * She uses her hands and smarts to **process** the milk, moving it to a bottle and warming it
  * She **outputs** a warm bottle of milk and a kiss to Harvey.

{{< alert title="Abstractions Reduce Complexity" color="warning" >}}
When we take the (at least) thousands of components of a PC and group them into a few simple functions, we call it **abstraction**, and it's a very powerful tool.

Any complex task achieved by humans requires the use of abstractions: if we considered every object in its full complexity we'd grind to a stop!
{{< /alert >}}

Just have a think about what you're *really* describing when you say "I was thirsty until I drank some water."  There are several Nobel Prizes in chemistry, physics, neuroscience and biology in that statement if you go deep enough!

## Four Basic Features of Computers

How do we turn these pretty simple instructions into something that controls the Frankenstein of components that is a computer?? 

While there are indeed lots of instructions you could give to a computer and its many parts, happily they all fit into one of these four basic categories or features: `input`, `storage`, `processing` and `output`, 

| Features | Examples  |
|-----------|-----------|
| **Input** |  *Data* in: Keyboard, mouse, network connection, camera, microphone, touch screen, control pad  |
| **Storage** | *Data* stored: SSD, Hard drive, RAM, CD, Micro SD. |
| **Processing** | *Data* changed: Moving a character across a platform, adding two cells of a spreadsheet, decompressing video. |
| **Output** | Showing the *data*: Drawing pixels to a monitor, sending packets to a game server, sound from speakers, printing. |
---


### Discussion

* Storage via variables and assignment (`=`)
* Processing via operators (`+`)
* Output via `cout`

## As a flow chart:

![flowgorithm](flow_knightsJourney_noInput.png)

## Variables

Memory boxes. 
* A bit of memory with something in it and a label so you can find it again. 
* Those contents can be changed, can be made to vary over time. 

Instead of calling them something awkwared like variable memory boxes, call them simply **variables**

### Variable Type

The contents of a box change, but the type of contents for a particular box shouldn't change. We choose that type when we declare our variable:

```cpp
string name               = "Pedro";
int age                   = 17;
bool isClassPresident     = true;
```

## Summary

* We installed the required software
* Programming is just a list of instructions to complete a task
* A computer/person is mostly input/storage/processing/output
* You already program things, you're just learning how to apply it to a computer.
* To program you need:
    - A subject you will program(human, computer)
    - Common language 
    - An agreed place the subject can do the work (car, kitchen, *Windows Command Prompt*)
    - A list of instructions
* We made a simple game, Knights Journey, with help from 3 of our basic categories (input, storage etc)
    - Once, in *Visual Studio* with *C++*, for the *Windows Command Prompt/Console*
    - Again as a flowchart in *Flowgorithm*.

## Homework

### From The Textbook 
Read through **pages 1-12** of [Chapter 1](../resources/cpp_through_games_1.pdf) of the textbook, *Beginning C++ Through Game Programming*. This will help you understand what **variables** are, and how they represent storage. 

Then:
1. Create a Visual Studio project for called `game_over_3`, using the *console app* project type.
2. Replace the contents of `game_over_3.cpp` with the code of the **Game Over 3.0** program (pages *11,12*).  
3. Run it with the <kbd>ctrl</kbd>+<kbd>F5</kbd> hotkey, or select *Debug -> Start Without Debugging* from the menu bar.  

The textbook is also linked from the [ise102 resources page](https://dmdocs.netlify.com/torrens/ise102/resources/).  

### Knights Journey with player input 

Add input to your `knights_journey` project. The code you need to type out is below; remember to include the comments!

![input](cpp_knightsJourney_input.png)

###  What to submit

I only need the cpp file for your updated Knights Journey with input. Locate the `knights_journey.cpp` file in your project and email it to me by the deadline given in class/Discord. In your email use the subject line `ise102 homework week 1`.
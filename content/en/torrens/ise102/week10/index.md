---
title: "Week 10: Movement, Speed and Responsiveness"
linkTitle: "W.10: Movement"
weight: "100"
description: >
  Moving a character object around. Controlling speed and reacting to input.
---

## Introducing the Snake Object

Remember, last week, when I put x and y into a Point2d (cactusLocation) so we wouldn't have variables coming out our ears? We're going to keep doing that this week so it's easier to move not just locations but characters, pickups and props.

To help us start moving snakes around our game I've lumped together some things you'll need and called the data type `Snake`. If you `#include "snake.h"` and it's in your project + project directory, you can do this:

```cpp
// Make some snakes with nice names
Snake darlene;     
Snake pradeep;  

// Each Snake can have its own location, colour and current direction of movement
// (heading +1 or -1 in x, same for y)
darlene.colour = GREEN;
darlene.location.x = 5; 
darlene.location.y = 10;
darlene.xdir = 1;   // Darlene moving right (x+1)
darlene.yDir = 0;   // Darlene not moving in y

// Pradeep is same same but different.
pradeep.colour = MAGENTA;
pradeep.location.x = 20; 
pradeep.location.y = 10;
pradeep.xDir = 0;
pradeep.yDir = 0;
```

### Player character as object

A character, say an explorer, is a person. A person, while not being *just* an object, most definitely is a physical thing in the world, and like all things bigger than a quark, they too are a collection of things. Let's get a bit uber realistic and break down some of the things (physical, behavioural) that are bundled into a real life human explorer:

Type of things      | Examples
-----               | ------
Properties          | Location, appetite, level of education, state of health.
Biological objects  | Arm, eye, toenail, hair strand, kidney, contents of stomach.
Biological systems  | Musculo-skeletal frame, circulatory system, immune system
Inanimate objects   | Map, glasses, bag, plate, fork, boot, coin, lighter, knife.
Abilities           | Walk, speak, eat, blow air, see, carry, climb, swim, pick locks.
Behaviours          | Seek food, avoid physical combat, crave adventure, avoid towns.
Passengers          | Billions of bacteria, maybe a tick, some lice.

> So a human object is.. a bunch of different things that, at the moment, taken together, act like a person.

It's not just characters: the world is full of things that have properties, functionality, tendencies: a chainsaw, a capsicum plant, a supermarket, a magazine, a wind turbine, a platoon.

### Objects to make anything

Since humans are good at thinking of bunches of complicated stuff as things, it starts to feel obvious that **making programs would be way easier if we could just bundle together chunks of our code and variables into virtual things**. Cars, maps, health pickups, levels, inventory items, scoreboards, snakes. That's **objects**.

```cpp
// An imaginary large health pack of data type PickupHealth.
PickupHealth largeHealthPack1;
largeHealthPack1.restorePoints = 60;
largeHealthPack1.location = Point2d(30 ,5);
```

{{< alert title="Objects in C++" color= "secondary" >}}
Objects (and functions) let us build our programs out of things, instead of endless lines of instructions and variables. They're a data type we can design to match the properties of our game's things and from that data type we can make as many as we want.

For future reference, the design for that data type is called a ***class***.
{{< /alert >}}

## Moving

Since our Snake has a position and a colour, it can be drawn somewhere. If we add its xDir (value of -1, 0 or 1)  to it's location.x many times per second it'll appear to animate across the screen. 

The same can be done for yDir/location. Think of the x and y directions as speed in a direction - in high school we called that *velocity*, something you used in science class when calculating *force*. In games/maths we often call it a *vector*.

## TODO: ADD DIAGRAM of these four unit vectors.

### Up Down Left Right

Reference: screen space.

{{< imgcard xy_leftright_updown Link "xy_leftright_updown.jpg">}}
We can move left and right by changing a snake's location.x. Up and down with y.
{{< /imgcard >}}

## Controlling Movement

We'll use it now to move around. **Grab the base file** and help me **fill in** the missing bits from the code below.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="Snake_A3_incomplete.zip" target="_blank">Download Snake_A3_incomplete.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

{{< imgcard code_playSnake_incomplete Link "code_playSnake_incomplete.png">}}
The playSnake function, like playSlots, just handles the gameplay screen.
{{< /imgcard >}}

{{< alert title="Frame based game loop" color= "primary" >}}
The frame-based **loop during gamePlay**, at its simplest, is this:
```
do:
  get input
  simulate game world
  ouput to screen
while player hasn't quit/lost
```
{{< /alert >}}

### Demo and work along
I'll explain the codebase above, and together we'll add left-right player controlled movement.


## Homework

Moving up and down!
**Everyone** needs to complete **at least the core homework**. Advanced and the learning below is for people who want to go further.

Provide answers to questions in comments in your code inside the `playSnake()` function, at its beginning.

* _**CORE**_   
  
  1. Complete the remaining TODOs, adding up/down movement.
  2. Try changing the slithers.moveInterval to different values, see how the speed changes.  
  3. Try the same with just the FPS values. 
  4. Question: Which offers more fine-grained speed control? Why?

* _**ADVANCED**_  
  * Set slithers.moveInterval to 15. What framerate value would make snakey cross the level in approx 1.8 seconds?  

* _**DELIVERY**_
1. **Zip the solution**  like you would for an assessment submission, taking care to **delete cache folders** like Debug and x86 
  
**Danny will review**  Monday morning

<!-- 

## Speeding up Slithers

**The game is too slow**. We need to move faster, so we need a way to **define our speed**. 

Our speed can be described as a combo of frames per second and frames between moves, but can we really get a sense of that? Is it how someone would describe what they see on screen? 

### A better target

Let's pick a more relatable metric. We'll ask:

> **how long does it take to go across the level?**

As in, "The snake goes across the whole level in one second", or "it got so fast I went up and down the screen/level in like twice in a second."

Picking an arbitrary number, say we want to get across the whole level in **1.5 seconds**. How would you figure out the right fps/n frames between moves values? You already know the kind of calculation and we use it to talk about car speed. 

{{< alert title="Calculating travel time: The long Maccas Drive" color= "primary" >}}
Your friend wants to go to his favourite maccas, but it's **100km** away. It's also through suburbia, so it's **50kph** the whole way. Cool, but you need to eat **within three hours**. _Will you get there in time?_

You probably did that in your head almost without thinking. The formula you used was:

$$time = {distance \over speed}$$

which is basically **kilometers per hour = speed** remixed to **hours = kilometers / speed**.

To check our answer, lets plug the $distance$ (100km) and the $speed$ (50kph)

$$time = {100 \over 50} = 2hrs$$

Only 2 hours to Newcastle Maccas, let's go.
{{< /alert >}}

### Applied to our game

The **distance** across our level is **35 pixels**, because that's what I set as the **`LEVEL_WIDTH`**

{{< imgcard code_screen_width>}}
Defining a screen width constant, using it when we create the console window.
{{< /imgcard >}}

**Slithers speed** is currently `10` pixels per second, because we wait 10 frames between moves and.. 

{{< imgcard code_snake_move >}}
Counting down frames till the snake moves, then resetting and counting down again.
{{< /imgcard >}}

*we set the frames per second** (`fps`) to 100 playSnake.

{{< imgcard code_snake_fps>}}
{{< /imgcard >}}

#### Plugging the values in:
Lets plug it distance = 35 and speed = 10 (both using "pixels")

$$time = {35 \over 10} = 3.5sec$$

> **3.5 seconds** just to cross the level once is slooow. 
> **What speed** would we need to do it in **1.5 seconds**?

#### Speed = distance over time

By moving the formula around we can get speed. Plug in **1.5 seconds** for $time$ and **35 pixels** for $distance$:

$$speed = {distance \over time} = {35 \over 1.5} = 23.\dot{3}pps$$

> We know we need about **23 pixels per second** but how do we get there??

### Increasing pixels per second

We could **moving more** than one pixel **each move**, but not only does it look buggy (skipping whole text pixels) but it's not very accurate:

| MOVE DIST | MOVES | SPEED |
|----- |----- |------ |
| 1 pixel  | 10 | 10 pps |
| 2 pixels | 10 | 20 pps |
| 3 pixels | 10 | 30 pps |

What if we move **more often**?

| MOVE DIST | MOVES | SPEED |
|----- |----- |------ |
| 1 pixel  | 11 | 11 pps |
| 1 pixels | 12 | 12 pps |
| 1 pixels | 12 | 12 pps |
| ... | ... | ... |
| 1 pixels | 23 | 23 pps |

### Move more often with `setFps(int fps);`

1. Scroll to the `playSnake` function 
2. Change the value we're passing to `the textpixels::setFps` to **23**. 
3. Change `slithers.moveIntervald` to 1, so we move every frame.
3. Try it out, see what it's like to cross the screen in about 1.5 seconds.

{{< imgcard code_snake_fps>}}
Setting fps in `playSnake()`
{{< /imgcard >}}

## Looks Good Feels Bad: Responsiveness

It looks better.. but if you try to turn fast you'll notice it sometimes misses it.

{{< alert title="Textpixels is asleep!" color= "danger" >}}

How does _textpixels_ lock the framerate to 23? By **sleeping** (telling the operating system to go and run other programs) until you need it to draw another frame. 

The problem is it only takes about **1/1000th of a second to draw a frame**.  It **totally misses keyboard inputs** because it's asleep about 98.5% of the time.

{{< /alert >}}

We need to **drastically increase the time our game is awake**, and one easy way to do it is:
> Increase the framerate to maybe.. 200fps?

### Lazy moving

An insane frame rate gives us insane speeds: 200 fps produces a **speed of 200pps**:

$$time = {distance \over speed} = {35 \over 200} = 0.175sec$$

Crossing the screen in 0.175 seconds is a problem for humans. We blink, for a start.

> We can keep our app awake and checking for inputs 200 times a second, but be **lazier about moving and drawing the snake.. maybe once every 15 frames**

### Method 1: counting.

1. Declare a constant for the number of frames we wait to move.
2. Declare a variable to count down, then copy the constant value (we just made one) into it. This has to be declared outside the loop or it'll be reset every iteration.
3. Count down by 1 each frame, assuming it hasn't hit zero.
4. Move the snake according to its speed when the countdown reaches 0
5. Set it back to the value in our frames-to-wait constant.
6. Goto instruction _2_.

### Method 2: our old friend modulus **`%`**

With modulus we can measure intervals easily. If you counted up from 0, dividing each number by 3 the remainders are 0,1,2,0,1,2.. to infinity.

{{< imgproc code_modulus3_loop_1 Resize "700x" Link "code_modulus3_loop_1.png" >}}
Printing the remainder of i divided by 3 (integer math) for every value of i.
{{< /imgproc >}}

So if we only print something every time the remainder is 0, it runs every.. ?th loop. You tell me.

{{< imgproc code_modulus3_loop_2 Resize "700x" Link "code_modulus3_loop_2.png" >}}
If 3 divides evenly into i, then the remainder is 0. So i % 3 is 0. Alternately, why not run only when the remainder is 2, or 1?
{{< /imgproc >}}

Modulus is great at doing things at various loop intervals: drawing even numbered columns a different colour in your tables, triggering a catapult every 20 seconds, etc.

{{< alert title="You gotta know integer division" color= "primary" >}}
If you don't understand **Integer Division** and **remainders**, it's officially on _you_ now. Go study it, **get it locked down**. It's taught in primary school so it was definitely a long time ago (less for you), but it's very easy to re-learn. 

Look it up on wikipedia, call your maths teacher, whatever, but DO IT NOW. 
{{< /alert >}}

--> 

> Programmers don't say "I don't know", they say **"I don't know _yet_."** 👍
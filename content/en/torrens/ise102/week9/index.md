---
title: "9: Drawing In The Console"
linkTitle: "W.9 Drawing"
weight: 90
description: >
  Going beyond text-entry mode, to drawing pictures with fonts.
resources:
  - src: "screen_refresh*"
    params:
      byline: "Original images: https://api.ed2go.com/CourseBuilder/2.0/images/resources/prod/ac3-1/CRT_Monitors.html"
---

## What are we learning today?

* Making frame based games: drawing the screen _30, 60 times a second_ (or more).
* Drawing the the terminal, like it was a bitmap, but using text symbols!

![snake huge pixels](snake_huge_pixels.png)

## Slots
* Thanks for submissions

<!--  
* Check Blackboard. Some people submitted the wrong files and I've messaged you about resubmitting. Each day costs marks so act now.
* I haven't looked at the code yet, just that the file structure looked right.
-->  

## Beyond Text Entry Mode

We've been making games in an environment like a chat, or a left-justified text document. 

### Input and Storage

* We can listen for input from a keyboard
* People can type in characters, digits, sentences
* Once they hit enter, we can store that data

### Drawing 

* We have symbols!
* We can space stuff out.. from the top or left.
![slots 1](output_slots_skeleton_1.png)

* We have colours!
![termcolor menu](output_termcolor_menu.jpg)

### Limitations

One major thing stands out as missing from our console/terminal games: the ability to draw to arbitrary locations. Well, we could afford a larger character set too.

#### Drawing Anywhere

We're really limited in **where we can place things** on screen. 

**Text symbols are** actually **not bad** for drawing graphics
- you can represent a lot with colour and symbols. 
- Buuut **we have to stack them** up from the left of the screen, line by line
- We can't change things we've drawn, except to clear the screen try again.

When you look at htop (like windows task manager) running in a console, it becomes obvious that the command prompt is just a grid of characters.

{{< imgcard console_htop_grid >}}
Rows and columns become obvious
{{< /imgcard >}}

{{< imgcard "far-manager_windows_5" >}}
Far manager takes it further, using colours and special characters to give the impression of windows and menus with shadows.
{{< /imgcard >}}

If you can draw a character in any colour ot any part of the screen **directly with x,y coordinates** you could do stuff like this without thinking about newline or tabbing across:
{{< imgcard pro_football_fairchild_channel_f >}}
Games on early consoles like the Fairchild Channel F are close to text mode but would be painful to make and play with our current method.
{{< /imgcard >}}

{{< imgcard textmode_2000 >}}
Textmode 2000
{{< /imgcard >}}

{{< imgcard zzt >}}
ZZT
{{< /imgcard >}}

{{< imgcard snake_huge_pixels >}}
We could make something like this more easily.
{{< /imgcard >}}

## Solution: TextPixels

I'll give you a Visual Studio solution today with a library that draws coloured unicode text characters anywhere in the console. 

* It is effectively like changing big pixels on a low resolution screen
* It can move to and draw at any x,y coordinate in any sequence
    * no left to right, no tabs `\t` or spaces or newlines `\n` needed.
* If you picture the command prompt completely full of text, like a find a word puzzle, those are our text pixels.

{{< imgcard output_console_drawing >}}
Some of the drawing routines in TextPixels demonstrated
{{< /imgcard >}}

### Drawing To Screen Coordinates

As you know, a computer screen is a big grid of pixels. Every time that grid is updated, that's one frame of your game, or 1 hz (hertz).

Before LCDs computer monitors were, like televisions, cathode ray tubes. The shot a beam of electrons at the pixels to change their colour, and they only had one beam, so they had to sweep the screen pixel by pixel.

{{< imgcard screen_refresh_combined Link "https://api.ed2go.com/CourseBuilder/2.0/images/resources/prod/ac3-1/CRT_Monitors.html" >}}
As you can see, the beam swept from top left to top right, and continued down the screen row by row.
{{< /imgcard >}}

When you draw to a screen in code we use the same coordinates, and textpixel uses this system as well.

{{< imgproc arduino_oled Resize "500x">}}
A tiny arduino screen
{{< /imgproc >}}

{{< imgcard screen_coords_3_mini_lcd >}}
Coordinates on a tiny arduino screen
{{< /imgcard >}}

{{< imgcard screen_coords_4_pixels >}}
Pixels at x,y coordinates
{{< /imgcard >}}

{{< imgcard fillRect_width_height >}}
Drawing a filled rectangle on a screen
{{< /imgcard >}}

### Character Set

Our projects so far have been limited to the basic 128 character set, which doesn't get you much more than what is on your keyboard. **TextPixels uses unicode,** which gives us handy stuff like the "box drawing" characters and pixels with different fills:

{{< imgcard unicode_box_drawing_characters Link "https://en.wikipedia.org/wiki/Box-drawing_character">}}
Click for the Wikipeda page
{{< /imgcard >}}

We'll get into how to use more of those later, but to get started we'll have **access to the solid pixel** with `drawPixel(x,y)`

### Download The Example

[Console_Drawing_w9.zip](Console_Drawing_w9.zip) (Updated with loop in demo function, additions to textpixels)
**Updated W10 T4 2021**

We'll treat the characters on screen as giant pixels. Using the TextPixels library, they'll be made square.

**Load and run** the code. Examine the code provided for:

 * drawing single pixels
 * drawing a string
 * int to string conversion
 * filling a row with a character
 * filling a row with a 16bit unicode character (64,000 possibilities vs 256)
 * checking if a key is held down
 * Showing fps

![console drawing](output_console_drawing.png)

Here's a look at some of the `textpixels` function calls in the demo

![showGraphicsDemo_full](showGraphicsDemo_full.png)

## The top level: a new game loop 

There's a fair bit even in that small function, so let's just look at the very top level: how it loops and what it wants to do each frame. Here it is without the drawing/output bits:

![showGraphicsDemo base](showGraphicsDemo_base.png) 

In our old chat-bot style loop, the player was asked something and the program loop hung until they entered something.

1. The program tells player something, prompts them for input, waits.
2. Player inputs something, program processes that input, then loops back to 1.

We don't wait for user input now, we check on it as we zoom past 30 or more times per second.. 

<!-- 

```cpp
void showGraphicsDemo()
{
  bool playerHasQuit = false; // set up variables that persist

  // Constantly loop while player hasn't quit the screen. By default this loop runs
  // 30 times per second. If we draw every loop, we're drawing at 30fps (or 30hz)
  do
  {
    textpixels::startFrame();   // Tell txtPixels we're doing things for this frame
    //!----- DO EVERYTHING FOR THIS FRAME - input, processing, output via draw functions --
    textpixels::endFrame();  // Tell texpixels we're done so it can batch draw to screen
  } while (playerHasQuit == false);     // Only stop when playerHasQuit
  return;
}
```
-->

### Frames Per Second

To make a bunch of drawings look like one drawing moving (animation) you have to clear and draw the screen quickly: a cinema projector shows a new frame on 24 times per second. A console game until fairly recently aimed for a minimum of 30fps, and PC games go for a more agressive 60 fps base, with some players aiming for 144 or higher to match their 144hz (screen draws per second). How long do these frames actually last for? 

| FPS                        | Time (milliseconds*) per frame     |
|--------                    |-----------------------------------|
| **30** (console)           | 1000/30  = **33.3ms**             | 
| **60** (most monitors)     | 1000/60  = **16.6ms**             | 
| **144** (gaming monitor)   | 1000/144 = **6.9ms**              | 
*\* There are 1000 milliseconds in a second*

### Our Old Game Loop

Here's our old game loop, simplified, in pseudocode:

```
while (player hasn't quit)
  Display something (output), prompt player for input
  Wait for input.......
  store/process input.
end while
```
Basically the loop was *output, input, processing*

### Animated Game Loop

We can't just leave output on the screen for as long as the player takes to react. Things have to move! At 60fps!

Here's the game loop most commonly used in *frame-based* games, as opposed to prompt-response games:

```
while (player hasn't quit)
  input: check for and remember input
  processing: update state of all things in game
  output:  draw graphics to screen
end while
```

**input, processing, output**, loop. Storage, or memory/variables, are present throughout the whole thing.

## Exercise

Read the code and comments carefully. Hover over function names for an explanation of what they do.

1. Change the `O` that's drawn across the row to something else.
2. Make the line go from top to bottom (y) instead of across (x).
3. Change the foreground and background colour of the line
4. Change the border colour of the demo.

{{< imgcard exercise1_by_waleed >}}
Exercise 1 complete, by Waleed.
{{< /imgcard >}}

## The Point2d type 

Point2d is a special data type I've made to work with textpixels. It holds a pair of x and y coordinates. If you were trying to remember the spot where you left a cactus, you could make a `Point2d` variable called `cactusSpot`, then set its x and y values.

```cpp
Point2d cactusSpot;
cactusSpot.x = 3;
cactusSpot.y = 10;

drawPixel(cactusSpot.x, cactusSpot.y, DARK_GREEN);
```

There's even a version of drawPixel that can take a single Point2d variable instead of needing two ints:


```cpp
Point2d cactusSpot;
cactusSpot.x = 3;
cactusSpot.y = 10;

drawPixel(cactusSpot, DARK_GREEN);
```

{{< alert title="A box of variables" color= "primary" >}}
If you think of an int or float variable as a box of memory with a value in it (`int age = 2;`), then you can think of any Point2d variable as a *box with two other boxes in it*; the x and y coordinates of the point. They're just a couple of `int`s. 

```cpp
cout << cactusSpot.x;  // print out the x coordinate of our cactus.
```

To check or change (read or write) those variables you can use *dot notation* like above. You just type the variable name, put a dot at the end, and see what it offers.
{{< /alert >}}

Just like two colons `::` gave you access to things inside a namespace/library or enum, a dot `.` gives you access to things inside an *object*. 

## Objects

Data types like the Point2D aren't like the fundamental types (int, float, double) They create data *objects*. That just means they are like a package, rather than a single, simple box in memory - they can hold multiple variables and even functions.

It turns out `string` has quietly been an object the whole time. It lets you access it with `=` like it's the other data types, but it has a lot of handy functions you can use too. 

You can find out how long a string called `name` is by calling `name.length();`. 

```cpp 
string myName = "Geena Baneena";
int nameLength = myName.length();
```

The function exists inside that one string object and when called, will always give you up to date information - if you assign a new name to `myName`, say `"Princess Sharma Fishsauce"` then `myName.length()` will give you a different answer.

Here's more about string's `length()` function on cplusplus: <https://www.cplusplus.com/reference/string/string/length/>

<!-- TODO: Textbook homework on objects? --> 

{{< alert title="Definition: Member Function" color= "primary" >}}
A function that you can call inside an object is often called a *member function* or a *method* of that object. Just calling it *function* is still fine, it's just less specific.
{{< /alert >}}

### Homework 

There are 5 tasks to complete at the top of the Console_Drawing's main.cpp file. Complete them and email me the cleaned, zipped solution.


<!-- TODO TRI 2 add more with point2D

, including  having the 


Type a letter to change the colour of a letter in a string?
Type in the start index of a substring to turn the start grey?
Shows animation, which is useful.


-->  

<!--  OLD
### Pixels

A grid. 

Starts top left, ends bottom right. Need a graphic.

5 cells by 5 cells:

0 1 2 3 4  
1 1 2 3 4  
2 2 2 3 4  
3 3 3 3 4  
4 4 4 4 4  

Notice something very important: it starts at 0! Drawing last cell of screen is 4,4.
-->
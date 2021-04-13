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

* Drawing in the console like it was a grid of large pixels, (but using text symbols)
* Making fluid, frame based games: drawing the screen *30, 60 or more times a second*
* How to use *objects*, powerful new data types.

![snake huge pixels](snake_huge_pixels.png)

## Slots
* Thanks for submissions! Marking will be happening over the next two weeks.

## Beyond left-justified text
The console's natural tendency is to start at the top left, and output along the line until we feed it `endl` or `"\n"`, or a player hits <kbd>enter</kbd>. Still, even with that limit, symbols and colour can do a lot; with careful use of tabs and spaces people can make some pretty sweet interfaces.

But what could we do if we could draw anywhere we want, in a grid?

### Big-pixel games

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

### First, we need a grid
It turns out the console is based on a grid. It's pretty obvious when you type in dir and the columns line up. Now when you look at htop (like windows task manager) running in a linux console, it gets really obvious.

{{< imgcard console_htop_grid >}}
Rows and columns give us tables, structure!
{{< /imgcard >}}

{{< imgcard "far-manager_windows_5" >}}
Far manager takes it further, using colours and special characters to give the impression of windows and menus with shadows.
{{< /imgcard >}}

### Drawing to any pixel

For that we need a special mode in the Windows console, and it's too complicated to go into. Still, there's good news: I'll give you a project today that contains **TextPixels**, a library that draws coloured pixels and text/symbols anywhere we like in the console.

{{< imgcard output_console_drawing >}}
A work of art produced in TextPixels.
{{< /imgcard >}}

### Download The Example

[Console_Drawing_w9.zip](https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/EXeQmzvBHRpAkKyVPNiAq8MBx_PKYGbcC3gUe6Us9QoOcQ?e=yFqN1n) (Updated with loop in demo function, additions to textpixels)

**Load and run** the code. Examine the code provided for:

 * drawing single pixels
 * drawing a string
 * int to string conversion
 * filling a row with a character
 * filling a row with a 16bit unicode character (64,000 possibilities vs 256)
 * checking if a key is held down
 * Showing fps

Here's a look at some of the `textpixels` function calls in the demo

![showGraphicsDemo_full](showGraphicsDemo_full.png)

## Drawing To Screen Coordinates

It's pretty easy to see how drawPixel and fillRect are meant to work, but how do those numbers map to the actual locations in the console? You really want to know the details when you start doing things like drawing all the way across or down the screen, or one to stop shy of a border, like in our drawLines function:

![drawLines function](drawLines.png)

Spreadsheets have their column-letter and row-number system, crosswords have their "5 down" and "10 across" system. For games we use *screen coordinates*, which start at the top left, at `0,0`, but that's not going to stick in your mind without some background and some pictures.

### The screen
As you know, or don't know, a computer screen is a **big grid of pixels**. Every time that grid is updated, that's one frame of your game, or 1 hz (hertz).

Before LCD screens our computer monitors were, like televisions, made with [*cathode ray tubes*](https://en.wikipedia.org/wiki/Cathode-ray_tube). The shot a beam of electrons at the pixels to change their colour, and they only had one beam, so they had to sweep the screen pixel by pixel.

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

## Exercise

Read the code and comments carefully. Hover over function names for an explanation of what they do.

1. Change the `O` that's drawn across the row to something else.
2. Make the line go from top to bottom (y) instead of across (x).
3. Change the foreground and background colour of the line
4. Change the border colour of the demo.

{{< imgcard exercise1_by_waleed >}}
Exercise 1 complete, by Waleed.
{{< /imgcard >}}

## The top level: a new game loop 

It's great that we have functions like drawPixel and fillRect, but what happened to cin and cout? How's it getting input if the loop never stops? How can any of this work? **Let's look first** at the most important change to our program: enclosing that drawing code is a new paradigm, the ***frame-based game loop***:

![showGraphicsDemo base](showGraphicsDemo_base.png) 

### Frame based games!

Our slot machine hung on user input, only processing or drawing if we hit a key or typed in an answer. Our new game will be like most real games you play: they keep animating and changing whether or not you move your mouse/touch the game pad. 

![nap time](https://gameprogrammingpatterns.com/images/game-loop-simple.png)

This new loop doesn't wait for user input now, it zooms by at 30 or more times per second whether you're ready or not. In the heart of each loop we're given a brief moment to do our work before it furiously redraws the screen, falls into a milliseconds-long hibernation, then wakes up to do it all again. 

### Go deeper: Frames Per Second

To make a bunch of drawings look like one drawing moving (animation) you have to clear and draw the screen quickly: a cinema projector shows a new frame on 24 times per second. A console game until fairly recently aimed for a minimum of 30fps, and PC games go for a more agressive 60 fps base, with some players aiming for 144 or higher to match their 144hz (screen draws per second). How long do these frames actually last for? 

| FPS                        | Time (milliseconds*) per frame     |
|--------                    |-----------------------------------|
| **30** (console)           | 1000/30  = **33.3ms**             | 
| **60** (most monitors)     | 1000/60  = **16.6ms**             | 
| **144** (gaming monitor)   | 1000/144 = **6.9ms**              | 
*\* There are 1000 milliseconds in a second*

### If you've forgotten: our old Game Loop

Here's our old, [input-dependent game loop](https://gameprogrammingpatterns.com/game-loop.html#interview-with-a-cpu), simplified, in pseudocode:

```
while (player hasn't quit)
  Display something (output), prompt player for input
  Wait for input.......
  store/process input.
end while
```
Basically the loop was *output, input, processing*

### Animated Game Loop

We can't just leave output on the screen for as long as the player takes to react. Things have to move! Remember our tiny window of opportunity, a few millseconds each loop? **It's up to us to use that moment to** 
1. check the state of the keyboard/mouse/controller,
2. make all our changes to our character, the world, run enemy ai, figure out the win/loss state of the game etc etc, then
3. Draw pictures and words on our screen to explain the new reality to the player and the other end of this tiny slice of time.

Here's the [game loop](https://en.wikipedia.org/wiki/Video_game_programming#Game_structure) most commonly used in *frame-based* games, as opposed to prompt-response games:

```
while (player hasn't quit)
  input: check for and remember input
  processing: update state of all things in game
  output:  draw graphics to screen
end while
```
**input, processing, output**, loop. Storage, or memory/variables, are present throughout the whole thing.

### The game loop roughly applied in showGraphicsDemo

Now compare that pseudocode loop to the base of showGraphicsDemo, and you'll see these three stages (input/ouput/processing) would all go between `textPixels::startFrame()` and `textPixels::endFrame()`.  

![](showGraphicsDemo_base.png)

What we actually do in the demo file, as you can see below, is mostly **output**, with one tiny check of the **input** to show the frames per second. 

The input is a little out of place, but for this simple demo which has no actual game state, it's much simpler to understand.

![](showGraphicsDemo_full.png)

{{< alert title="What do startFrame() and endFrame() do?" color= "primary" >}}
These two calls do handy things like:

1. Measuring the time your code takes to execute in each frame
2. Figuring out how long to sleep the program between frames so that it'll draw the requested number of frames per second
3. Controls the console so that it draws everything you requested in one pass, avoiding flickering and slowdown.

![nap time](https://gameprogrammingpatterns.com/images/game-loop-simple.png)
[Read more at gameprogrammingpatterns.com](https://gameprogrammingpatterns.com/game-loop.html#a-world-out-of-time) about the game loop programming pattern and what's going on if our game isn't just running as fast as it possibly can (4000fps anyone)?
{{< /alert >}}



## A new, custom data type: Point2d

Point2d is a special data type I've made to help us build games in textpixels. It holds a pair of x and y coordinates, locating a thing in a 2d space.. like our game window. If you wanted to remember where you left a cactus, you could make a `Point2d` variable called `cactusLocation`, then set its x and y values.

```cpp
Point2d cactusLocation;
cactusSpot.x = 3;
cactusSpot.y = 10;

drawPixel(cactusLocation.x, cactusLocation.y, DARK_GREEN);
```

There's even a version of drawPixel that can take a single Point2d variable instead of needing two ints:


```cpp
Point2d cactusLocation;
cactusLocation.x = 3;
cactusLocation.y = 10;

drawPixel(cactusLocation, DARK_GREEN);
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
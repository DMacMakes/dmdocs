---
title: "Week 12: Snakes And Collections"
linkTitle: "W.12: Snakes"
weight: "120"
description: >
  How would a segmented snake work? How can I store all those segments?
---

## Assessments Marked

1. All results should be visible on Blackboard.
2. How marks accumulate, or "can I still pass?"
   - Fail, Pass, Credit, Distinction, High Distinction
   - F is not 0, it's <50. It still contributes to your overall mark.


### Trello

Not sure what's left to do? Check the [Snake_A3 Trello](https://trello.com/b/aVYKZSK8/snakea3).

{{< imgproc snake_trello Resize "650x" Link "https://trello.com/b/aVYKZSK8/snakea3" >}}
Click image to visit the Trello
{{< /imgproc >}}

### Build On The Base

A few people had this issue in the Slots assessment, and typically do if they haven't followed the streaming classes.

We **won't be marking any old Snake code that's submitted**: you need to be attending or watching streams, and demonstrating what you've learned. That means your Snake game is **built on the provided base** code and uses *textpixels*.

### Submitting your files correctly

Watch the review video again if you're not sure.
<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://au-lti.bbcollab.com/recording/657bbe01394d4c7fb991a6e85dc46314" target="_blank">Cleaning up and zipping your project<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>


<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://au-lti.bbcollab.com/recording/631e6bb1ef6a46b6ae6263451a14d097" target="_blank">Testing your zipped project<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>
### A3 Required: Do More Than The Minimum

The brief says the Snake game is a base. It rewards building new things, added settings and features. When your tinker with it, when you flex a little.. we know you really understand it.

* Go through rubric
* Extra features! Things you can run into that change the game, difficulty settings, extra lives, best score recorded to disk.
* Do more than the minimum! 
* Don’t just do exactly as i do visually. You could:
  * Change the window dimensions (`setupWindow(50,25)`)
  * Have a double-thick wall
  * What can you display in unicode? Can you make the background or snake more interesting?
* Use the gui to provide any info you want
  * different fruit types what they give you
  * Hints
  * Your previous best score
  * tell them how disappointing they are.
* Action replay of the last 10 seconds?
* Multiple game modes
* Top 3 scores saved to disk and reopened each time app opens


## State, and How To Wait Without Sleep

Some of you may have tried using sleep() in the `playSnake()` loop and discovered it isn't going to fly in a frame based application. Things need to keep happening, like Snakes slithering and keyboard input being checked.

This requires an understanding of the *state* of the game, and why I'm focussed more on you delivering game modes, pause/game over screens, the full experience. Making a snake grow and wiggle is tricky, but it's more of a localised problem, an algorithm, it's on the detailed end of our problem solving. 

One word: state. What state is your program in? What screen are we on? Are we mid game, are we about to fight a boss? 

"Play again" is a good example from the Slots assessment, and is a challenge again here. If we show a game over message and loop back to the start of the game, what state have we left our variables in? Is the game still running as fast as it did after eating 30 fruit, or a haste fruit? How do we get it all back to the starting state. 

> To react to these changes of state, we have to know what they encompass, and what one we're in! It's that high level abstract thinking we need to get back to all the time, keeping our brain in the problem space rather than the code.
### No Sleep()

Demo of **Waiting** solution.

 ## State



## A growing snake

Try the segmented, growing snake in `4_snake_insert_erase.exe` from the zip below:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="week12_executables.zip" target="_blank">Download week12_executables.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

> Q: How did I stop drawing?  
> A: HMMM. How _did_ I stop drawing?

### Break it down

How can we change our `Snake` so that:
* it has body segments as well as the existing head pixel.
* the segments of the body follow the head as if on rails - no corner cutting
* the snake can grow in length 

There are _many_ ways to make our Snake, but with limited time left I've picked one to dive into.

## Idea: Snake as history

The Snake's body, when you think of it, is sort of a history of places the Snake has recently visited.

Think of footprints as you walk on sand, or in the snow. Which prints are nearest? Furthest? We naturally describe them in terms of time. The most recent is  one behind it is slightly older and so on.

{{< imgcard bears_alan_watson >}}
Which prints here are most recent?
{{< /imgcard >}}

{{< imgcard paws_circles >}}
What do you know about the concrete when these paw prints were made? Think outside the circle.
{{< /imgcard >}}

**Bear prints answer:** The ones under their feet <img src="pausechamp.png" width=40 height=40 />

Sadly we don't have the help of a medium like snow or cement that will do the work for us. Our old locations are lost as soon as we move. We need an another analogy maybe?

## _Geotagged_ photos
If you're travelling and take a bunch of photos, you can leave geotagging turned on (common phone feature) and it'll save location data (gps) in your photos. When you upload them, some services will read that info. You can use it to draw a path of your travel over time, like a visual travelog of your journey. 

{{< imgproc geotag_map Resize "700x">}}
Path of a walk in Tbilisi showing locations from photo metadata 
(look up pic2map){{< /imgproc >}}

If you out it's a snake with your current location (if you upload a photo today) as the head.

### Application: building our snake's travel blog

{{< imgcard slithers_notrail_trail >}}
Slithers with a trail. Can we do it with our own kinda x,y geotags?
{{< /imgcard >}}

Our game needs to clear the screen every frame so it can draw the current state of things. This erases our footprints in the sand, so to speak, from the screen. So we don't get the free visual history that the beach gives us. 

We need our history captured and stored somewhere, just like when we take photos and upload them to the cloud. If we capture our snake locations as we move around the garden, there's a history. **Draw that history** and you'll have a snake that goes all the way back to your starting point!

{{< alert title="Big programmers now" color= "primary" >}}
<img src="big_baby_bird.jpg" width=200 />
I'll be getting you started on this, but after that you'll have to fly on your own: putting together the code and ideas into a working snake is up to you. 
{{< /alert >}}

### Planning our solution

  
1. **Input:**  
   - Make a variable in our snake that can store our past locations, our history.  
   
2. **Processing:**   
   - Every time we are going to move to a new location, add our current location to the history  

3. **Output:** 
   - Every time we go to draw the Snake's current location (with DrawPixel), go through our travel history and draw all of those too.  

{{< imgproc screen_snake_history_insert Resize "600x" >}}
Drawing snake head, then the snake history in alternating colours.  
{{< /imgproc >}}


<!--

### Exercise 1: Starting With 1

Slithers has one location, but we need many. Make another location in your Snake class (`snake.h`) called `lastLocation`. 

1. Every frame, **before** we move slithers, store (assign) her location in lastLocation.
2. Then move slithers (we already do this by updating her location)
3. When you draw a pixel at `slithers.location`, draw another pixel at her `lastLocation`.

## More than 1 segment

Keeping a single location (lastLocation) gave us one frame of history, one segment of snake body. That was just one snapshot.

To get the rest you just need a collection of previous locations. 

Two ways to store collections of things in C++ are
1. Declaring an `array`
2. Declaring a `std::vector`. 

Arrays are very basic, static things that don't grow and don't offer any tools to us. I suggest using `std::vector`, because they're super flexible, easier and safer to use, and not noticeably slower for our simple game. 

-->  

<!--  

{{< imgcard snapshots_onionskin>}}
Leaving snapshots behind
{{< /imgcard >}}

oldSlithers is just one snapshot of slithers past, being taken over and over again.
What if, instead, we had a bunch of snapshots, and instead of updating them we just take new ones. When slithers is about to move, take a snapshot and leave it there.


PREVIOUSLY COMMENTED
> slithers0, slithers1, slithers2, slithers3..

What about all those damn variables though? Do you have to make like 100, 1000 variables to store them? How do you even make new variables at run time? Hell, we don't even need all the names. Just slithers0, 1, 2, 3.

--> 

<!-- 

## Storing History In Collections

 You need a collection of past locations you can access with a single name (history, travelog?) and a number or `index`.

{{< alert title="Indexed Collections" color= "primary" >}}
 A gallery contains lots of precious and small items. When you visit with your family then, you're not surprised that they don't want people taking in bags: they ask you to leave yours with security in the `bag check`. It's full of all different sizes and shapes of bags, and when they take yours they assign it a number, 104, so they can find it again.
 
 When you've had your walk around the gallery you return and fish out the piece of paper reading "Bag Check" with your bag's assigned number. Without needing any sort of description, they find and return your bag.
 {{< /alert >}}


## Collections: The vector
A vector object can hold any number of a chosen data type(int, float, string, Bag, Creature, Fruit). Then you can read or write individual values in the collection using an index.

-->  

## Declaring a vector of stuff:
```cpp
  // We declare a vector type, then the type it contains, and give it a name.
  vector<int> scores;
  vector<string> studentNames;
  vector<float> heights;  // in metres
  
  // versus a single one of those things
  int score;
  string studentName;
  float preciseDistance;
```

`vector<Point2d> locationHistory`, does that sound useful to anyone?

### Initialising vectors 

You can initialise a vector's first _n_ entries (as in create your `vector` with a few things already in there) using _set notation_, which you learned about in high school maths (and maths 1 here at uni)
```cpp
  vector<int> scores = { 25, 2, 108, 60 };
  vector<string> studentNames = { "Miles Morales", "Chen Guo", "Gwanda Stacey" };
```
Here are some [vector initialisation techniques on Geeks For Geeks](https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/), which is a) helpful and b) a fun rabbit hole maybe? We all love listicles. 

We're only using very basic set notation (a list of values or objects) but here's [a reminder on Wikipedia](https://en.wikipedia.org/wiki/Set-builder_notation). 

### Adding things to vectors

New entries can be added with `push_back()`: 
```cpp
  studentNames.push_back("Another name");`
```

{{< alert title="Accessing Entries With Array Notation" color= "primary" >}}
To access the first score in the scores collection, use `scores[0]`. For the second use `scores[1]`.

Critically, `scores[0]` behaves just like a single variable name, like `scores0` would. You can assign to it, use it in expressions.
```cpp
scores[0] = 22;
scores[0] = garysScore;
int secondScore = scores[1];
int scoreBuffed = scores[2] + 20;
```
{{< /alert >}}
Note: array access notation

{{< imgcard diagram_snake_move_insert_erase Link "diagram_snake_move_insert_erase.png">}}
Step by step.
{{< /imgcard >}}

## Drawing a snake, not our entire history

Our snake isn't a trail all the way back to our origin. Each frame, we'll have to limit how many old locations we draw. Where's the cut off point? What property of a `Snake` might tell us how _long_ a `Snake` is?

### Drawing a snake using history.

Steps       | Details
---------------- | ---
1\. Snake history archive | Create an empty history collection in our snake ( vector of Point2d locations )
2\. Snake length | Give our snake a length variable that we can add to when they eat (or other scenarios)
3\. Storing locations | Just before we execute a snake move, push a copy of our current location into the history collection. (depending on your approach you can push it on the back or insert it at the front).
4\. Drawing long snake | Draw that location history after (or before)  drawing our snake's head. **A** Only draw enough of our history to represent our snake's full length and **B** head will be one pixel, then draw length - 1 (for head) - 1(for count from zero math) bits of 4. snake. That's  *head and length-2 bits of snake history.*

### Snake length 

What variable does our `snake.h` need, then? 
1. **Add it** to `snake.h`, initialise it somewhere (before the play loop), then make sure you respect it in your body-drawing loop. 

### Growing a `Snake`:

When you eat a fruit, you become longer. So make Slither's length longer.

### Snipping a `Snake`
If you don't want to keep every location your snake ever visited you can always throw some away, provided you used `std::vector` to store them. 

## Useful `std::vector` functions

Google them, they're your tools now.
    * vector::insert(), vector::erase(), vector.append().
    * vector::front(), vector::back()
    * vector::begin(), vector::end()

## Vector help:
* Geeks for geeks: https://www.geeksforgeeks.org/vector-in-cpp-stl/
* Edureka: https://www.edureka.co/blog/vectors-in-cpp/
* Technical reference: http://www.cplusplus.com/reference/vector/vector/

## Tips for good marks in Assessment 3

### CLARITY

{{< alert title="The Golden Rule" color= "primary" >}}
A player should never have to guess what happened.

If they hit a rotten fruit, you have to make clear it was rotten fruit, and what penalty was paid.
  - Changing the border to display "ROTTEN APPLE: -3 SCORE" for 2 seconds is one possible way.
  - You could tutorialise it a bit by pausing the game for 2 seconds the first time it happens, so they def read the message.
  - Have your fruit types and effects in the gui in the first place!
If the they hit a poison fruit or deadly wall, tell them why the game ended.
  - Game over popover: "You ate a poison fuit, they kill!" Use your own words though.
  
{{< /alert >}}

## Colliding with your own body

A snake's body is just a list of locations. How can we check, each frame, if slithers' head (`slithers.location`) is on the same pixel as one of her body parts? You've already done it for a `strawberry` or `banana`, so do the same for the old locations. 
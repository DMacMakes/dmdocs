---
title: "Week 12: Snakes And Collections"
linkTitle: "W.12: Snakes"
weight: "120"
description: >
  How would a segmented snake work? How can I store all those segments?
---

## Homework:
Collisions: Fruit eating, score updating, wall hitting, options etc.

## Reminders:

### Trello

Not sure what's left to do? Check the [Snake_A3 Trello](https://trello.com/b/aVYKZSK8/snakea3).

{{< imgproc snake_trello Resize "650x" Link "https://trello.com/b/aVYKZSK8/snakea3" >}}
Click image to visit the Trello
{{< /imgproc >}}

### Submitting your files correctly

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://dmdocs.netlify.app/torrens/ise102/assessments/#deliverable" target="_blank">Cleaning up and zipping your project<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## A growing snake

How can we change our `Snake` so that:
* it has body segments as well as the existing head pixel.
* the segments of the body follow the head as if on rails - no corner cutting
* the snake can grow in length 

## DRAFTING THE REST

There are many ways, we'll stay focussed on one.

## Idea: SNAKE AS HISTORY

The Snake's body, when you think of it, is sort of a history of places the Snake has recently visited.

PICTURE OF FOOTPRINTS 

Think of footprints as you walk on sand, or in the snow. Which prints are nearest? Furthest? We naturally describe them in terms of time. The most recent is  one behind it is slightly older and so on.

{{< imgcard bears_alan_watson >}}
Which prints here are most recent?
{{< /imgcard >}}

{{< imgcard paws_circles >}}
What do you know about the concrete when these paw prints were made? Think outside the circle.
{{< /imgcard >}}

**Bear prints answer:** The ones under their feet <img src="pausechamp.png" width=40 height=40 />

GEOTAGGED PHOTOS

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
<img src="big_baby_bird.jpg" width=400 />
I'll be getting you started on this, but after that you'll have to fly on your won: putting together the code and ideas into a working snake is up to you.
{{< /alert >}}

### Steps

Simulation:
1. Make a variable in our snake that can store our past locations, our history.
2. Every time we are going to move to a new location, add our current location to the history 
Output:
3. Every time we go to draw the Snake's current location (with DrawPixel), go through our travel history and draw all of those too.

{{< imgproc screen_snake_history_insert Resize "600x" >}}
Drawing snake head, then the snake history in alternating colours.  
{{< /imgproc >}}

Try the segmented, growing snake in `4_snake_insert_erase.exe` from the zip below:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="week12_executables.zip" target="_blank">Download week12_executables.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

> Q: How did I stop drawing?  
> A: HMMM. How _did_ I stop drawing?


<!-- 
### 2. Draw Pixels Where We Visited

A trail should be easy. It's just a pixel drawn in any square the creature goes into.. wait, didn't we do that? 

{{< alert title="Did We Already Make A Trail?" color= "primary" >}}
Yes! Sort of! You moved to a bunch of squares and drew a pixel each time. Like walking down the street leaving a trail of m&ms.

The only reason it's not there is.. you fill the background every frame, erasing your old bat/snake coloured pixels.
{{< /alert >}}

### Exercise 1: Drawing Slithers' Trail

Filling the screen with wall and grass has been hiding slithers' trail. Stop it happening by commenting out a couple of lines.

{{< imgcard slithers_notrail_trail >}}
No trail, trail. No trail, trail.
{{< /imgcard >}}

{{< alert title="Definition: \"Comment out\"" color= "primary" >}}
To stop lines of code executing by turning them into comments. You can:
1. Add `//` to the beginning of code on a line 
2. Add `/*` to the start of a line and `*/` several lines later.
{{< /alert >}}

### What's Wrong?

That was a great way to get a trail, but what's wrong? What's the solution?

1. ???  (Messiness)
2. ???  (What's wrong with the trail?)

Solving either problem means wiping our trail out. How can we draw it again, instead of just drawing one pixel?
-->


### Exercise 1: Starting With 1

Slithers has one location, but we need many. Make another location in your Snake class (`snake.h`) called `lastLocation`. 

1. Every frame, **before** we move slithers, store (assign) her location in lastLocation.
2. Then move slithers (we already do this by updating her location)
3. When you `slithers.location`, draw another pixels at her `lastLocation`.

## More than 1 segment

Keeping a single location (lastLocation) gave us one frame of history, one segment of snake body. That was just one snapshot.

To get the rest you just need a collection of previous locations. 

Two ways to store collections of things in C++ are
1. Declaring an `array`
2. Declaring a `std::vector`. 

Arrays are very basic, static things that don't grow and don't offer any tools to us. I suggest using `std::vector`, because they're super flexible, easier and safer to use, and not noticeably slower for our simple game. 
<!--
{{< imgcard snapshots_onionskin>}}
Leaving snapshots behind
{{< /imgcard >}}

oldSlithers is just one snapshot of slithers past, being taken over and over again.
What if, instead, we had a bunch of snapshots, and instead of updating them we just take new ones. When slithers is about to move, take a snapshot and leave it there.


PREVIOUSLY COMMENTED
> slithers0, slithers1, slithers2, slithers3..

What about all those damn variables though? Do you have to make like 100, 1000 variables to store them? How do you even make new variables at run time? Hell, we don't even need all the names. Just slithers0, 1, 2, 3.

## Storing History In Collections

 You need a collection of Creatures you can access with a single name (maybe oldBattys?) and a number or `index`.

{{< alert title="Indexed Collections" color= "primary" >}}
 A gallery contains lots of precious and small items. When you visit with your family then, you're not surprised that they don't want people taking in bags: they ask you to leave yours with security in the `bag check`. It's full of all different sizes and shapes of bags, and when they take yours they assign it a number, 104, so they can find it again.
 
 When you've had your walk around the gallery you return and fish out the piece of paper reading "Bag Check" with your bag's assigned number. Without needing any sort of description, they find and return your bag.
 {{< /alert >}}


## Collections: The vector
A vector object can hold any number of a chosen data type(int, float, string, Bag, Creature, Fruit). Then you can read or write individual values in the collection using an index.

-->


### Declaring a vector of stuff:
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

<!--
### Visualising locationHistory

So, if slithers is real, and behind her is a trail of snapshots of her past, many old slithers, we could call that `slithersHistory`.

{{< imgcard battyHistory_in_flight>}}
{{< /imgcard >}}

Every time **she is about to move**, we create a **new snapshot**, an `oldSlithers` at her current position, **insert it** into `slithersHistory` at the **beginning**, and then move her.

That **new snapshot makes her body one piece longer**, which is **not okay** because she only grows when she eats, not every time she moves. 

To prevent growing, we **snip off** the old, **unwanted snapshot** at the end of `slithersHistory`

## Making a snake:
* Say you have a `Creature` called `snakeHead`.
* And you make a `vector` called `snakeHistory`, to hold old snakeHead snapshots. It's of type `vector<Creature>`
Create the first 3 snapshots, `Creature`s with the same x and y as snakeHead, and push them onto the snake, like so:
In a loop:
  * make a `Creature` called `oldHead`
  * give it `snakeHead`s `x` and `y` coordinates.
  * add it to `snakeHistory` with vector::push_back()

### Drawing A Snake
1. Loop through `snakeHistory`. For each `Creature` in there, draw a pixel at it's x and y location
2. Body drawn, draw a pixel at `snakeHead`'s `x` and `y` location.

### Moving a snake:
1. When you're about to move the head, make a snapshot, a `Creature` called `oldHead`
2. Store `snakeHead.x` and `snakeHead.y` in `oldHead.x` and `oldHead.y` (like we did with `oldSlithers`)
3. `insert` `oldHead` into the `begin()` of the `snakeHistory`.
4. `erase` the oldest `Creature` at the end of the the `vector` to keep the same length.
-->

{{< imgcard diagram_snake_move_insert_erase Link "diagram_snake_move_insert_erase.png">}}
Step by step.
{{< /imgcard >}}

### Drawing a snake, not our entire history

Our snake isn't a trail all the way back to our origin. Each frame, we'll have to limit how many old locations we draw. Where's the cut off point? What property of a `Snake` might tell us how _long_ a `Snake` is?

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

## A3 Required:Doing more than the minimum

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

## Colliding with your own body

A snake's body is just a list of locations. How can we check, each frame, if slithers' head (`slithers.location`) is on the same pixel as one of her body parts? You've already done it for a `strawberry` or `banana`, so do the same for the old locations. 
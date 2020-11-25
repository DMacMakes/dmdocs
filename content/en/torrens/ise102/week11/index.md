---
title: "Week 11: Custom objects, Collisions"
linkTitle: "W.11: Customs"
weight: "110"
description: >
  How do we check if things collide? How can we use bunches of related objects easily? How do we add more screens to our game?
---

## Learning this week

1. Targeting speeds, using high frame rate and lazy drawing: Last week's _**medium**_ and **_advanced_** homework
2. Creating a fruit object
4. Add Score: Make a variable,show on gui.
5. Colliding! Fruit.
6. Adding to score on fruit hit.
7. Game over?

<!-- _Coming soon.._ -->

## Homework due next week  

**Homework:**  
_easy:_ Collide with wall, end game. Add in a poison fruit.  
_hard:_ Add in teleporting, remove deadly walls. Game over: Offer option to play again.  
_advanced:_ Add second playmode, deadly walls. Pass as argument to playSnake.  

## A2 Slots marking

Not ready yet, will be releasing in bunches as I go.

## Assessment 3

## Last week's homework and review

We added up and down movement, controlled speed. In the review we learned more about controlling and calculating speed, and **found the txtpxls library had been broken by windows sdk changes**.


<a class="btn btn-lg btn-primary mr-3 mb-4" href="../week10b/#homework" target="_blank">Week10 Homework<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## Creating your own objects

### Slightly updated base

You can continue to use your work from last class or grab this. It has the fixed frame rate code, up and down movement, TODO comments for this class.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="Snake_A3_w11_incomplete.zip" target="_blank">Download Snake_A3_w11_incomplete.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### The easy way: copy and edit 

Creating an object is as easy as   
1. Creating a _**myobject.h**_ file, known as a **header file** file (or less formal **dot h** file)  
2. Defining a **`class`**, which is basically a recipe/description of the object you want.   

An easy way is to copy a similar class and edit it. **Open your snake project** in Visual Studio and **look at the _snake.h_ file**.

* What does it tell us about a snake object? What properties would it have?

{{< imgproc code_snake_class_explained Resize "1024x" Link "code_snake_class_explained.png" >}}
Hacking time! We can get away with understanding 80% of what's going on here 👍
{{< /imgproc >}}

### What is a fruit?

{{< imgcard fruit_pixel_marker >}}
Credit: <a href="https://www.youtube.com/watch?v=xCX7NyfY_Gg">Hello Pixel Art</a>
{{< /imgcard >}}

What properties does a fruit have? 
1. Fruity properties: kind, colour.
2. Gamey properties: location

Anything else?


### Exercise 1a: Create a fruit class

1. From solution explorer (in Visual Studio), right click your project and open/reveal it in explorer.
2. Find the snake.h file. Click it, then copy it (right click menu or ctrl+c) and paste it (ctrl-v).
3. Rename the new copy **`Fruit.h`**.
4. In the Visual Studio Solution Explorer, right click _Header Files -> Add -> Existing item.._ and choose the Fruit.h file.
5. In Solution Explorer, Double-click Fruit.h to open it.
6. Change this class to a Fruit class with the following properties:
   - colour (short)
   - location (use Point2d)
   - value (1 pt, use int)
---

### Exercise1b: Create a fruit

1. Go back to `main.cpp` and, above the loop in `playSnake`, define some fruit! 
   * Create a yellow banana, set its position (not in wall or snake)
   * Create a strawberry, set its position
2. Draw those fruit every loop, just like you draw slithers. 
   * Do it on the lines just above the code for drawing slithers, which prevents them drawing over the snake when they collide.

## Adding a score

1. Add a variable for the score
2. Draw it to the gui
3. Gui as sep function?

## Colliding with fruit

When have you collided with something? 

What happens when two cars attempt to share the same location?
What about two people? Two huskies?

{{< imgcard collision_moonmoon>}}
Moon Moon demonstrates.
{{< /imgcard >}}

So how do we check if fruit shares a location with our Snake?

### Fruit collide!

* How to check location equality?
* How to only collide once?

### Stop and check variables when you've collided 

In your collision checking code should be a section to handle what happens if the collision result is `true`, and you can set a boolean, say `snakeHitFruit` to `true`. Set a breakpoint on that line, and debug your program, you can check all sorts of useful information (like if slithers location really does match that of a fruit)

{{< imgcard code_snake_collide_test>}}
Once you've actually moved you can check if you've slammed into something. Setting a boolean gives me a line of code to set a breakpoint against, also it's probably useful.
{{< /imgcard >}}

Remember,to debug your code you have to have the drop down on the toolbar set to _**debug**_, not _release_, then in the menus click _debug->start debugging_ or hit **F5**, or click the _Local Windows Debugger_ button on the toolbar.
{{< imgcard debugger_fruit_collisions>}}
The debugger "Locals" window showing the contents and values for our banana (Fruit object) and Slithers (Snake object), along with other great info.
{{< /imgcard >}}

### Exercise: Collide and stop

1. Make fruit collision happen
2. Set a breakpoint inside the collision testing if statement
3. Screenshot the moment in time when the debugger stops the game (game screen, not code)
4. Paste into Discord.
5. Does the image match what the collision test and local variable values (in debug locals window) for the snake and piece of fruit are telling you? Why?

## Homework

You don't have to send me this homework, but you do have to do it if you want to have **a chance at finishing the assessment** on time and passing. I'll answer questions about it next week and help a bit, but I won't spell it all out.

**CRITICAL:** 
1. When you hit the fruit, **add 1** to the score.
2. Pass the score to the gui drawing function
3. Always **display the score** as part of the gui
4. Reposition fruit when eaten (as if it's a new fruit)
5. Check if the **snake hits the walls**: you can check side walls when moving left/right,
   top and bottom when moving vertically.
6. Test the wall collision with a breakpoint like we did in class for fruit collisions.
   Once it works, try pausing the game for a while and displaying a message about 
   the deadly wall collision.

Optional:  
1. Give the second fruit type a different score.
2. When the snake collides with a side wall, teleport it to the opposite side. Do the
   equivalent for top/bottom walls.

## Extra session this week

Covering collections aka arrays/vectors.

Time and date incoming! 

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../week11b" target="_blank">Week 11B<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

  

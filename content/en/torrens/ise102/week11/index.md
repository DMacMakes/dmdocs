---
title: "Week 11: Custom objects, Collisions"
linkTitle: "W.11: Customs"
weight: "110"
description: >
  How do we check if things collide? How can we use bunches of related objects easily? How do we add more screens to our game?
---

## Learning this week

1. Creating a fruit object
1. Add Score: Make a variable,show on gui.
1. Colliding! Fruit.
1. Adding to score on fruit hit.
1. Game over?
1. speed change options: frame rate or draw interval

<!-- _Coming soon.._ -->


## A2 Slots marking

Announced on Blackboard, Discord. Ultimo, Online 1 classes are marked, Online 2 in progress.

## Last week

We added up and down movement, set a high framrate and only moved when we needed to with `moveInterval()`.

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

## Things left to do

Not sure what's left to do? Check the [Snake_A3 Trello](https://trello.com/b/aVYKZSK8/snakea3).

{{< imgproc snake_trello Resize "650x" Link "https://trello.com/b/aVYKZSK8/snakea3" >}}
Click image to visit the Trello
{{< /imgproc >}}

## Bunches of data: collections!
 
 Games are full things, and a lot of those things are _almost_ the same.

{{< youtube "09QaF345qZk?t=203" >}}
(Jump to 3:20)

Chickens, buildings, villagers, fishmen, trees, clumps of grass with or without hidden gems, treasure chests, bouncing fireballs, stone platforms, eaty flowers, stone tiles.

Lots of each of them, and they don't all have variable names. We don't have time for garima, kevin, jacinta, and aram the chickens. Or stoneTile1, stoneTile2, stoneTile3. How would you even write code to deal with so many variable names?

Instead we need **a way to deal with things as collections.**

{{< alert title="A punnet of strawberries" color= "primary" >}}

This little plastic container is a _punnet_, and it's full of strawberries. 

![](strawberries_punnet.jpg)

It has
  - a type of thing it's holding: in this case strawberries, or more generally, Fruit
  - an amount of fruit in it
  - a limit to what it can hold in this case
  - a way of retrieving the strawberries inside
{{< /alert >}}

### Virtual punnets: the Vector

We've already used collections in C++: strings. They're just collections of characters, and they have properties like "size()" and functions to change or access the characters, like `append()` and `substr()`.  

We need a more generic collection, something that lets us choose what type of things it contains: maybe a collection of integers, or even whole strings, or Fruit.  
  
The **`vector`** object is exactly that. If we add **`#include <vector>`** to `main.cpp`, we can make vectors of any size to hold whatever we need.  
 
You can declare a new vector that holds `Fruit` objects like this:  

```cpp
  vector<Fruit> strawberryPunnet;
  // vectors are objects. They are special because they can hold a punch of objects.
  // vector is the type of container object, then <Fruit> specificies what type of objects it can hold.
  // finally it has a name, punnet.
```

Add an existing fruit to your vector with **`.push_back(strawberry)`**. It's not a great name, but it means something like "add_to_end". If you imagine someone joining a queue, they join it at the end. They're kinda.. pushed onto the back?
```cpp
Fruit smallStrawberry;
Fruit hugeStrawberry;
strawberryPunnet.push_back(smallStrawberry);
strawberryPunnet.push_back(hugeStrawberry);

// punnet now contains 2 fruit.
// punnet.size() returns the number of things added to the vector (as an integer)
drawString(0,0, "Number of strawberries in punnet: " + to_string( strawberryPunnet.size() );
```

## Exercise: vectors

1. Grab Fruit_vector_wk11_inc.zip (a special cut down version of snake) 
2. Look for the //TODO: comments
3. Finish the code by uncommenting lines and filling in the blanks.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="Fruit_vector_w11_inc.zip" target="_blank">Download Fruit_vector_wk11_inc.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### Accessing objects in vectors by _**index**_

 {{< alert title="Indexed Collections" color= "primary" >}}
 A gallery contains lots of precious and small items. When you visit with your family then, you're not surprised that they don't want people taking in bags: they ask you to leave yours with security in the `bag check`. It's full of all different sizes and shapes of bags, and when they take yours they assign it a number so they can find it again.
 
 When you've had your walk around the gallery you return and fish out the piece of paper with your bag's assigned number. Without needing any sort of description, they find and return your bag.
 {{< /alert >}}
 
 You create a single vector object, and can submit as many objects to it as you like for safe keeping. To access any object, just provide an _index_. Like with most indices in c++, it starts at 0.

## Homework

1. Core
2. Go further
3. Delivery
  
### Core:
1. When you hit the fruit, **add 1** to the score.
2. Pass the score to the gui drawing function
3. Always **display the score** as part of the gui
4. Reposition fruit when eaten (let's pretend it's a new fruit)
5. Check if the **snake hits the walls**. If you're moving left/right, you can check if your x matches one of the boundary walls. If going up or down, check y against boundaries.
6. When the snake hits the wall, try stopping the game and displaying a popup message about the deadly wall collision, layered over the game.

{{< alert title="The Golden Rule" color= "primary" >}}
If the player doesn't know something happened, it shouldn't affect them. Put another way: a player should never have to guess what happened.

* If there are deadly walls in one mode and teleporty in another, they should *look different*. 
* If a player hits a poison fruit and dies you better have made it clear that fruit was deadly. 
* Whenever you die the game has to make it clear, and hold for a bit so the player knows the context and can accept responsibility + see how to do better.
{{< /alert >}}

### Go further:
1. Add a second fruit type that gives you more points. Show the fruit types in the gui (below the game) and their value.
2. When the snake collides with a side wall, teleport it to the opposite side. Do the
   equivalent for top/bottom walls.
3. Give the game basic easy+hard modes:
   - easy: the walls teleport you.
   - hard: the walls kill you
   - Don't duplicate the whole `playSnake()` function to do this. If `playSnake()` receives a variable, say, `int mode`, that should be enough. You can use it in `if` statements to decide whether a collision is deadly or teleporty in the current mode.
   - You could add the modes to the main menu or provide them in an options screen (access from main menu) or game type screen (after menu, before game starts).
4. Maybe create a deadly fruit that appears, is a terrifying hazard, and then disappears for a bit before appearing somewhere else.

### Delivery
Clean and zip the solution (as we do for assessments), email your zip to your lecturer by the end of Sunday.

<!-- 
## Extra session this week

Covering collections aka arrays/vectors.

Time and date incoming! 

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../week11b" target="_blank">Week 11B<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>
-->

  

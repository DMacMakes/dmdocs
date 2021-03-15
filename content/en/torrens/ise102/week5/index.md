---
title: "5: Functions 1"
linkTitle: "W.5 Functions 1"
weight: 50
description: >
  Programs inside programs!
---

<!-- First, what are functions and how do you use them? -->
## Doing the same thing all the time

In a **shooter** like _Battlefield_, _Overwatch_ or _Fortnight_, what are you doing a lot of? **Shooting**. Hitting things, missing things. Weapon switching, reloading. 

In a **platformer like _Super Mario Bros_** you do a lot of **jumping** and **colliding with things**. You **collect** who-knows-how-many items (coins, stars, mushrooms), and sometimes you **power up**.

{{< imgcard mario_actions >}}
Platforming actions
{{< /imgcard >}}

{{< alert title="Player Actions" color= "primary" >}}
A game, boiled down, is **a person performing a small set of actions, many times.** Actions which
* Have predictable properties (a jump goes this high, and higher if I hold the button)
* Occur in many different scenarios (off a platform, under a brick, onto an enemy)
* Produce outcomes appropriate (following the game rules and world physics) to their current scenario.
{{< /alert >}}

As a programmer, you'll need to make the same things happen all the time. This means you'll want **the same code over and over again..** but without having to write it over and over again. Loops were one way to do it, but how to we get back to them? How can you be in one loop for jumping, and then another for shooting, then back to jumping.. WHILE shooting? 

### The same but different.

Even worse, you're **not really doing the same thing**. 

You're sometimes pressing jump under water, sometimes in a tanooki suit while falling (Mario), sometimes while sliding across ice riding a dinosaur who's holding a giant egg in his mouth.. So it feels kinda like we need `whiles` in `fors`.. with `ifs` in those `whiles` and `fors` in those `ifs`.. it's like a Dr Seuss book. 

{{< imgcard through_jumpers>}}
Through-jumpers jumping through horns while their horns are jumped through.
{{< /imgcard >}}

### Way too many `if`s

Here's just a **tiny sample** of the sort of ifs you might handle if we kept going with just the tools we have. Imagine these three jump actions with all the yoshi riding  and mushroom powerup variations added, along with fire flower, speed boosts etc etc.  
  
> If she presses jump, if **running**, if not riding yoshi, if has a mushroom power up, **do this**.  
> If she presses jump, if **walking**, if not riding yoshi, if has a mushroom power up, **do whatever**.  
> If she presses jump, if **swimming**, if not riding yoshi, if she has a power up, **do that**  
> etc etc.  
  
How does anyone even make games?  
  
Spoiler alert, we're going to use *functions* and other tools to get around these problems, but **they'll still be possible if we aren't careful**, so let's avoid this classic *code smell*:  

{{< imgcard bad_nesting_shapes >}}  
If you can draw big pyramids under your code like this, it's stinky.{{< /imgcard >}}

## Reusable code: Functions

Functions! They're like **little programs within your program**! They're bits of code you want to use a lot, wrapped up in a bundle you can summon whenever you want. They do a single, focussed job, then tell you how it went/give you an answer.

You could call them to:  
* start a jump  
* check if you've landed  
* update the score  
* show a menu  
* whatever.  

Just like programs, they become really dynamic *when you feed them input* - change what goes in, you get something different coming out.  

How they work:  
1) You all them by name: maybe `fireCannon();` or `showExitMessage();`    
2) Give them some input (if they need it): `bigOrc.takeDamage(20);`  
3) They do whatever they are supposed to do   
4) When finished, they feed you back (usually) some output. A card game might have `bool youWon = checkForWin(card1, card2, card3);` or I could find things out about a string with `numberOfLettersInMyName = myName.length();`    

Before we even learn how to really use or write them, you can see that function with a good name and the right input/output makes code read aloud like what you were trying to do 👍    

## Functions we can already use in C++ for free  

> Writing functions save you a lot of work. Using someone else's functions though, that's even better!  

There are loads of free and super useful functions packaged with _C++_, in the _**Standard Library**_  

```cpp
float cash = 5400.23f;
int cashRounded = roundf(bigCash); // Rounding to nearest int.

string tweet = "I have every unlock in Mario Kart 8 #hotsawce";
int tweetLength = tweet.length();

int randomNumber = rand();  // See, they're pretty self explanatory.

int myDogAge = ageInDogYears(myAge); // no.
```

{{< imgproc ceil_cppref Resize "300x" Link "http://www.cplusplus.com/reference/cmath/ceil/" >}}
Cplusplus.com reference for the <code>ceil()</code> function
{{< /imgproc >}}

* Our **work colleagues**, friends or teams we're making games with, Github, game engines, operating systems, drivers and many, many more.  

### The Standard Library

The keywords of the language give you the basic building blocks to make whatever you need.  That leaves out a lot of everyday things you might need though like:  
* reading files  
* generating random numbers  
* rounding off numbers  
* trigonometry and much more.  

The Standard Library functions are spread out in a number of library files, but all use the same `std` prefix.  
1: **include** the right **header** like `#include <cmath>`  
2: Either use `std::` or `using namespace std` to access the function. Now you know what that really means.  

> To find which header holds the function, google like so: for absolute values (turn a negative positive) google "absolute value C++" and click [abs - C++ Reference - Cplusplus.com](http://www.cplusplus.com/reference/cmath/abs/).  

### Handy Math For Games  

Here's Some very basic but very necessary math you don't want to have to code yourself.

| Function  | Header      | Description                                                   | Returns            | Link |
|-----------|-------------|---------------------------------------------------------------|-----------------|------|
| **abs**   | cmath     | Takes a number, returns the **positive value**  (-2 becomes 2)  | int, float etc     | [docs](http://www.cplusplus.com/reference/cmath/abs/)     |
| **ceil**  | cmath     | Takes a decimal, returns **nearest higher** whole number        | float, double      | [docs](http://www.cplusplus.com/reference/cmath/ceil/)    |
| **lround**| cmath     | Takes a decimal, returns **rounded** result, converted to int.  | int (use round for float) | [docs](http://www.cplusplus.com/reference/cmath/round/)    |
| **pow**   | cmath     | Takes numbers a and b, returns **a to the power of b**          | double      | [docs](http://www.cplusplus.com/reference/cmath/ceil/)    |
| **srand** | cstdlib   | Takes a number, **seeds** random number generator               | void                | [docs](http://www.cplusplus.com/reference/cstdlib/srand/) |
| **rand**  | cstdlib   | Generates a **random number** from 0 to RAND_MAX                | unsigned int        | [docs](http://www.cplusplus.com/reference/cstdlib/rand/)  |
| **time**  | ctime     | **Time** in seconds since Jan 1 1970. Good seed for srand.      | time_t              | [docs](http://www.cplusplus.com/reference/ctime/time/)    |

## Calling a function

You _call_ a function by writing its name followed by parentheses.

```cpp  
// Just focus on the part after `=`
int rand1 = rand();
```

The function evaluates to some sort of value, just like expressions with operators do (say `4+8` or `y * 4`).

### Passing data to a function

You _pass_ it input data, called _arguments_ or _parameters_ by putting variables or literals in the parentheses.

Think about it: if you're asking someone to do a real world job for you, maybe get you something while they're on holiday, they need info.  What is it, where can they find it, how much will it cost?

```cpp
// round `5.7` down to the nearest int and give us the result.
// See how you can use it where you'd use any other expression?
cout << floor(5.7f);  // prints what?

// Using `pow` to get the square of a number. It's just an exponential function,
// like using the x-to-the-power-of-y button on your calculator.
///You can pass the usual data (variables, literals etc) to functions.
int x = 5;
int xSquared = pow(x, 2);  // Using 2 as the power is like using the x squared button
cout << xSquared;   // prints what?
```

**Output:**
>  5  
>  25  

### Do something with the return values!

A function (often) _returns_ a result, which has a data type (int, float) etc. In the code above, `pow(x,2)` is processed and returned `25`. This is just like a maths expression, say `5*2`, is processed into a result, `10`. It is only held in memory temporarily, and if not stored will be lost when you move on.

You want to do something useful with the return values like you would with the result of any expression:
* Store it in a variable or
* Print it to the console with `cout` or
* Use the result in another expression

```cpp
/// You wouldn't write this without printing or storing the result
5 * 2;      
/// ( The result, 10, evaporates.. )

/// So don't expect anything useful to happen if you do this:
roundl(3.6f);
/// ( The result, 3.0f, evaporates.. )

// Try storing the result
int nearestWhole = roundl(3.6f);    // Stores 3

// Printing the result
cout << "Nearest whole number to 3.6 is " << round(3.6f);

// Using the result in an expression, then storing the result of the expression.
// I'm using use the results in a simple calculation, averaging two numbers:
// Average of two numbers = (a + b) / 2
float roundedNumbersAverage = (roundl(3.6f) + roundl(1.2f)) / 2.0f;

```

## Functions for random numbers

C++, like most languages, offers functions that **generate random numbers** for you.

The most basic of them is `rand()`. Have a look at this definition of `rand()` from [cplusplus.com](http://www.cplusplus.com/reference/cstdlib/rand/).

{{< imgcard rand_cppref Link "http://www.cplusplus.com/reference/cstdlib/rand/">}}
Click for more info.
{{< /imgcard >}}

## Exercise: Random code

Make a project called _randoms_ and  type out the following code:

{{< imgcard rand1_code_jdoodle Link "https://www.jdoodle.com/online-compiler-c++17/">}}Printing the random number and the range of numbers possible. (Written in the jDoodle.com editor){{< /imgcard >}}

Now, edit the code to create and print 3 random numbers. 

> Hints: Keep it simple, don't use a loop for now. Maybe an `int` called `rand2` might help.. maybe more?

### Not that random.

You might have noticed by now that your random numbers, though pretty random are **always the same** 3 randoms.

> "That's not very random." - everyone.

{{< alert title="Deterministic machines" color= "primary" >}}
Before starting his rounds in the hospital cardiac ward, Nurse Feng has to calculate the dosage of heart medication for one of his patients. He enters `high blood pressure`, `female` and `66kg`. The machine outputs:
> Verapamil, 5mg. (high bp, female, 60-70kg)
Just to be safe, he runs it again
> Verapamil, 26mg. (high bp, female, 60-70kg)

Clearly, computers that gave different results each time you run the same calculation would be **very very bad**. 

This is why computers are designed to be _deterministic systems_: if you start at the same point, with the same data, and take the same steps, you can expect the same outcome.
{{< /alert >}}

### Psuedo-randomness

Computers, then, are actually bad at being random, because everything about their design had one main goal: stopping anything random happening! 

This is one reason we call `rand()` a **pseudo-random number generator**. It can generate a long series of seemingly random numbers, but it has to start somewhere and it always does that the same way.

### Seeding

We can **change the starting point** of the random calculation.

A **_seed_** is a number we feed to the computer something it doesn't control. 

We can start with something pulled from thin air, like `10`.
* `rand()` doesn't just accept a seed argument 😢
* Instead we can pass 10 to `srand()`.  

{{< imgproc rand1_b_code Resize "1280x" Link "rand1_b_code.png">}}
New seed, new result?
{{< /imgproc >}}

Try adding it to your 3 number generator, like i've done below for rand1. You only need to call it once.

### New problems 

Run it a few times. What's wrong?? 

Now we have the respsibility of feeding `srand()` a different value whenever we start our program. It sounds like we've circled back to the same problem.. but **the number we feed in doesn't have to be random, just different each time**. 

* We'll use a very basic one: the current time (to the second).

{{< imgproc rand1_seed_code Resize "1280x" Link "rand1_seed_code.png">}}
Click to expand
{{< /imgproc >}}

<!-- end learning how to just USE functions -->
{{< alert title="Function: definition and synonyms" color= "primary" >}}
A section of a computer program that is **defined only once** but can be **called on when needed**. 

Though we'll (mostly) call them functions, they have several names across programming languages. Even within _C++_ you'll hear more than one. 

The most common are:
* method 
* procedure
* routine
* subroutine
* subprogram

Are there any **you know** that aren't listed here?
{{< /alert >}}

## Making your own functions

You can define them to handle whatever job you need done, then call them whenever needed. You can hand them new data to work on each time, and grab their results to use or pass to other functions to get even more done.

They're easy to create because they have the same basic components as their parent programs: input, storage, processing and output.

The function `twoTimes` takes a number and multiplies it by 2:

### Declaring a function

**Just like a variable**, a function needs to be _declared_. We have to tell _C++_ what it's **named**, what input it **accepts**, and what type of data it's going to **return**.
* Like a variable, you write the _type_ followed by the _name_
* Unlike a variable, you put **parentheses on the end** to tell C++ it's a function.

```cpp
// Declaring a function that returns my age as an int 
int myAge();
```

If your function will accept inputs, you declare those in the parentheses

```cpp
// Declaring a function that multiply any (integer) input value by two and return the (integer) result.
int twoTimes ( int inputValue );
```

### Defining the function body

Just like a variable without a value isn't much use, a function without any code isn't much use.

To make it useful, you have to _define_ the function body in curly braces `{}`. Just like code blocks for `if`, `for` and `while`, it can hold new variables (storage) and statements (processing).

Here we'll **declare and define** twoTimes:

![](function_twoTimes_code.png)

The **output** or result of a function is called the **return value**. That's what will take the place of the function call when it has been processed

![call twoDozen](call_twoDozen_code.png)

### Exercise: Creating the twoTimes program.

Using the code outline below and the real code above, create the *two_times* program in Visual Studio.

```cpp
#include <??????>  // Put the include needed for cout here.

// Declare and define twoTimes here

int main ()
{
  // call twotimes from here, with an argument, and store the value.

  // Print out a message, include the result from the call to 2X
}
```
The program should produce this output:

![twoDozen output](twoDozen_output.png)

---

## Assessment 2 and homework

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../assessments/#assessment-2-slot-machine" target="_blank">Assessment 2 Info<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>
* Slot machine!
* Homework counts!

**Do not look at any slot machine code outside of class!** You'll end up using it even if you don't intend to. Look at fundamental code, documentation, other kinds of games: not a slot machine.

---

## Randoms in range 1: Integer remainder

In integer division, **dividing a by b,** produces a _**quotient**_, or how many times b divided **evenly** into a.

The left over amount is the **remainder**. As you know, **a modulo b** gives us that.  

> a / b = quotient  
> a % b = remainder 

### A pattern emerges:

If we keep dividing a by 3 what becomes obvious about the `b` and the remainder?

|  a / b  | quotient | remainder |  
|------|----------|------|  
| 6 / 3 | 2 | **0** |  
| 7 / 3 | 2 | **1** |  
| 8 / 3 | 2 | **2** |  
| 9 / 3 | 3 | **0** |  
| 10 / 3 | 3 | **1** |  
| 11 / 3 | 3 | **2** |  
| 12 / 3 | 3 | **0** |

It looks like for **any value of a**, `a % b` produces a number from `0` to `b-1` before it divides evenly again.

{{< alert title="Rule: Maximum Remainder Size" color= "primary" >}}
For any value of `a`, the **maximum remainder** of `a/b` is `b-1`.
{{< /alert >}}

### Producing a range from 0 to n

```cpp
/// The rule above says anything % b maxes out at b minus one
betweenZeroAndB_minus_one = anything % b;    

/// So a % (b+1) gives us something from 0 to b right? 
// Try 7 % (3+1).. which is 7 % 4.. remainder is 3. It works!
betweenZeroAndB = anything % (b + 1)

// Then for any random at all..
randomBetweenZeroAndB = rand() % (b+1);
```

{{< imgcard modulus_11_over_3 >}}
There are <b>3</b> sets of 3 balls. <b>2</b> are left over. If we add one more.. it becomes 4 groups of three, with no leftovers.
{{< /imgcard >}}

---

## Randoms in range 2: Ratios

A decimal between 0 and 1 is the ratio version of a percentage. If you multiply it by 100, you get the more recognisable percentage 0-100.

**0.5 of something is 50%**, 0.1 is 10%, 0.99 is 99% etc.

At school you turned a **fraction** into a decimal **ratio** by dividing the top by the bottom:  

| Fraction  | Ratio  |  Percentage (ratio*100)  |  
|------------|----------------------|-----------|  
| 1/2   | 0.5   | 50%   |  
| 1/4   | 0.25  | 25% |  
| 2/4   | 0.5   | 50% |  
| 3/4   | 0.75  | 75% |  

So if we have a number **x** between **0** and a range's upper limit (**max**imum) we can figure out the ratio:  

```cpp
ratio = x / max;
```

### Converting your ratio to a new range

Once you **have a ratio**, you can easily express it as a number **y** in a new range: 

**Multiply** the **ratio** by the **new** range **max**.

```cpp
y = ratio * new_max;
```

> 6 eggs in a carton that holds a dozen:  
> _6/12 = 0.5 (50%)_  

| Ratio  | Max  |  Ratio * Max = y  |
|------------|----------------------|---------------|
| 0.5 | 4   | **2** |
| 0.5 | 100 | **50** |
| 0.5 | 20  |**10** |


### In C++

```cpp
/// We already have accessto the maximum value
/// of our random through RAND_MAX.
int randomValue = rand();

// `r = x / max` gives us a ratio so:
float ratio = (float)randomValue / (float)RAND_MAX;

// So if we want it as a number from 0 to 10
int outOf10 = ratio * 10;

// We had to use (float) before each variable to force c++ to do
// do floating point division. Otherwise it uses integer division.
// Any decimal from 0 to 1 would be cut down to 0.
```

---

## Summary

This week we learned:
* Functions are like mini programs: 
  * input, storage, processing, output
* Creating and calling functions
* How functions make programming easier
* Ways to get more out of functions
  * Passing arguments
  * Descriptive function names
  * Returning values.

___

## Homework

{{< alert title="Homework is part of assessment 2" color= "danger" >}}
On-time submission of weekly homework is part of assessment 2. Non-submission (or low effort submissions) will **impact your final mark.**
{{< /alert >}} 

It consists of assigned reading and two code projects. **Submit** your two `.cpp` files (calculate_more and random_range)  **by the end of Saturday.**

### 1: Reading

Read [Chapter 5](../resources/cpp_through_games_5.pdf), pages **143 to 153**. You can stop when you reach 'Working with scopes'. 

{{< imgproc cpp_through_games Resize "200x" Link "../resources/cpp_through_games_5.pdf" >}}
<b>Click to download</b> Chapter 5.
{{< /imgproc >}}

{{< alert title="Separating declaration and definition" color= "primary" >}}
You can **declare a function before main()** (like a variable declaration) and **define the body after**. 

Be ready to see this in the textbook. Functions will be your bread and butter from now on, so get your head around them!
{{< /alert >}}

### 2: Calculate_more

Two times calculator is a bit limited. **Create a new project** called *calculate\_more*. You can copy+paste the code from the old calculator's `.cpp` file as a starting point.

Instead of two times calculation, **give the program the features below**:
* Ask the player to input a multiplier (int) and store it.
* Also ask them for a multiplicand (int) and store it
* Calculate the product by calling a "multiply" function which takes the two numbers as _arguments_ and returns an _int_. Store that value.
* Print the product.

**Mathematical terminology** for `a * b = c`:
> **multiplier** * **multiplicand** = **product**  

(from [wikipedia](https://en.wikipedia.org/wiki/Multiplication))
 
### 3: Random_range

**Create a new project** called _Random\_range_. In it you'll make a function called `randInRange()`. When you call it and pass an integer `rangeMax`, it'll return a random in the range `0` to `rangeMax` inclusive.

I've written the structure, it's up to you to replace the missing code. _Note: The lines (\_\_, \_\_\_\_\_) don't always match the length of the answer._

{{< imgcard hw_rand_code_gaps Link "hw_rand_code_gaps.png">}}{{< /imgcard >}} 

The output (with your own program name) should look like this:

{{< imgcard hw_rand_range_output Link "hw_rand_code_gaps.png">}}{{< /imgcard >}} 

{{< alert title="That random code" color= "primary" >}}
The approach you use to change your random from the default range `0`-`RAND_MAX` to the custom range `0`-`range_max` is up to you. Use either technique from the section above (By remainder or ratio), whichever made more sense. Or do it your own way.
{{< /alert >}}


  


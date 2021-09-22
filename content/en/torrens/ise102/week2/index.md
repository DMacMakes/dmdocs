---
title: "2: Comparing and Deciding"
linkTitle: "W.2 Comparisons"
weight: 20
description: >
  If we can _compare_ things and _choose what to do next_ we can almost make anything!
---


## Week 1 Recap And Homework

**Review:** Hopefully you all watched the video before this. If not, you're going to struggle a bit. Always watch those sessions before the next class or, even better, attend!  

## This Week: A New Game

We're exploring a new game called **_Guessy Number_**. Let's type it in, then break it down.

### Exercise: Coding guessy number

1. Fork your own copy of the [*hello-ise102* project on Replit](https://replit.com/@dmacmakes/hello-ise102).
1. Click the name of the project, *hello-ise102* and rename it *guessy-number*;
2. Enter the following code in main.cpp:
{{< imgcard guessy_code_vs Link "guessy_code_vs.png" >}}
Click the code if it's too small.
{{< /imgcard >}}
 
1. Click Run. Try to work through any errors you may have.
2. Test the game with a few guesses.
3. Take a **screenshot** of the *output* of the program (in the console tab) and **paste/insert it into the _#discussion-ise102 channel_** on our *Torrens Classes* Discord server.

## The power to choose!

In _Guessy Number_, Two new types of **processing** help the computer to be our playmate. They are:

1. **Comparing** two things to decide what is **true**.
2. **Choosing** what to do next.

Sure, in _C++_ this stuff is new to us, but we understood `true` or `false` and making decisions before we figured out _toilets_.

{{< imgproc vegetables_true Resize "1024x" >}}
<i>Peas</i> yo!
{{< /imgproc >}}

{{< alert title="True and False: Booleans" color= "secondary" >}}
People use true and false comparisons every day and have a great feel for it, but to really gain power over them we need some language. 

_George Boole_ spent so much time on figuring out how to use `true` and  `false` in maths (along with _and_, _or_ and _not_) that computer scientitsts ended up using the term _**Boolean logic**_.

```cpp
// Declaring variables of type `bool` or boolean.
// They can only store the values `true` or `false`.
bool doorIsOpen;
bool sunIsVisible;
bool dogPeedOnFloor;      // maybe if floorPuddleColour == "yellow"?
bool xGreaterThanY;
int x = 10;
int y = 5;

sunIsVisible = true;
xGreatherThanY = (x > y);     // Is x greater than y? That's either true or false.
```

Remember, when we talk about _Boolean logic_ or _Boolean operators_, we're discussing things that end up being `true` or `false`.

{{< /alert >}}

### Testing equality with `==`

{{< imgcard if_playerGuess_equals >}}
What's happening here?
{{< /imgcard >}}

How do we compare two things for **equality**? 
* Can we use `=`? Why not?
  * `=` already has a job: it's used for **assigning** a value to a variable

``` cpp
int secretNumber;
// ..code snipped

// We "assign" (give) secretNumber a new value, 2.
secretNumber = 2;    
```

Instead, we test "is equal to" or "is the same" using the operator `==`, which is just two equals signs. 

The test `(a == b)` is a question: is `a` is equal to `b`?  There are only **two possible answers**: `true` or `false`.

```cpp
secretNumber = 2;

// assume the player enters 4 here, so
// the value stored in playerGuess becomes 4
cin >> playerGuess;   

if (playerGuess == secretNumber) {
```

When our program runs (run time) and it gets to `playerGuess == secretNumber`, C++ knows it has  the job of _testing_ if the two numbers are equal. It has to return us a value of `true` or `false`. 

At run time the _expression_ **`playerGuess == secretNumber` is effectively replaced  with `true` or `false`**, depending on the result:

```cpp
if (true)
```

or

```cpp
if (false)
```

## Deciding The Next Action

{{< imgcard if_else_playerGuess >}}
How does this work?
{{< /imgcard >}}

Once we make a comparison, how do we decide our next action? `==` returned `true` or `false`, so we have two paths available to us. How can we head down one of two different paths in _C++_?

{{% alert title="New Tool: The <b>if</b> Statement" color= "primary " %}}
Any code in the first _code block_ (the first curly braces) is executed when the comparison evaluates to `true`.

If the comparison resutls in `false`, the second _code_block_ after `else` is executed.
```cpp
  if ( a == b )
  {
    // Do things if a and b were the same
  } else
  {
    // Do things if a and b were different
  }
```
{{% /alert %}}

### The Test In `if`

In the parentheses `()` we have the relational test `a == b`, but you can replace it with any test that returns `true` or `false`. You can even use a single `bool` because they can only be `true` or `false`.

### `else` is optional

You don't always have to supply an `else` action. For example, you only show error messages if errors happen, otherwise you continue as normal.

Let's say our character is falling from the sky, and only needs to stop falling if they hit the ground..

```cpp
  if (metersAboveGround == 0)
  {
    // stop the player falling
    playerFallingSpeed = 0;
    cout << youLandedMessage << endl;
  }
```

{{< alert title="Definition: Conditionals" color= "primary" >}}
_Conditional logic_ or _control logic_ is code that lets us choose what is executed next. It allows branching: we can choose our code to divert along one branch (do this) or another (do that).
{{< /alert >}}

## Assessment 1: Exam

Let's pop over to my [ise102 assessment page](../assessments/#assessment-1-exam)

## Other relationship tests

`==` tests the **relationship** between two things, in this case 'are they equal?' _C++_ and other languages have a family of them, known as...

{{< alert title="New Tool: Relational Operators" color= "primary" >}}
A _relational operator_ is something in _C++_ that checks how two variables/values relate to eachother and returns `true` or `false`.
{{< /alert >}}

{{< imgcard relational_operators Link "../resources/cpp_through_games_2.pdf" >}}
Click for the relational operators of c++. (Chap 2, p.38, of the textbook)
{{< /imgcard >}}

{{< alert title="Definition: Operators" color= "primary" >}}
_Relational operators_ are just the operators in _C++_ that test relationships.

Operators are just **symbols** that tell the computer to **do some processing** on variables or values.
{{< /alert >}}

```cpp
int myDollars = 10;
int yourDollars = 5;

// `+` is a math operator that performs addition.
int ourBudget = myDollars + yourDollars;
```
There are operators for arithmetics (`+`,`-`,`/`), input/output (`<<`,`>>`), assignment (`=`), logic (`&&` is _and_, `||` is _or_) and more.

## The Power Of Names

One of the most **important parts of learning** is putting names to things. Naming a thing or concept gives us power over it: we can **discuss** it, **theorize** about it, **question** it. It becomes a manageable idea, you can **combine** it with other ones.

Think about the power of the word _**choice**_ as you grow up. In your family life, at school, at work. Imagine life without the ability to think about and demand the right to make choices. **Would your parents ever have suggested** nutella toast and clan raids at 1am Sunday night?

We learned a few new and very powerful words today, and I don't want you to think of them as jargon or a pain to learn. These words might be the **biggest gift of a university education**. Todays words..

* Operators
  - Relational Operators
  - Arithmetic Operators
  - Assignment
* Conditional logic
  - branching
* Code block
* Literal (vs variable)

give you huge power because these are **common ideas in programming**. If you know how to look for these things in a **new language** you'll find them, and the language will open up very quickly.

## Summary

Ths week we learned how to make comparisons between values, and then to decide what action to take. We matched the idea of **processing** and the use of **operators**.

We discussed the importance and power of names.

## Homework

### Flowgorithm Guessy 

Lets implement the same game in **_Flowgorithm_**, using our new understanding of programming ideas.

1. Grab _Flowgorithm_ (windows 64 bit) from the their [downloads page](http://flowgorithm.org/download/index.htm).
2. Open it, it should start with a new flowchart (main -> end).
3. Click the arrow between (main -> end) and choose _declare_
4. Name the variable `secretNumber`, and set it to `integer` in the drop down.
5. Assign it a value.
6. Continue on to make the rest of Guessy Number.
7. Run Guessy Number and try a valid and invalid guess. Screenshot the output window (not your flowchart!) and paste it into the *Discord* `#class-ise102` chat.
   
{{< imgcard flow_guessy Link "flow_guessy.png" >}}
Fill in the blurry bits. (click if the flowchart is too small to read)
{{< /imgcard >}}

### Reading and programming
  
1. Read the rest of [Chapter 1](../resources/cpp_through_games_1.pdf) of the textbook, where you'll learn about arithmetic operators, data types and more.
    - Take notes
2. Read [Chapter 2](../resources/cpp_through_games_2.pdf) up to a **page 48**
    - Take notes
    - Create another project *score_rater_3* and **type and run** the code on **page 47**.

### Submission

Make sure you've pasted your flowgorithm output into the Discord chat as described above.

When you've completed typing and running the code in the text book **submit the `score_rater_3.cpp` files**. 
   * Email to Danny with the subject _"ise102 homework week 2"_
   * Danny's email will be sent to you via Blackboard announcements (and _Discord_).

{{< alert title="Where's my source code?" color= "secondary" >}}
You can find the `.cpp` file for a project in its **project folder**. For `guessy_number` you'll be looking for `guessy_number.cpp`.

* If you're following our class conventions, those project folders will be in `ise102/code/week2`.
* If you aren't sure were to find it or just want to go there from within Visual Studio, right click the project name in the _solution explorer_ panel and go to _open folder in file explorer_.
{{< /alert >}}
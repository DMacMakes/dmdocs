---
title: "8: Finalising Slots"
linkTitle: "W.8 Final Slots"
weight: 80
description: >
  User experience, submission of projects.
resources:
  - src: "dad_car.jpg"
    params:
      byline: "Credit: http://annx.asianews.network"
---

## What are we learning today?

1. The next level of **abstraction**: the `playSlots()` function.
1. Project management using sticky-note style _**agile/kanban** board_.
1. Adding colour with **_colorterm.h_**

<!--

## Delivering Your Assessment

* If anything is going to stop you delivering on time, reach out/request extension BEFORE the day it's due.

Visit the link, follow the instructions there carefully!!

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../assessments/#assessment-2-slot-machine" target="_blank">Delivery (Zip) File Creation on dmdocs<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

-->

## Assessment 2 progress

**What's done?**
* Screens, menu loop (if homework done)
* `playSlots()` function dummy structure is there
* Some real playslots structure basic user inputs of bet
* Good formula for calculating new cash amount, it's returned to Menu.

### What's left to do?
This will be easier [using Trello](https://trello.com/b/aETa5OZN/slotsot2):

{{< imgproc trello_slotso_w8 Resize "700x" Link "https://trello.com/b/aETa5OZN/slotsot2" >}}
Click the image to visit the board.
{{< /imgproc >}}

## Exit and Credits screens

Skipping these is a terrible idea. You're here to make games, and games are made to engage and entertain. EASY MARKS.

---

## Pseudocoding Playslots

Play Slots is different to the other screens, it hosts the actual game itself. As such it has more work to do, and is more complex.

**How do we deal with complexity?** We break it up/abstract it into smaller jobs, and send it to functions.

![](pstasks.png)

First, think of it at the topmost level:

{{< alert title="Psuedocode: playSlots() outline" color= "secondary" >}}
Keeping it pretty abstract, again half way between a bullet list and pseudocode.

Make sure you understand this before you go further!

```
START playSlots (needs: players cash amount to start)
  Get valid bet from player.
  Remove bet from playerCash
  Make and display random numbers
  Set bet multiplier based on win/loss by matching random numbers
  Add (bet times multiplier) to playerCash
  Tell players the outcome
  return playerCash value 
END playSlots
```
{{< /alert >}}

### Pseudocode comments in playSlots

Fleshing it out further, and getting closer to code:

```cpp
// Provides the whole slot game experience
// Takes in player's available cash as an argument
// returns their new total available cash amount after winning/losing
int playSlots(int playerCash)
{
  cout << "========= SPIN TO WIN! ===============\n";
  cout << "===== Your Cash: $ " << playerCash << "\n\n"; 

  // DON'T LEAVE ALL THESE LONG PSEUDOCODE COMMENTS IN YOUR FINAL SUBMISSION.

  // -------- GET BET ----------------------------------------------
  //  Should be one line, call a function, store bet it returns.
  //  Get user bet, check that it's valid, so.. getValidBet, returns a bet that we can 
  // expect to >$0 and <=$playerCash, can't bet what you don't have. Function will 
  // need to know player's cash to check they don't bet above it..
  //  bet = getValidBet(playerCash)
  int bet = 200;  // /dummy bet
  
  //  player cash = player cash minus bet  // (you always pay to play)
  playerCash -= bet;

  // make and save 3 random numbers in range 2-7
  // Give numbers to a function that displays them pretty
  
  // ----- Check for a win and figure out the multiplier to apply to the bet
  // Give the 3 random numbers to a function that checks if they are 
  // winners or losers. Whether it's a win or loss, get back the multiplier:
  // 0, 3, 5 or 10. Those numbers are meaningless on their own so create constants
  // that say what each multiplier means like PAIR = 2 and THREE_SEVENS = 10.
  // An enum would be perfect.

  // multiplier = check for wins ( 3 random numbers )
  int multiplier = 0; //  = NO_WIN
  

  // Calculate their winnings: the bet times the multiplier. 
  // Add their winnings to their cash total. 
    // Note: If they didn't win this number will be 0 so no need for an if statement. 
          // Their bet was already taken from total, so loss is already handled.)
  
  //  Display win/loss info (You can check the multiplier to see what the outcome was)
  cout << "You lost!\n"; 
  cout << "You now have $" << playerCash;
  
  // -------- Play Again: nice to have. Press <esc> for menu, <space/whatever> play again
  // Tell player "Press <space> to to play again or <esc> to return to the main menu
  
  cout << "\t\tHit a key to go back to the menu . . .\n";

  // Wait for the any key.
  _getch();
  // int pressed = _getch();  // play again version
  
  // Play again feature would need a loop here:
  // While the pressed key was not <escape>, loop back up to near the top of this function.
  // (need to put the `do` of this loop at start of function.

  return playerCash;
}
```

### The bet

There are two cards related to making a bet. There's an obvious repeat in the job too. 

{{< imgcard pstasks_1_bet Link "pstasks_1_bet">}}
From the <i>Trello</i>. Maybe these two can go in a function together.
{{< /imgcard >}}

{{< alert title="Psuedocode: playSlots() calls getValidBet()" color= "secondary" >}}
In `playslots()`, we'll do the equivalent of making a wish. We'll pretend we have a function to do the work for us, and describe it.

```
//... inside playSlots()
  // -------- GET BET ----------------------------------------------
  //  Should be one line, call a function, store bet it returns.
  //  Get user bet, check that it's valid, so.. getValidBet, returns a bet that we can 
  // expect to >$0 and <=$playerCash, can't bet what you don't have. Function will 
  // need to know player's cash to check they don't bet above it..
  // bet = getValidBet(playerCash)
  int bet = -200; // dummy bet for now

```
Looks good! So we need a function:
```
FUNCTION getValidBet
needs: playerCash
returns: a valid bet in dollars
```
{{< /alert >}}

### Randoms

We need to make 3 random numbers. They'll have to be displayed and then compared to see if they're a winning combo. That means storing them. 

{{< imgcard brief_randoms>}}
From the assessment brief pdf.
{{< /imgcard >}}


{{< alert title="Pseudocode: playSlots() with randoms" color= "secondary" >}}
Since we don't yet know how to get 3 values back from a function, we'll have to request them one by one in playSlots.

```
START playSlots (playerCash)
  // Get valid bet from player becomes:
  bet = getValidBet(needs player Cash)

  rand1 = a random in the range 2-7
  rand2 = another random in the range 2-7
  rand3 = another random in the range 2-7
  
  display the numbers on cards/pokie wheels/whatever
  ...
```
Let's make a wish again! Those lines could become:

``` 
rand1 = getRandInRange(2,7)
rand2 = getRandInRange(2,7)   // and so on
```

You can guess what our function definition might look like 

```
FUNCTION getRandInRange
needs: lowest number and highest number
returns: a random integer in that range, inclusive.
```
{{< /alert >}}

You can hopefully see how starting at a high level of abstraction begins to make the next level down pretty obvious. It's _never_ true the other way around - making low level functions without a plan and then trying to fit it all together is a nightmare.

### Testing wins, setting multipliers.

When we check for a win we only need to know one thing in order to calculate winnings: what was the multiplier? 

The job we need done then is:
1. Take multiple inputs (the 3 random numbers we have already stored)
2. Compare them and check for win conditions.
3. Tell me what multiplier is appropriate: 0x (loss), 3x (Pair), 5x (triple) or 10x(triple7)

{{< alert title="Pseudocode: playSlots() with win test" color= "secondary" >}}

```
START playSlots (playerCash)
  // Get valid bet from player becomes:
  bet = getValidBet(needs player Cash)

  rand1 = a random in the range 2-7
  rand2 = another random in the range 2-7
  rand3 = another random in the range 2-7
  display the numbers on cards/pokie wheels/whatever

  multiplier = checkForWin(rand1, rand2, rand3)

  ...
```
The arguments for checkForWin are just 3 numbers, but it'll help if we use something more meaningful than `number1, number2,number3` or `x,y,z`.

You can call them wheel, as in the spinning wheel on the machine, or card since they're numbers represending cards  in poker(thus _poker machine_).

```
FUNCTION checkForWin
needs: 3 numbers (wheel1, wheel2, wheel3)
returns: a multiplier, preferably matching a meaningful constant? hint: enums

{{< /alert >}}

### Calculating winnings, returning new cash total.

According to the brief, the amount you win is a multiple of your bet. We can just add that to the player's remaining cash (we've already subtracted the bet). Finally, we return it.

{{< imgcard brief_multipliers>}}
From the assessment brief pdf.
{{< /imgcard >}}

{{< alert title="Pseudocode: playSlots complete" color= "secondary" >}}

```
START playSlots (playerCash)
  // Get valid bet from player becomes:
  bet = getValidBet(needs player Cash)

  rand1 = a random in the range 2-7
  rand2 = another random in the range 2-7
  rand3 = another random in the range 2-7
  display the numbers on cards/pokie wheels/whatever

  multiplier = checkForWin(rand1, rand2, rand3)
  playerCash = playerCash plus (bet times multiplier))
  Tell player about win/loss, new total etc
  
  Prompt player to hit key, return to menu.
  return playerCash
END playSlots
```
The arguments for checkForWin are just 3 numbers, but it'll help if we use something more meaningful than `number1, number2,number3` or `x,y,z`.

You can call them wheel, as in the spinning wheel on the machine, or card since they're numbers represending cards  in poker(thus _poker machine_).

```
FUNCTION checkForWin
needs: 3 numbers (wheel1, wheel2, wheel3)
returns: a multiplier, preferably matching a meaningful constant?
hint: enums (look at MenuChoices)
```
{{< /alert >}}

{{< imgcard pstasks>}}
I remember to check the Trello cards too.
{{< /imgcard >}}

## Filling in getValidBet

For this to work, the player should:
1. Know what to input: what a valid(correct) bet is.
2. Be told if they make a mistake, and what it was.
3. Be prompted again for a valid bet.

{{< alert title="Pseudocode: getValidBet in detail" color= "secondary" >}}
It's a lot like the menu functionality from week7. It loops, has valid and invalid input to test for, and an error needs to be displayed.

**Week 7 menu:**  
<a href="displayMenu_wk7.png" target="_blank"><img src="displaymenu_wk7.png" width = 400 /></a>

**getValidBet** function as mostly pseudocode comments.

```cpp
// Get a valid bet from the user (more than $0, and no more than the
// user actually has). Returns the amount that was bet.
// If the user enters an invalid bet they are told so, how to do better,
// and asked to try again until they succeed.
int getValidBet(/*pass in the player's total cash*/)
{
  int bet = 0;
  // string error

  // do in a loop..
    // Ask user to bet. Show an error message and more info if this
       // isn't their first try.
     // clear any previous errors
    // Receive the bet amount
    // if it's more than nothing and no more than they have (affordable)
       // it's fine, no error, can return the bet.
    // otherwise
      // Set an error message
  // while there's still a non-empty error message, keep looping till they make no errors

  // return the bet. // note if we use return in the loop we'll never have to get this far.
}
```

{{< /alert >}}

## Check for wins

"Winning" in our game is based on something like simple Poker hands (two of a kind, three of a kind) with a special bonus hand (three 7s). Checking for a win then is a pretty straightforward bit of comparing using our boolean operators `&&` (AND) and `||` (OR).

There are *a lot* of ways to compare these three cards/numbers to check for three 7s, a pair etc, I'll just loosely outline a couple of them here.

```
START checkForWins (card1, card2, card3)
  int multiplier
  if three cards show sevens 
    multiplier is 10 (great idea to use a constant/enum THREE_SEVENS to represent 10)
  otherwise if three cards are the same
    multiplier is 5
  otherwise if there's a pair
    multiplier is 3  
  
  return multiplier.
END checkForWins
```

Using multiple return values:

```
START checkForWins (card1, card2, card3)
  if three cards are the same
    if three cards are 7
      return 10 (THREE_SEVENS)
    otherwise
      return 5
  otherwise if just two cards are the same
    return 3
  otherwise 
    return 0

END checkForWins
```

```cpp
// Receives 3 ints in range 2-7 representing the cards/wheels in latest spin.
// Returns a multiplier for the win type (no win, pair, three of kind, three sevens)
// (We define an enum for this, WinMultiplier)
// checkForWins(card1, card2, card3)
//{
  //return 0; // NO_WIN
//}
```

<!--

TODO: checkforwin would be very useful. My descriptions before were a bit eh

## Filling in checkForWin

lorem
1. ipsum
2. dolor

{{< alert title="Pseudocode: checkForWin " color= "secondary" >}}
Lorem ipsum.

```
START checkForWin( wheel1, wheel2, wheel3)
  storage

  processing

  return something
END checkForWin
```

{{< /alert >}}

-->

## More about what to submit.

Academic integrity, demonstrating what you've learned in class, not submitting broken solutions.

 <a class="btn btn-lg btn-primary mr-3 mb-4" href="https://trello.com/b/aETa5OZN/slotsot2" target="_blank">Avoid submission dangers: Trello<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## Random numbers in a range?

`rand()` generates random numbers between 0 and.. whatever your compiler defines as the maximum. You can access that number in the constant `RAND_MAX`. To convert any number in one range to a number in another range we can use percentages. 

Let's imagine that number is 16, and our random number is 8. What percentage of 16 is 8? You probably all thought "50%", but it came to you fairly automagically. The formula you learned in school and are unconsciously applying is 

**n / range_max = ratio ( between 0 and 1).**

A ratio is just a percentage expressed between 0 and 1. To convert to 0-100 we times by.. 100. 

**0.5 * 100 = 50%.**

### General rule for converting ratio to another range.

So, we just multiply the ratio by something other than 100.. say 16, to get the number in that range.

**0.5 * 16 = 8**

**0.2 * 10 = 2** or..

**ratio * range = number representing that ratio in that range.**

### So to convert our 0-RAND_MAX to another range..

**n / range_max** becomes **rand() / RANGE_MAX**. 

#### but the answer is always 0.
Divide an int by another int, you get an int. You need to *cast* the ints to floating point numbers for a floating point result.

{{< alert title="Casting data from one type to another" color= "primary" >}}
Think of the phrase "type cast". It means an actor is always cast to play a certain type. In the 90s Gary Oldman was cast as "character who is well spoken and slight in build but GETS VERY SHOUTY AND SCARY."  

<img src="oldman_zorg.jpg" height=400 />  
*Gary Oldman as Zorg in The Fifth Element*

Casting in C++ forces one type of data to become another, like an int to a float. We write: `float(myInt)`, and it gives us the floating point version of `myInt`. It's just using the type name like a function.

```cpp
int eggs = 6;
int dozen = 12;
int noGoodRatio = eggs / dozen; // = 0
float eggsDozenRatio = float(eggs) / float(dozen); // = 0.5
```
{{< /alert >}}

### Ratio to new range

Multiply any ratio from 0.0 to 1.0 by, say, 16, and you'll get a new float between 0 and 16. We **don't** want to just cast the new value to int though, because that'll just cut off the decimal points (5.9 becomes 5). 

Use the `<cmath>` header's `round()` function. Annoyingly, that returns a float instead of an int (12.0, or 100.0, etc) so we have to turn that into an int. Fortunately, we can just assign to an int.

```cpp
// You can assign the result of the roundl to an int and you'll
// be just cutting the .0 off the end of your rounded float.
int eggRatioAppliedToSoccerTeam = roundl(11 * eggsDozenRatio);

// or you can be more pedantic/careful like so:
int eggRatioAppliedToSoccerTeam = int( roundl(11*eggsDozenRatio) );
//.. the fun never ends.
```

### Pseudocode

```cpp
// randAsRatio = float(random number) over float(rand max).
// Rand between 0 and 20 = round to nearest whole( randAsRatio * 20 )
```

## Add Colour With Termcolor

What does it achieve, and how do can you add it?

{{< imgcard output_termcolor_menu Link "Termcolor_sample.zip">}}
Menu (older code) with some basic colour added.
{{< /imgcard >}}

### Visual Communication

It's not pretty but it's easy to parse, so it's easy to play.
  - Colour blocking to separate title and current cash from menu
  - Green to evoke cash for the player money (association)
  - Hilighted the menu numbers to call player to action
  - Used the same magenta to associate the input area with the menu numbers.

### Using The Library:

Download the visual studio solution first:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="Termcolor_sample.zip">Download Termcolor_sample.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

  * Including termcolor in main.cpp
  * accessing the constants it uses for colour
  * using termcolour's reset function

{{< imgcard code_termcolor_menu Link "Termcolor_sample.zip">}}
{{< /imgcard >}}

## Exercise: Add colour to your menu.

### Getting The Library

Add `termcolor.h` to your own assignment by **right clicking** the `termcolor.h`, clicking _Save link as.._ and saving to your assessment's project folder.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="termcolor.h">Download termcolor.h<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### Making The Library Available

Just having it in your project/solution folder doesn't make `#include` work.

In _solution explorer_, right click _Headers_, add existing, and select the `termcolor.h` file in your project folder.

### Usage

For more help, visit the [github homepage of termcolor](https://github.com/ikalnytskyi/termcolor) and scroll down to the README.

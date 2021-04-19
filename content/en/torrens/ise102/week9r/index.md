---
title: "Week 9 Review: Frames, input, objects"
linkTitle: "W.9R: Review"
weight: "95"
description: >
  String objects
---

## Using Objects
 
 Objects are a **types of data** in C++ that have more features than your basic types (`int`, `float`, `char`). Objects we've used so far include `string`, `cin` and `cout`.
   
### Objects can
  
Behave like a normal variable. Look at `string` for example:

```cpp
string fullName = "Princess Bubblegum";   // like initialising an int or bool
```

Also **behave like folders** that contain more variables and functions inside
  * We can access them by putting a dot `.` right after the variable name

{{< imgcard string_object_functions Link "string_object_functions.png">}}
The `string` object has plenty of useful functions.
{{< /imgcard >}}


The **output:**
```
        Your full name, Princess Bubblegum is 18 characters long.
        Is 'Princess' your first name? I like it.
```

{{< alert title="Dot Notation" color= "primary" >}}
You access variables and functions within an object by typing its  <b>variable name followed by a dot</b>. Intellisense will offer you a **list** of functions/variables for that data type. 

Here, it's `string`, and I've found a `length()` function:

<img src="string_intellisense.jpg">
{{< /alert >}}

#### Visualising string character positions

![string positions princess bubblegum](string_positions_princess_bubblegum.png)

## Exercise 2: String object functions

1. Create a C++ *console* project and **type the _Princess Bubblegum_** code into `main()`.
2. Now take the role of the interviewer. You still think "Princess Bubblegum" is a regular name.
   * Create a variable `lastName`. Use `substr` (substring) to **store the Princess's last name** in `lastName`.  
   * After your discussion of her first name, go to a new line and **complement her** on her last name. Mention it in the sentence.

{{< imgcard string_object_functions Link "string_object_functions.png">}}
This goes into main.
{{< /imgcard >}}

One **example:**

```
        Your full name, Princess Bubblegum is 18 characters long.
        Is 'Princess' your first name? I like it.
        I can't think of a lovelier last name than `Bubblegum`.
```

### Dive Deeper: String Functions

* `string::substr()` (substring) [documentation](http://www.cplusplus.com/reference/string/string/substr/) 
* `string::length()` [documentation](http://www.cplusplus.com/reference/string/string/length/)
* `string` object [documentation](http://www.cplusplus.com/reference/string/string/)

## Other objects
  
  Ojects also: 
  * Exist in the C++ libraries: `string`, `cout` 
  * Are things we can create to suit our own programs.
  * Can be made to represent anything you need

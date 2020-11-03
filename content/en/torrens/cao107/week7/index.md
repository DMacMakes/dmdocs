---
title: "Week 7: Loader"
linkTitle: "7: Loader"
weight: "70"
description: >
  Sound? In Linux?
---

## Double-updated base!

Like the base below, but this one has:
1. Timer files included (timer.cpp, timer.h)
2. Includes libraries_cpp, containing sound libaries (dev and playback)
3. Todo: comments showing where you can add the sound library code.
4. A new MLoad_Sound struct. ImageTexture has been renamed MLoad_Image to match.
5. Big tif images to load
6. 3 sample wav files, 3 mp3 files.

Note: you need the timer, dmgui, sln and proj files from this project, also parts of main.cpp (mainly around the includes).

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/EYzfbd90TelGn-TGUM5hgi8Bae6WYCzYQwZnmg8CsTJjxA?e=YI41NP" target="_blank">Download w7-base-with-sound-libs.7z<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## Updated base (example, use what you need)

1. Download this new base:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/EZAodsMjJQlLmjmwWau6B48B0ulDLZlNYSrr8SODYFQ3dg?e=Yt4U5n" target="_blank">w7_base_media_loader.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

2. Unzip into a folder called `loading` in your `cao107/weekly_code/week7` folder
3. Copy the `libraries_cpp` folder you already have into the same root (week7 folder)

End result:
cao107/week7/loading/hw-w6-media-loader
cao107/week7/libraries_cpp

### What is the base?
A base for people who've fallen away (fresh start, can mark on the additions from here) plus marks for having achieved up to here.
- loads an image, opens a window
- closes on click
- contains options object to handle the checkboxes added to a unique options menu. Feel free to take that for your own project. 
- Removal of statics. 
- Shorthand if statements.

### Opening closed windows

Together, _add a button_ that opens that window once closed.
Loading more than one image? Use a vector of ImageTexture and push loaded images to it.
You can load an image each time the file dialogue opens, or look up the documentation for _ImGuiFileDialog_ and load several at once.

## Assessment 2

Due: End of Week 8 (Sunday 11:55pm)

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../assessments/#assessment-2-multi-threaded-loader" target="_blank">Details on Assessments page<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## How do we load sound?
We can add sound to this one, people who already have their code base advanced can copy over the code from this to theirs when done.

_What does it mean to load and play a sound?_ What's involved at system level? How is SDL saving us work?

## What actually is SDL?

<https://www.libsdl.org/index.php>
<https://wiki.libsdl.org/FrontPage>
<http://lazyfoo.net/tutorials/SDL/index.php>
<https://www.libsdl.org/projects/SDL_mixer/>

What is SDL abstracting for us? What does it depend on?

_question:_ Is anyone lost on pointers? (One on one chat? pointers class?) If so, have you tried studying up on them somewhere? What issue do you think you're having with them? 

## Homework

I won't be specifying hard requirements for homework this week, instead I need you to make strong progress on the image loading and threading part of the assessment:

**Images:** _finalising.._
Load multiple images
- open by default
- top left and cascading (try adding n pixels to the x and y position of new window first creation)
- list with buttons
- allow multiple image select in dialog

**Threads:**
Text how/if the program bogs down loading large/multiple images. Bring in the timer from assessment one to get yourself real data.
- Immediate mode gui runs at 60 fps.
- Loading a large image or sound, loading many images at once..
- does that make interface responsive?
- how long does it take?
- If so, how can we fix that with regular threads?
- How do you avoid accessing images before they’re fully loaded?
- Does the solution lock the entire vector of images/sounds? How can you avoid that?

Your challenge now is to **manage your workload** and not fall into taking a week off, or you'll be in a dire place next week (a half week from deadline). **Reach out on Discord** if you have questions, and I'll see you in work review class.

PS: **Sound **- I'll work on getting SDL-mixer into the libraries and let you know the visual studio settings to integrate them (I may give new sln and .proj files out too)

<!--

## Bonus: References and pointers videos?

## Bonus: Compiling in Linux. Installing the required libraries
1. Copying your files to the Linux virtual machine. VmWare share folder. Recco: zip it on windows side first, then copy over, unzip.
2. Try compiling, show there are errors re: missing libraries. Visual studio's compiler and g++ handle this differently. I've sorted out the Makefile but we need the libraries installed at system level on Linux.
3. sudo apt install libSDL2-dev, sdl2 image, imguifiledialog, mixer? #!cao107.

-->
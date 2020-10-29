---
title: "Week 7: Loader"
linkTitle: "7: Loader"
weight: "70"
description: >
  Sound? In Linux?
---

## Updated base (example, use what you need)

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/EZAodsMjJQlLmjmwWau6B48B0ulDLZlNYSrr8SODYFQ3dg?e=Yt4U5n" target="_blank">w7_base_media_loader.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

A base for people who've fallen away (fresh start, can mark on the additions from here) plus marks for having achieved up to here.
- loads an image, opens a window
- closes on click
- contains options object to handle the checkboxes added to a unique options menu. Feel free to take that for your own project. 
- I've reduced number of functions and removed statics.
- Added path name to the string (getting rid of statics)
- `using namespace DmGui;` added to reduce clutter
- lots of if braces removed to make it shorter.
  - Shorthand if statements.

### Opening closed windows

Together, _add a button_ that opens that window once closed.
Loading more than one image? Use a vector of ImageTexture and push loaded images to it.
You can load an image each time the file dialogue opens, or look up the documentation for _ImGuiFileDialog_ and load several at once.

## Assessment 2

Due: End of Week 8 (Sunday 11:55pm)

Load multiple images
  - open by default
  - top left and cascading (try adding n pixels to the x and y position of new window first creation)
  - list with buttons
  - allow multiple image select in dialog
  - can you add jpg/tif support?

Load multiple sounds
  - use SDL mixer
  - ready to play on load (don't play)
  - a button for each to play
  - extra features
    - per sound mute
    - per sound volume
    - overall system volume

Large files!
  - Immediate mode gui runs at 60 fps.
  - Loading a large image or sound, loading many images at once.. 
    - does that make interface responsive?
    - how long does it take?
  - If so, how can we fix that with threads?
    - Can try with regular threads
    - Can try with boost pooled threads
    - How do you avoid accessing images/sounds before they're fully loaded?
    - Does the solution lock the entire vector of images/sounds? How can you avoid that?
    

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
## Bonus: References and pointers videos?

## Bonus: Compiling in Linux. Installing the required libraries
1. Copying your files to the Linux virtual machine. VmWare share folder. Recco: zip it on windows side first, then copy over, unzip.
2. Try compiling, show there are errors re: missing libraries. Visual studio's compiler and g++ handle this differently. I've sorted out the Makefile but we need the libraries installed at system level on Linux.
3. sudo apt install libSDL2-dev, sdl2 image, imguifiledialog, mixer? #!cao107.
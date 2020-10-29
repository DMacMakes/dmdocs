---
title: "Week 7: Loader"
linkTitle: "7: Loader"
weight: "70"
description: >
  Sound? In Linux?
---

Bits:

**FILE:** zipped latest imgui_loader

Hand out a base for people who've fallen away (fresh start, can mark on the additions from here) plus marks for having achieved up to here.
- loads an image, opens a window
- closes on click
- contains options object to handle the checkboxes added to a unique options menu. Feel free to take that for your own project. 
- I've reduced number of functions and removed statics.
- Added path name to the string (getting rid of statics)

Together, _add a button_ that opens that window once closed.

_How to load sound?_
Together we add sound mixer library support to the windows version.

Learning from _LazyFoo_ tutorials
Looking at SDL2 wiki for reference

We can add sound to this one, people who already have their code base advanced can copy over the code from this to theirs when done.

_What does it mean to load and play a sound?_ What's involved at system level? How is SDL saving us work?

Look at what _SDL actually is_ and does. What is it abstracting? What alternatives exist? SFML. Whichever of glew or glfw or whatever does it too.

(Remaning to do: you guys add them to a list/table using imgui?)

What's due in total?
Loads multiple images in a list
Loads multiple sounds into a list
Images auto open on load in a window starting top left and cascading (try adding n pixels to the x and y position of new window first creation)

_question:_ Is anyone lost on pointers? (One on one chat? pointers class?) If so, have you tried studying up on them somewhere? What issue do you think you're having with them? 
Bonus: References and pointers videos?

Bonus: Compiling in Linux. Installing the required libraries
1. Copying your files to the Linux virtual machine. VmWare share folder. Recco: zip it on windows side first, then copy over, unzip.
2. Try compiling, show there are errors re: missing libraries. Visual studio's compiler and g++ handle this differently. I've sorted out the Makefile but we need the libraries installed at system level on Linux.
3. sudo apt install libSDL2-dev, sdl2 image, imguifiledialog, mixer? #!cao107.
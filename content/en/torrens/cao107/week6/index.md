---
title: "Week 6: Loading and playing media"
linkTitle: "6. Media"
weight: "60"
description: >
  What happens when we load an image or a sound? How can we control that across operating systems?
---

## Assessment 2: Loading and playing media

Loading images and sounds. Displaying and playing.

Steps:
  1. Browse for and choose
  2. Load into memory
  3. Decode
  4. Decompress?
  5. Send to display

### What's really involved?

### On Windows

### On Mac

### On Linux

### Cross Platform then? Impossible?

## Code: Base_imgui

{{< imgcard Base_imgui_running >}}
What you'll see when you run the project.
{{< /imgcard >}}

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/EW63GlqCx0RDls2upO3B6gcB323l_Vzo-97WA97XJto3Vw" target="_blank">Download Base_imgui.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

Unzip the contents into a folder, you'll see `libraries_cpp` and `weeks_5-8`.
Go into `weeks_5-8\Base_imgui` and double click `base_imgui.sln`. 

Set build type to _Release, x86_ in the main toolbar of visual studio, hit **ctrl+F5** to run.

## Homework

Explore the provided _Base\_imgui_ project, and add the functionality described below. This homework requires you to research the libraries I've provided, and to dig through the code and make discoveries. It'll also help to read about _Immediate Mode GUIs_.

1. Look through demo window features both in the running program and in code, see how they work.
2. Add two checkboxes to the Media Loader window, _Load with thread_ and _Multiple threads_. They don't have to do anything yet.
3. The ImFileDialog library is being used to pop a new file browser when you click _File->Load images_ in the Media Loader window menu bar.
  * Configure it to show only image file types for selection. Look into the window flags and file extension masking.
  * The dialog already returns a string with the file path in it. Use the sdl2_image library to load an image when one has been selected in browser and the user has clicked OK.
  * You've loaded an image with sdl, now create a new window in imgui to display it.
4. Bonus/nice to have: Allow selecting of multiple images. Drop their names into a table, with a button beside each to open them for viewing.
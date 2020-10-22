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
  1. Browse for and choose a file
  2. Load into memory
  3. Decode
  4. Decompress?
  5. Send to display

## What's really involved?

Start with computer with an operating system.

### 1. Browse for and choose
1. Windowing, file browser on a gui (graphical user interface): some sort of interface for browsing for files.
1. A mouse or keyboard to open the browser and select a file. 
1. File is on some physical storage: HDD or SSD or thumb drive or cloud storage or Micro SD card or a CD.
1. Driver software that can turn physical attributes of the storage medium and movements of read/write head etc into useful information we can read.
1. What is 01010011111000010101100101010101010010010011? What makes that into files and folders? Drive has to be formatted with a file system. 
   Windows: FAT32, NTFS. 
   Mac: HFS+, now AppleFS.
   Linux: EXT4, BTRFS
  
### 2. Load
1. Moving a file from the long term storage to memory. We need DIMMs (memory modules) and a bus that moves the data from the hard drive to the memory.
  Buses:
    - Sata: usually internal, sata3 gives 6Gigabits/s. PCIE bus.
    - USB: External, between 40MB/s up to 1GB per second.
    - m.2: nvme or sata protocol ends up on PCIE bus
2. Goes via pcie bus through Direct Memory Access to the ram

{{< imgcard motherboard_x99m_killer>}}
Motherboard: Moving images from storage to ram to cpu to ram to cpu to gpu etc
{{< /imgcard >}}

{{< imgcard nvme_m2_installed>}}
The NVME drive (a pcb) installed into m2 nvme slot.
{{< /imgcard >}}

### 3. Decode/decompress/put in window
1. Image header is read, assess the file type. Then, using a library that defines how that image type works, the image is decoded/decompressed in the cpu, then shunted back to memory.
1. Then you need an operating system's windowing library to display the image on screen. 

## Send to Display
1. Finally, this is sent via the pcie bus, with the help of the graphics drivers, to the GPU.
1. The GPU sends it to the display via HDMI/VGA/DVI/DP/Thunderbolt/Usb C.

### On Windows

File system: Fat32/NTFS 
Driver model: WDM
Limitations: Windows is 99% x86 architecture
Windowing: Win32 API
Multimedia/graphics libraries: Directx

Open alternatives exist for multimedia part: OpenGL, SDL2, QT, Imgui.

### On Mac
File system: HFS+, AppleFS
Driver model: IOKit/Driver kit
Limitation: Apple made computers. Unless you are running a Hackintosh, you are on apple made and sold hardware.
Multimedia/graphics: Metal API 
Windowing: Cocoa (appkit)
64bit: As of MacOS 10.15 your app has to be 64 bit.

### On Linux
Filesystem: Ext4
Driver model: Not really branded.
Limitation: Not friendly to casuals.
Upside: Runs on almost anything. x86, arm, other architectures, all supercomputers.
Windowing: X11 api (Gnome, KDE, Mate)
Multimedia/graphics libraries: OpenGL, Vulcan, SDL2 

### Cross Platform then? Impossible?
Hard! 
Cross platform does exist: openGL/Vulcan 

Our Solution, layers of abstraction:
Lowest layer:
  OpenGL: Talk to graphics card, display triangles, bitmaps.
  Boost: Thread pools
Middle layer:
  SDL2: Accessing files, accessing operating system/multimedia/graphics, controllers
  sdl2_image: Library for various image formats
Top layer:
  ImGui: Displaying visuals, reacting to clicks. All your typical program gui elements. Buttons, text areas, checkboxes, tables, text, tileable windows.
Helpers:
  ImGuiFileDialog: Browse files

## Code: Base_imgui

{{< imgcard Base_imgui_running >}}
What you'll see when you run the project.
{{< /imgcard >}}

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/EW63GlqCx0RDls2upO3B6gcB323l_Vzo-97WA97XJto3Vw" target="_blank">Download Base_imgui.7z<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/EXx4avVQkvZBmYSxe6h_sh0ByLgjBpf0Tcy9zSgONM9gig" target="_blank">Download Base_imgui.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

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
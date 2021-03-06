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

> - Lowest layer:  
>   - **OpenGL**: Talk to graphics card, display triangles, bitmaps.  
>   - **Boost**: Thread pools  
> - Middle layer:  
>   - **SDL2**: Accessing files, accessing operating system/multimedia/graphics, controllers  
>   - **sdl2_image**: Library for various image formats  
> - Top layer:  
>   - **ImGui**: Displaying visuals, reacting to clicks. All your typical program gui elements. Buttons, text areas, checkboxes, tables, text, tileable windows.  
> - Helpers:  
>   - **ImGuiFileDialog**: Browse files  

## Code: Your Media Loader base project 

{{< imgcard Base_imgui_running >}}
What you'll see when you run the project.
{{< /imgcard >}}

Your lecturer will provide you with the media loader base code.

Unzip the contents into a folder, you'll see `libraries_cpp_cao` and `cao107-loading`.
Go into `cao107-loading\media-loader-base` and double click `media-loader.sln`. 

Set build type to _Release, x64_ in the main toolbar of visual studio, hit **ctrl+F5** to run.

## Homework

Explore the provided _imgui\_load\_image_ project, and add the functionality described below. This homework requires you to research the libraries I've provided, and to dig through the code and make discoveries. It'll also help to read about _Immediate Mode GUIs_.

{{< alert title="Delivery" color= "primary" >}}
1. Copy and paste the two folders (libraries_cpp, weeks_5-8) into a new folder.
2. In the new copy of the Base_imgui folder, delete the usual visual studio folders (.vs, Release, Debug and x64)
3. 7zip the new libraries_cpp and weeks_5-8 folders. It'll reduce from 130+ megabytes to about 11mb. Call the file _cao107\_week6\_homework.7z_. Zip is fine as well.
4. Upload the file to cloud storage.
5. Email the link to Danny by Monday Night (_not_ Tuesday morning). Also describe what you did and didn't get finished in the email.
{{< /alert >}}

1. Look through demo window features both in the running program and in code, see how they work.
2. Add two checkboxes to the Media Loader window, ideally in an options menu: _Load with thread_ and _Multiple threads_. They don't have to do anything yet.
3. The ImFileDialog library is being used to pop a new file browser when you click _File->Load images_ in the Media Loader window menu bar.
  * Configure it to show only image file types for selection. Look into the window flags and file extension masking.
  * The dialog already returns a string with the file path in it when a user chooses and image and clicks _OK_. Create a `DmGui::ImageTexture` and use the `Load_Image_To_GLuint_Texture` function I've provided to load an image (usable with `ImGui::Image()`).
  * You've loaded an image, now create a new window in imgui to display it.
4. Bonus/nice to have: Allow selecting of multiple images. Drop their names into a table, with a button beside each to open them for viewing.

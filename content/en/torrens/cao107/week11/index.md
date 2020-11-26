---
title: "Week 11: Assessment 3 and using libraries" 
linkTitle: "11: A3+libs"
weight: "110"
description: >
  The full brief for A3, plus Q&A, tips. Also to make full use of the many features of computers and their operating systems without reinventing the wheel, you need to know how to find and integrate libraries.
---


## Libraries

It feels like we've been working fairly low level, and compared to a lot of styles of programming we have. Still we've been able to make cross platform, gpu accelerated, windowed applications that can load and play standard image and sound formats, deploy work to a GPU to run massively parallel, drawn plots, all in C++. Almost none of that stuff is supported in the C++ standard library without writing at least hundreds of thousands of lines of spending years reading white papers and specs. 

So, how? We're standing on the shoulders of other coders who've done the work and rigorously tested their code while using it in real production. Then they've compiled their code into libraries and supplied us with the header files to use them ourselves. This includes, by the way, large game and tech company staff contributions, along with open source communities on Github.

Tool/Library | Description
-------------|------------
C++ | Language plus standard libraries as our core.
Cuda/nvcc | General computing library and compiler for Nvidia GPUS, C++ extension.
gl3w | OpenGL cross platform initialiser (used by SDL2/ImGui) (see also freeglut, glew)
SDL2 | Simple Direct media Layer. Offers access to graphics and sound hardware, input and output, without having to write os-specific code or low level GL code.
SDL_Image | Extension library for SDL, allows loading of images
SDL_Mixer | Extension library for SDL, load and play sounds
Format libs | Various free libraries doing all the decoding and decompression of image and sound formats (complex, dry work): libpng, libjpeg, libmpg123,zlib
ImGui | gpu accelerated, frame based (immediate mode) gui.
ImGuiFileDialog | Adds a cross-platform file browser to ImGui
Others | usynergy, dirent

### How to leverage libraries

They offer huge power, but you have to understand a bit about what they are and how your compiler/linker/IDE work to use them.

1. Download the library files and put it somewhere on your disk
2. Read the documentation: how do you incorporate it? What binaries and source files do you need to access for windows, linux etc. What dependencies does it have (other libraries, OS level installs)?
3. Tell your compiler where to find the includes
4. Tell your linker where to find the binaries. (static vs dynamic)
5. Include the relevant headers in your code
6. Repeat 1-5 for any libraries the library depends on!
7. Finally, write the code that uses the library and compiles
8. If you've done everything write you have an executable. But, does it work?
9. If your library is _statically linked_ then it will be incorporated into your executable. The exe _should_ be able to run.
10. If your library is _dynamically linked_ then you'll need the runtime library (.dll or .so) to either be in the same folder as your exe OR in a system folder. Windows dlls, linux so files.

{{< alert title="Dynamic libraries on your system" color= "secondary" >}}
Executables would be gigabytes in size if they had to include the binary for every library they might ever use. They'd very often be bloated with the exact same code too.They'd also use a ton of memory, and you'd have to install a new patch/update to almost every app on your system each time microsoft patched/updated a library.

Have a look in:

1. c:\windows\system32 folder
2. The windows _Apps \& Features_ control panel. Type 'redist' in the search/filter box. Look familiar?
3. Install folders like C:\Program Files\iTunes and C:\Program Files\7-Zip
{{< /alert >}}

## Exercise: Downloading and integrating implot

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://github.com/epezent/implot" target="_blank">Go to implot on Github<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### Grabbing files, configuring project
1. **Get it**
   - Log in so you can click on the green "code" button to download a zip
   - Unzip it somewhere
2. **Put it somewhere your project will find it**
   - make a folder in libraries_cpp called implot
   - copy the files from your implot zip into here (not in a subdirectory)
3. **Tell your project where to look for header files, lib files**
   - Open your solution in visual studio 2019
   - Go to project properties
   - Go to _C/C++_ and look for additional include directories
   - add `..\..\libraries_cpp\implot;` to the beginning. The `;` semicolon separates it from other include directories
   - Go to _Linker_ and look for Link Library Dependencies. That's where you'd add any binary lib folders. Note the sdl2 lib path is in there.
4. **Choose which binary libraries to include**
   - Still in the project properties dialogue, go to _Linker/Input_ and look for Additional depencies. You should see a lot of lib files there including SDL2.lib, cudart_static.lib and plenty of windows libaries. This is where we'd add the specific lib binaries if we had them for implot.
5. Close project properties
6. **Make sure .h and .cpp files compile and intellisense works**
   - In solution explorer, right click your project and _Add -> New Filter_, name it implot
   - Right click the new filter/folder and _Add -> Existing Item.._
   - Navigate up to `libraries_cpp` and then into `implot`. Select all the `.h` and `.cpp` files. Hit ok.

### Including and coding
Hooray! Your project should now see the library. That was a fair bit to do the first time,but a) you'll get faster and b) it's a small investment compared to months/years of learning and coding. Also, c) now you know why _dependency/package managers_ (like _pip_ and _nuget_) and _build managers_ (like _make_, _CMake_, _ninja_ etc) are things.

1. Add `#include "implot.h"` to your main.cpp
2. In _Solution Explorer_ expand the _cao_ filter and double click `imgui_sdl_helpers.cpp` 
3. Look for `ImGui::CreateContext();`, and directly **beneath** it add `ImPlot::CreateContext();`
4. Look for `ImGui::DestroyContext()`; and directly **above** it add `ImPlot::DestroyContext();`
5. You should now be good to add a plot to your project!

### Adding a plot

{{< imgcard plot_scatter_demo>}}
The demo scatter plot in my creeper window.
{{< /imgcard >}}

1. Find the code in `main()` where you've been displaying your creepers.  
2. Go to the ImPlot live demo web site and look at Scatter Plots:   
   <https://traineq.org/implot_demo/src/implot_demo.html>  
3. In windows explorer open your `libraries_cpp/implot` folder, then open `implot_demo.cpp`. Any text editor will do, or you can open it in visual studio.  
4. Search for "Scatter Plot". Grab everything **inside** the collapsing header if statement. Don't copy the start or end of the if statement itself.
  ![](code_scatter.png)  
5. Past that in above the code for displaying your creepers.  
6. Run your project!  
7. If it doesn't work, **read the next bit on errors carefully.**  

{{< alert title="Fixing Errors" color= "danger" >}}  

1. We're all here to help  
2. **Ask for help only once you can provide information**. In Discord, Blackboard or in person, **avoid give vague reports** like "I have an error", "It didn't work" etc and leave it at that, because there's no info there to base an answer on. Anticipate the next question being "what is the error? What do you mean it didn't work? Can you be more specific?"  
3. Look at the **specific error** in the _**output window**_. Pick the bit that is least generic, seems like you could google it, and google it. Look around for common solutions.  
4. If you tried and can't solve it, provide me/the class with the **specific error** from your _**output window**_, and formulate a specific question. "It says it can't link symbols from SDL. Is that likely to be the lib files, my `#include` statement, something else? I think it might be X. Where do I start looking?"  
{{< /alert >}}  

### Plotting your own data

Look at how the plot works. What data does it need? An array of stuff for the x axis, another for the y? Well, you better copy some of your creeper data over to some handy, plottable arrays. Do it when the data changes (original roll, spells, re rolls), NOT every single frame.
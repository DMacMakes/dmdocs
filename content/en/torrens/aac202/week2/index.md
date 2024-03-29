---
title: "2: Cleaner ZBrush"
linkTitle: "2. Clean ZBrush"
weight: 20
description: >
  Working clean: subtools, automasking, base meshes, remeshing.
resources:
- src: "*patri*"
  params:
    byline: "Art: Patri Balanovsky (Artstation)"
---

<!--  

## Last Week's Homework

Madballs: 2 hours of try-harding.

Q&A
1. What was easy to do on Madballs in ZBrush?
2. What was hard to do in zbrush?
3. Got stuck in a weird mode?

Today we'll learn to do things that were hard with the basic subdividing workflow.

(Doing stuff close together, clean work with crisp transitions, eyeballs and eyelids!)

-->  

## What are we learning today?

You'll learn how to:
* make cleaner, more professional looking models.
* create a wider variety of silhouettes and shapes 
  * without worrying about stretching
  * without needing as many divisions
* work from basemeshes for fast, clean, on-model results

## Assessment 1: Character Sculpt
Look at order of assessments, brief.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../assessments" target="_blank">aac202 assessments<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## Beyond Pushing Clay
More than just adding and removing clay. Now we take advantage of digital tools.

{{< imgproc res_ztools Resize "650x">}}
Stylised human basemeshes.
{{< /imgproc >}}

## Follygon's ZBrush Process

{{< youtube cYE_bVG98OQ >}}

## Modelling from existing base mesh

A base mesh is essentially a reusable block out: a whole made out of smaller, simpler pieces.
- don't have to worry about joining and topology
- can edit pieces safely without messing up neighbouring anatomy.

Brice Laville Saint Martin doing it:

{{< youtube "Ay-UY6JTbF4" >}}

### Preserving important details around the eye

Sometimes having everything in one mooshy, continuous mass makes life hard. Consider eyes:

<!-- ## ---------- BETTER IMAGE?? ----------- -->  

{{< imgcard moana_disney Link "https://www.pinterest.com.au/dmacdraws/aac202/">}}
Moana's lower lids are more visible as she looks upward. Also visible are the thick edges of her upper lids.
{{< /imgcard >}}

* **Eyeballs**, apart from a bump on the front, are **perfectly round**, glossy balls. 
    * Maintaining perfect shapes is hard in sculpting.
* **Eyelids** criss cross them at strange angles depending on expression and genetics.
    * Humans are sensitive to the slightest movement of eyelids and brows.
    * As a modeller you need to change them constantly.

To freely modify one while leaving the other perfect, **we need different surfaces**.

{{< imgproc bust_chef_pixar Resize "500x" Link "https://www.pinterest.com.au/dmacdraws/aac202/">}}
This real clay chef sculpt from Pixar is extremely stylised. You can see the eyes and lids are not sculpted out of the main mass.
{{< /imgproc >}}

## Cleaner madballs

It was tough to avoid smushing the eye when doing gross eyelids, or to avoid destroying lips while sculpting teeth.

{{< imgcard dn_madball Link "https://laustu.sharepoint.com/:u:/r/sites/largefilecurriculum/AAC202/dn_madball_class_handout.zip?csf=1&web=1&e=tkt6GN" >}}
David's clean base with subtools. Let's gross it up.
{{< /imgcard >}}

Grab David Neselius' Hornhead sculpt from week 1 (thanks David) and we'll explore easier ways to model where hard and soft things collide.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laustu.sharepoint.com/:u:/r/sites/largefilecurriculum/AAC202/dn_madball_class_handout.zip?csf=1&web=1&e=tkt6GN" target="_blank">Download dn_maddball_class_handout.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### Using masking and subtools to stay clean

Ctrl+left mouse drag to mask.
Ctrl+alt+left mouse drag to erase mask.
Ctrl+left moue drag on background to clear mask. **Warning: disable dynamesh (click big orange button on bottom left of zbrush ui**

### Exercise: infected horn

{{< imgproc horn Resize "400x">}}
Nathan Tucker's in-class horn infection 👍
{{< /imgproc >}}

Use masking to protect the horn while you gross up the surrounding flesh with your usual brushes. Don't forget *inflate*, *standard*, *damien standard*.

### Tools and Subtools

To access the new files in _ZTools_ we'll start ZBrush and use the _lightbox_. It usually opens when ZBrush starts. If it doesn't, hit comma `,` or click the _lightbox_ button, top left.

{{< imgproc lightbox Resize "800x">}}
Projects, models, materials, brushes that don't load with ZBrush can be loaded from the lightbox.
{{< /imgproc >}}

<!--  

### Load and save subtools

A Tool can have multiple subtools. While you're in a ZBrush project you can load in new ones or save them out. 
1. Let's load our whole, merged pipehead from a ztl file.
2. Load pipehead again, this time as separate subtools from another ztl file.

{{< imgproc subtools_jaw Resize "800x">}}
Jaw is a subtool of our character tool. Note the ear subtool has two meshes.
{{< /imgproc >}}

-->  

| Category |  Definition/Place                            |
|-----|-----                                              |
| Tools | Objects in the Tools palette.                   |
| Subtools | Objects in the Subtools list                 |
| Meshes   | Shells of contiguous polygons. Found inside subtools. |

{{< alert title="Definition: Subtools" color= "primary" >}}
A bit like objects in Maya. Can have multiple meshes.
{{< /alert >}}

### Exercise: infected eyesocket

{{< imgproc eye_socket Resize "400x">}}
Some gross eye exploration from a class demo.
{{< /imgproc >}}

It's time to use subtools with ghost and solo modes to: 
1. Smooth away Hornhead's eyelid
2. Resize/move the eye
3. Build up the nose bud
4. Remake the eye socket with swollen, creased flesh and exposed muscle. Google "infected toenail" for choice reference 👌

## Let's look at Brice SLVs basemesh 

* Open the 1mCube starting file in `Lightbox->Projects`
* Select a star or cylinder tool from tool palette
* Go to `Lightbox->Tools->Base Meshes` and double click `Brice_Head.ztl`

### Insert new subtools

On the Tool menu (usually docked on the right side of *ZBrush*) is our *subtool palette*. Below the palette's list of subtools you can find the *Insert* and *Append* buttons. Clicking either will pop a selection of primitive shapes to choose from. 

I prefer *Insert*: it not only inserts the mesh after the subtool you're working with, it also selects it.
  
{{< imgcard ui_append>}}
Append an object as a Subtool
{{< /imgcard >}}

#### Moving With The Gizmo

The  gizmo is like the Maya transform manipulators.
* Press `w` to use it (or `e` or `r`)
* Press `q` to return to brushing
* If you see a weird line with circled ends instead of gizmo, press `y` to switch.

{{< imgproc gizmo Resize "300x" >}}
The Gizmo and its menu.
{{< /imgproc >}}
  
Gizmo tool moving things
	* Individually
	* As a group
	* Locking/unlocking and changing the gizmo pivot `alt` or gizmo edit widget (like `d` in Maya`)
	* Back to center of visible objects
	* Can scale/rotate also.

* Modifying eyes
  	* Deforming with gizmo (`w`)
  	* We have one subtool for eyes and eyelids. How work on eyelids without messing up eye
  	* Back to Sculpt/Draw: `q`
  	* Move brush `b, m, v`
      	* masks (in draw mode)
        		* `ctrl-left drag` to mask out
        		* `ctrl-left drag` on background, not touching model, to clear mask.
        		* `ctrl-left click` on background to flip mask.
    		* With automask polygroup (in brush menu)
      			* View popugroups with shift F
    		* automask topological
    		* masking with ctrl
    		* Now try Move Elastic `b, m, e`

{{< imgproc brice_head_pg Resize "500x">}}
Brice head with polygroups visible.
{{< /imgproc >}}

## Examples of the basemesh in action

### Pipehead

Here's one I've started in my spare time, using the Brice base to model a Max Grecke concept. We'll open and look at the modified mesh.

[![pipehead](pipehead_polys_low.png)](pipehead_demo.zip)

<a class="btn btn-lg btn-primary mr-3 mb-4" href="pipehead_demo.zip" target="_blank">Download pipehead_demo.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

  
### Basemesh vs Team Fortress 2 Spy 

{{< imgproc "spy_base" Resize "600x">}}
Beginnings of spy from TF2 concept art, another spare time project using Brice's base mesh.
{{< /imgproc >}}

You'll need [7zip](https://www.7-zip.org/) to extract this one. Reference included. 

<a class="btn btn-lg btn-primary mr-3 mb-4" href="spy_demo.7z" target="_blank">Download spy_demo.7z<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## Homework

Head modelling exercise
Due: before our review session
Details are in the linked thread. Concepts are below.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://torrens.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_120651_1&nav=discussion_board_entry&conf_id=_270524_1&forum_id=_1127447_1&message_id=_3023650_1" target="_blank">ULTIMO: Alien Homework Submission<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://torrens.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_120652_1&nav=discussion_board_entry&conf_id=_270525_1&forum_id=_1127462_1&message_id=_3023655_1" target="_blank">ONLINE: Alien Homework Submission<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### Concepts

Don't pick blue octopus guy, he requires too many extra models or too much subdividing of the unsuitable jaw mesh.

{{< imgproc "patri-balanovsky-alien-faces-5" Resize "600x" Link "https://www.artstation.com/artwork/n6X1r" >}}
faces-5
{{< /imgproc >}}

{{< imgproc "patri-balanovsky-alien-faces-8" Resize "600x" Link "https://www.artstation.com/artwork/n6X1r" >}}
faces-8
{{< /imgproc >}}

{{< imgproc "patri-balanovsky-alien-faces-12" Resize "600x" Link "https://www.artstation.com/artwork/n6X1r" >}}
faces-12
{{< /imgproc >}}

### Staying low subdiv

{{< imgproc pipehead_polys_low Resize "600x" Link "pipehead_polys_low.png" >}}
Here I'm attempting to get as far as I can (on a different concept) towards final before adding more subdivisions. <I>Click for high res.</I>
{{< /imgproc >}}

#### Resources

ZBrush keyboard shortcuts:
[http://docs.pixologic.com/user-guide/keyboard-shortcuts/shortcuts-by-category/](http://docs.pixologic.com/user-guide/keyboard-shortcuts/shortcuts-by-category/)

My aac202 pinterest board.
[https://www.pinterest.com.au/dmacdraws/aac202/](https://www.pinterest.com.au/dmacdraws/aac202/)

My aac202 youtube playlist:
[https://www.youtube.com/playlist?list=PLfWza-ietxyzCD459RKEL6Tg42Tgnq5gE](https://www.youtube.com/playlist?list=PLfWza-ietxyzCD459RKEL6Tg42Tgnq5gE)

The middle tao pai pai video:
{{< youtube "k2TPi-WaO20" >}}

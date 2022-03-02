---
title: "3. Working clean in zbrush"
linkTitle: "3. Clean ZBrush 2"
weight: 30
description: >
  Working clean: subtools, automasking, base meshes, remeshing.
resources:
- src: "*patri*"
  params:
    byline: "Art: Patri Balanovsky (Artstation)"
- src: "pipehead_arnold_2.png"
  params:
    byline: "Rendered with Arnold in Maya"
- src: "refining_pipehead_2.png"
  params:
    byline: "Zbrush preview render (second with polyframe enabled)"
---

## Housekeeping: ZBrush licensing  
Trials expire after 30 days :( but we have options:
1. Use the lab computers
2. Get a 1 month subscription zbrush license from [pixologic for USD $39.95](https://store.pixologic.com/zbrush-2022/) (or buy it outright)
3. Use splashtop to remotely log into a uni machine and use ZBrush. Similar to Remote Desktop/VNC/Team Viewer/Steam link.

## Learning Today  
1. Easier ways to do the tricky things in the homework!
2. Persistent masking to polygroups - it's the best.
3. Working easily with multiple meshes in a single subtool

{{< alert title="When do your licenses expire?" color= "primary" >}}
Jump into the *#class-AAC202* now and post your license expiry date. IIRC it's visible at top left of ZBrush.
{{< /alert >}}Please let me when your licenses are due to expire.

## Refining The Sculpt

{{< imgproc refining_pipehead_2 Resize "800x" Link "refining_pipehead_2.png" >}}
Pipehead, based on the Brice basemesh, with polygrouped lower lip for mouth editing
{{< /imgproc >}}

{{< imgproc "pipehead_arnold_2" Resize "800x" Link "pipehead_arnold_2.png" >}}
Still in pieces but with more work and 1-2 subdivisions
{{< /imgproc >}}

We're still using a small subset of ZBrush's features, and some areas remain difficult to work with.

* How can I work cleaner with last week's tools?
* What new tools will help?

### Sculpting the mouth

#### Download updated pipehead
Subdivided and (in progress) detailed pipehead plus reference. The zpr file is a little messy - there are two merged heads, including one that was exported to Maya for rendering.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laustu.sharepoint.com/:u:/r/sites/largefilecurriculum/AAC202/zbrush__pipehead_detail.zip?csf=1&web=1&e=fL1Jrn" target="_blank">Download zbrush__pipehead_detail.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

#### Topological Automask

Work an area with masking or hiding its not-closely-linked neighbours: _Brush->AutoMasking->Topological_.

{{< imgcard automasking_ui>}}
Several handy automask features are clustered on the left side of our custom UI.
{{< /imgcard >}}

## Polygroups!

### Polygroups: Together, Alone

If you don't have polygroups visible, hit `shift-f`.

Auto groups, group visible (custom ui, _Tool->Polygroups_).

In _Brush->AutoMasking_ there's a slider for Mask By Polygroups. 
* Turn it up to 100 and it works just like Mask Topological for our hand subtool.
* It's more powerful because you can have multiple polygroups on a single mesh with unbroken topology.

To test it: 
1. Select the upper eyelids and solo them (right side of custom ui), turn on polyframe.
2. Choose the clay buildup brush and sculpt on the outside of the lids. Without lifting your pen, move around to the underside. 

### Masking the mouth

1. First, in draw mode <kbd>Q</kbd>, select the lower face/jaw with <kbd>alt</kbd> + <kbd>left mouse</kbd>.
2. In the tool menu (right of screen or in menus) scroll down to *polygroups*, expand the palette and click on *group visible*.

{{< imgcard "group_visible" Link "group_visible.png" >}}
<i>GroupVisible</i> applies the same polygroup to any mesh visible <i>in the current subtool</i>.
{{< /imgcard >}}

Mask shortcuts again:

| Command           | Shortcut                              |
|-----------        |------------                           |
| Activate masking    | `ctrl`                                          | 
| Draw mask on mesh   | `ctrl + left drag (mouse)`                      | 
| Erase mask on mesh  | `ctrl + alt + left drag`                        | 
| Clear mask          | `ctrl + left drag` on canvas                    | 
| Invert mask         | `ctrl + left click` on canvas                   | 
| Blur mask           | `ctrl + left click` on mesh                     | 
| Sharpen mask        | `ctrl + alt + left click` on mesh               | 

{{< imgproc mask_pipehead Resize "500x">}}
Masking the upper face to move lower lip.
{{< /imgproc >}}

### Hiding And Showing

Hiding parts of meshes or polygroups makes it a lot easier to work in the spaces between things. If you don't have Polygroups visible, hit `shift+f`.

| Command           | Shortcut                              |
|-----------        |------------                           |
| Activate hiding    | `ctrl-shift (plus mouse)`                                     | 
| Hide part of mesh   | `ctrl + shift + left drag (mouse)` a rectangle over it  | 
| Invert hiding       | `ctrl + shift + left drag` on canvas                    | 
| Show all            | `ctrl + shift + left click` on canvas                   | 
| Solo a polygroup    | `ctrl + shift + left click` on mesh                     | 
| Hide a polygroup    | `ctrl + shift + alt + left click` on mesh               | 

Now, again in the *polygroups* palette, click *Group Masked Clear Mask*. Shortcut fans can use <kbd>ctrl</kbd> + <kbd>w</kbd>

{{< imgproc group_masked Resize "800x" Link "group_masked.png">}}
Groups are created, mask is cleared 👍
{{< /imgproc >}}

## Colour

Perfectly visualising the final product before it's painted is hard even for a seasoned sculptor.  Applying colour early can:
* help you better compare your model to the character.
* reveal issues with the eyes and get them solved quicker.
* save on oversculpting, uncertainty and noodling.

Enable colour/polypaint
Fill object
Custom brush DM_FlatHardPaint
Polygons = pixels, so subdivide.
Good materials for polypainting
Hiding/showing the paint job
Eyelids: creasing to keep the eyelid forms. 
  - Crease by angle (crease level 3)

{{< imgproc polypaint_pipehead Resize "800x" Link "polypaint_pipehead.png">}}
UI things to look for when polypainting.
{{< /imgproc >}}

### Exercise: Colour Character Head

If you didn't get it done, borrow [Callum's](Long_head_joe_CA.zip).

## Assessment 1: Character Bust

Here's the [assessment page](../assessments/#1-high-poly-character).

This week we'll do the first page, jump to the [homework](#homework).

### Demo Project

Download this hand project:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="Week7_hand.zip" target="_blank">Hand Basemesh Project<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

{{< imgcard 1_hand_subtools Link "Week7_hand.zip">}}
Hand basemesh (one subtool, multiple polygroups). <i>Click to download</I>
{{< /imgcard >}}

## Combining And Polishing

### Merging Subtools

* You've shaped and moved individual subtools
* At some point it becomes more pain than benefit having them separate

**Pro:** You can run a brush along the palm and onto a finger now, making it easier to sculpt the joints.
**Con:** Now you risk messing up nearby fingers while you sculpt.

It's easy to **merge** the subtools. Make sure *polyframe* is turned on so you can see the changes more easily.
   
1. Enabled *polyframe* so you can see the changes more easily.
2. In *Tools->Subtools->Merge* click *MergeDown*.
3. It'll ask if you're sure. Click *Always OK..*.
4. Continue merging down.

{{< imgcard 1_hand_subtools Link "1_hand_subtools.jpg">}}
Left: multiple subtools. Right: single merged subtool.
{{< /imgcard >}}

### Quick masking meshes within subtools

In move/gizmo mode (press w) you can control click a polygroup to instantly mask out all the others.

Command           | Shortcut                              | Details  
-----------        |------------                           | -----
Mask other polygroups    | `ctrl-shift left-click` in gizmo mode | Leaves the clicked polygroup unmasked

{{< alert title="Move mode vs move brush" color= "primary" >}}
Remember, the move brush is a normal drawing mode brush, and there is also a move/gizmo mode
{{< /alert >}}



## Homework

Work on your assessment 1 bust, follow the instructions in the thread, and **post your work before our work review**. The Module 3 **submission threads** for each class are linked from our assessments page (in step 3). 

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../assessments/#1-high-poly-character" target="_blank">Assessment 1 Submission Details<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>


<!--
## Fusing and Remeshing with Dynamesh


It'll be hard to see, but Brice merges everything with around 0:25. After that, you'll see the seams and cleanup. He's meticulous.
{{< youtube "-ElecAWzP_Y" >}}

### What Did We Just See

Dynamesh completely recreates your model with the same form, as well as it can, with new topology. Your separate meshes are joined where they meet, somewhat like melting wax or plastic together, or welding metals.

{{< imgcard brice_tao_dynamesh Link "brice_tao_dynamesh.jpg">}}
Captured frame where he looks at the new topology. Teeny tiny quads with no apparent flow.
{{< /imgcard >}}

The new topology **has no flow**, but makes up for it with **quite high density** to match the smallforms and folds.

### Easier dynamesh with _Ryan's Tools_

{{< imgproc easymesh_hand_1 Resize "1080x" Link "easymesh_hand_1.png" >}}
Click for high res and check out the mesh changes.
{{< /imgproc >}}

| Command           | Shortcut                              |
|-----------        |------------                           |
| Easymesh to level 5   | Click the _EasyMesh_ below the main canvas on my custom UI  |
| Easymesh to another level  | Undo the previous easymesh and drag the _Detail Level_ slider. 1 is coarse and 10 very fine |

### Dynamesh directly
| Command           | Shortcut                              |
|-----------        |------------                           |
| Enable Dynamesh   | Click the _Dynamesh_ button inthe _Tools->Geometry->Dynamesh_ subpalette. |
| Re-Dynamesh       | `ctrl + left drag` on canvas (like clear mask, so be careful) |
| Project           | Button in the _Dynamesh_ subpallette. |
| Change resolution | Slider in _Dynamesh_ subpalette. |

-->
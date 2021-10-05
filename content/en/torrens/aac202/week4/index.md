---
title: "4. Finishing and rendering in ZBrush"
linkTitle: "4. Finish"
weight: "40"
description: >
    Dynameshing, seam removal, rendering passes, compositing.
---

<!--

## Review Of Progress

Week 7 detail sculpting:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_89547_1&nav=discussion_board_entry&conf_id=_152757_1&forum_id=_866559_1&message_id=_2226714_1" target="_blank">Week 7 Progress Thread<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

Stuff that was **easy**? Stuff **less easy** than expected?

 ## A2 extension and delivery.

**Delivery:** Wednesday, July 29 (as discussed last week).

We're going to **push our model over to Painter**, which is different to last trimester's students
* I'll be **updating the deliverables** in the next few days.
* It'll be a combination of working files and screenshots. 


## Pipehead painting

Open last week's pipehead detailing file. If you don't have it, [grab it from last week's notes](../week3/#download-updated-pipehead)

## Polypaint along review
* Enable polypaint
* Hard and soft brushes
* Use <kbd>c</kbd> to pick colours from mesh
* Look at the terrible results on low or dynamic subdivisions. Add real divisions - you'll have to do this on your own character.

Me prep: Add polypaint to him and see if can get it through the process. Bake as id map and duplicate texture

## Exercise: Paint your character a bit.

Get started painting your own character using what you've just learned.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_89547_1&nav=discussion_board_entry&conf_id=_152757_1&forum_id=_866560_1&message_id=_2226746_1" target="_blank">In Class Painting Thread<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

-->


## Can I edit/add bits using Maya?

There are a few easy ways to do this. You can use regular exporting and importing, or you can use the GoZ plugin.

{{< alert title="Method 1: Manually" color= "primary" >}}
This is simplest way in that it doesn't require learning new tools beyond the fbx exporter. It's laborious though.
1. Export an obj or fbx file from zbrush at a low subdiv
2. Import it into zbrush, model around it to add your new bits. Work in quads: it'll be subdivided.
3. Export those bits from zbrush into a new fbx
4. Import that into zbrush.
5. If it's a blocky mesh (say, a box) try adding creases by normals.
{{< /alert >}}

{{< alert title="Method 2: GoZ" color= "primary" >}}
GoZ makes a connection between Maya and Zbrush. It's initially a bit harder because it requires a little setup and learning, and some testing on something unimportant to figure out the quirks.

In the long run it's the much better process. It's fast and automated, removes any fussing around with scale and names, and more information makes it back and forth (creases and more).

1. Trigger GoZ install into Maya
1. Set Maya (and its path) as GoZ destination
1. GoZ your mesh from ZB to Maya
1. Model bits around it
1. In the Maya GoZ shelf, push your mesh back to ZBrush.
{{< /alert >}}

## Topology

A soccerball is always the same general **_form_**: a sphere. The panels that make up the surface can vary enormously. The layout of these panels is the ball's _**topology**_

{{< imgcard topology_footballs>}}
Some of the many panel layouts.
{{< /imgcard >}}

{{< alert title="Definition: Topology" color= "warning" >}}
The shape, number and layout of polygons that make up the surface of your model.
{{< /alert >}}

{{< imgcard topology_cubes>}}
A cube's topology can vary infinitely while remaining a cube.
{{< /imgcard >}}

### Character Topology

We started with a lower density mesh, made of quads, and the quads flowed fairly well with the forms.

{{< imgcard brice_head_pg>}}
Our starting point, the brice head.
{{< /imgcard >}}

The polygon _density_ was fairly consistent on a lot of the surface, with extra density in areas like the features of the nose, the edges of the eyelids, the ears. We **increased the density** across entire subtools of the mesh by _subdividing_ (ctrl-d).

{{< alert title="Definition: Polygon Density" color= "warning" >}}
The number of polygons making up a given area of a mesh. It can change from location to location on the mesh.
{{< /alert >}}

## Making one mesh from many

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_torrens_edu_au/ERnPVQnNq8ZFrT8PYF0wuXIBAVoJYld7r1VMngodfeB2LA?e=rE124g" target="_blank">Download zbrush__pipehead_detail.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

The Brice head is separated over multiple subtools, so **it's not a continuous mesh**. Even if they're all merged into one subtool, the shells are still separate, made of their own polygons. We can join them all together with new topology. It won't follow the shapes with nice loops as the previous meshes did, so we'll need a lot of polygons to make up for it. This is why you don't do it before you have to!

{{< imgcard remeshed_eyes Link "remeshed_eyes.png">}}
Pipehead topology after easymesh/dynamesh and some smoothing, modeling.
{{< /imgcard >}}

### Exercise: Smoothing, merging, easymeshing

1. All joins should be good as can get while meshes not joined. I fixed pipehead his nose so it doesn’t have gaps near face. Check your mesh for gaps where objects should meet. 
2. SAVE A NEW VERSION WITH A NEW NAME.
2. Add subdivs till everything is smooth.*TIP: none of your meshes on your own model should be over 1 million points. Del higher if u have this.*
2. Reorder your subtools so all the things you want to merge are in sequence, with the non-mergey subtools at the end.
3. Merge down till all your skin bits are merged.
4. Duplicate that merged subtool and turn off visibility on the old one - it's good to have it to go back to
5. Hold control and just do a few brushes on the mesh with the mask, and deselect the mask. It's a goofy workaround, but we need a few undo states on the mesh for the next bit.
3. On the left of the ui is *Easymesh*. Grab the dragger on the little 1-10 detail slider and drag it to 7, then let go.
	
## Handling seams and wrinkles

Once we've remeshed we can remove ugly seams (think around temples, ears,nose, neck) and add in character-enhancing wrinkles and creases around the eyes and nose.

### Style reference matters!
Now, how do we translate from 2D painting to 3D *in a style we'll be happy with*. Style defines how all those plane changes happen, how much of the wrinkles to leave in, how much we change them from realisticto get nice flow and contrast, etc etc.

Let's have a look at my 3d-inspiration board on pinterest and the some pureRef files I use to remember what I want to achieve.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://www.pinterest.com.au/dmacdraws/3d-inspiration/" target="_blank">3d inspiration on Pinterest<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://www.pinterest.com.au/dmacdraws/face-inspiration/3d/" target="_blank">3d face inspiration on Pinterest<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

{{< alert title="Pureref files" color= "secondary" >}}
Jump into the **\#class-aac202** channel on the *Discord* server and check the pins/latest messages.
{{< /alert >}}

## Exercise
Do some seam fixing.

<!-- 
##  low poly auto
8. Duplicate each tool, give _low suffix
9. Decimate skin to 8k
10. Decimate eyes to .5k
11. Weld, fix mesh, test integrity
12. Export fbx of head, eyes baldy_low.fbx

##  Maya quick uvs
1. Import into new maya scene
2. Dont mess with position
3. Mesh cleanup->fix manifold.
4. Create auto uvs
5. Unfold
6. Layout
7. Soften/harden by texture borders
8. Delete history
9. Export fbx again

## Painter:
1. New file from low fbx
2. Bake normals from high on 1024
3. If it works go 2k and bake all maps except colour id
4. Try colour id from vert colours
5. Dupe id map and add to fill layer
6. Celebrate.

-->

## Rendering How

Turning on and tuning **shadows**
* Shadows
  * Change direction to match material?
* Ambient Occlusion
* Filling with material:
    * Making some things glossy (eyes), some matte
    * Wax/subsurface scattering
* Subpixels (sampling)

### Rendering What

* Angles
  * EXAMPLES 
* Closeups
  * EXAMPLES

## Render Passes

Making passes and exporting to photoshop/Krita for more editing.

### Photoshop Method

* In the _Zplugin_ menu you'll find ZBrush To Photoshop CC. Select passes like shadow, bpr, AO, lights, and _Send To Photoshop CC_.
    * It will ask where the photoshop executable is on your hard drive. Browse to it. (probably `c:\program files\adobe\Photoshop\Photoshop.exe` or similar)
    * It will take a while and do a lot of stuff in zbrush, turning subtools on and off etc.
    * Click yes when photoshop asks if you want to run a script.

{{< imgcard zbrush_to_photoshop Link "zbrush_to_photoshop.jpg">}}
Click the passes you want, let the plugin automate the exports.
{{< /imgcard >}}

### No Photoshop Method

* Ensure shadows, ambient occlusion are on in _Render \> Render Properties_
* Make a BPR render in zbrush (shift R or click the button)
* Look _Render -> BRP RenderPass_: click on a pass to download it as an image. Default type is single layer PSD, but it also has TIFF.

{{< imgcard zbrush_bpr_renderpass Link "zbrush_bpr_renderpass.jpg">}}
Click individual passes to export.
{{< /imgcard >}}

## Using Render Passes

Here's a render with some a bit of quick processing/painting over
  - rim lighting painted in
  - right light pass added
  - shadows purpled up
  - eyelashes, gloss on lips, scar quickly dropped in
  - radial gradient behind, cool colour photo filter on top
  - Camera raw: quick add grain, sharpen, individual hues adjusted, vignette

{{< imgcard izzy_comp_passes Link "izzy_comp_passes.jpg">}}
Left: Render passes exported to photoshop  Right: With some editing
{{< /imgcard >}}

## Homework

Finish and submit your [assessment](../assessments/#1-high-poly-character-week-4)

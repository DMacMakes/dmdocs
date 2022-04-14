---
title: "9. Hard surface modelling with subdivs"
linkTitle: "9. Hard surf 1"
weight: 90
description: >
  Weeks 9-12: Hard surface modelling time
---

## What is Hard Surface Modelling?

Hard surface modelling is a term used in the game industry for modelling objects that are inorganic and usually machined. Think headphones, engines, washing machines, hinges, vehicles, space helmets, guns, armour, frying pans. These objects are usually rigid and have features not easily found in nature: **paralell lines, near-perfect circles, very flat surfaces, tightly controlled bevelled/rounded edges**. If you've held an iphone,- played a nice piano, used a well made game controller or mouse that fit your hand well, you know the pleasure of having just the right curves and texture to a surface, just the right play/travel to a button.

{{< imgcard "wooden_radio" Link "wooden_radio.jpg">}}
Handsome retro bluetooth radio.
{{< /imgcard >}}

{{< imgcard helmet_doom_eternal Link "helmet_doom_eternal.jpg">}}
AAA super legit space helmet
{{< /imgcard >}}

The techniques for modeling a go kart or military radio in high detail, then, is pretty different to how you'd model say, a _Wrinkle-necked Slothbarg Peasant_ NPC or his ragged cloth farmer's tunic.

## How's it done? 

The key is controlling surfaces and edges carefully, without introducing lumpiness. As we saw in character modelling, **fewer edges** usually leads to **fewer lumps**: but it leaves things faceted, or we **smooth it and lose our sharp edges**.

{{< imgproc klaayas_room_wireframe_javier_rodriguez Resize "600x" Link "klaayas_room_wireframe_javier_rodriguez.jpg">}}
Round vs sharp, countour control!
{{< /imgproc >}}

Look at the eimage above carefully. See how the window is perfectly smooth and round, and the top left curtain folds are perfectly curved despite having few lines on there?

That's our friend **dynamic subdivisions**. But how do we use them without collapsing the sharp edges at the edges of teh window, or the controlled bevels on the chest?

![Pixar subdivs](subdiv_pyramid_pixar.png)

### Creases and control edges

{{< imgproc control_loops Resize "400x" Link "control_loops.jpg" >}}
Using extra edges where we want more structure.
{{< /imgproc >}}

When we subdivide, as you can imagine, our computers do some fancy math to add new polygons, average them out, etc etc. That's fine, we just hit ctrl-d. The way that algorithm (bit of code that calls the shots) works allows for us to add in extra edges, or add *crease* to edges, just like creasing paper really, so when the surface smoothes it can keep corners.

{{< imgproc "bot_piece" Resize "400x" Link "bot_piece.jpg" >}}
Armour from the upper arm of a robot.
{{< /imgproc >}}

You can think of **creases** like the bendy poles in a tent. The hold the form very well where the cloth crosses them, and bend with the form along their length.

TODO: Need pic of crease in zbrush. Pref from my hearthstone things.

**Support edges** are more about strength in numbers.. The more there are and the closer together they are, they more they behave like a creased edge. You get more control with support edges, but it messes with your polygon density. 

{{< alert title="Catmull-Clark" color= "primary" >}}
The most common smoothing algorithm used in 3D packages is <i>Catmull-Clark</i> subdivision. You probably won't be surprised that it's engineered to allow expressive modelling with minimal polygons when you hear that the _Catmull_ is **Ed Catmull**, co-founder of **Pixar**. Pixar's tech is heavily focussed on realism combined with appeal, but with the goal of rendering fast enough to make the hundreds of hundres of thousands of frames needed for a feature film.

He worked along with Jim Clarke, who co-founded _Silicon Graphics_ and _Netscape_, and of course like all our creations it was built on the work of other smart, passionate people.
{{< /alert >}}


## Subdivision surfaces

{{< imgcard subdivision_cube_wikipedia >}}
Subdividing a cube three times - wikpedia
{{< /imgcard >}}

#### Subdivision: 
* Take a square, draw a vertical and horizontal line through the middle. 
* You've subdivided it into 4 squares.

#### Smoothing

Once your mesh is subdivided and has lots more edges and verts, a smoothing algorithm is applied. In it's simplest form, it's kind of averaging out the space between all the vertices on the model, averaging out the area of all the faces, averaging out all the angles. It eventually leads to a sphere.

Imagine you can sew:
* You get some soft, elastic fabric, cut out the shapes of the polygons in your model, and sew them together.
* Fill it with little foam balls (bean bag beans)

{{< imgproc cube_cushion Resize "500x">}}
Cube cushion
{{< /imgproc >}}

Or just imagine your model as a baloon:
{{< imgproc jett_balloon Resize "500x">}}
The Super Wings?
{{< /imgproc >}}

{{< alert title="Further Reading" color= "primary" >}}
Wikipedia: <https://en.wikipedia.org/wiki/Subdivision_surface>
{{< /alert >}}

<!-- 

## New tools!

Since we're doing new things, I've updated our tools and UI. Grab them and we'll install.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/Ee2da8SsTu5Jlf4E10iHxCgBhxjyXKhXfMMnCeyzpibg_A?e=6f1xLN" target="_blank">ZBrush 2020.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/ETsNpdQYe1NJpDtFYUZDE04Bawx7Di8-PfsyDlWfOCZwxw?e=75Dvru" target="_blank">zbrush_customisation.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

-->
## Introducing ZModeler brush! 
hotkey: b > z > m

Zmodeler brush lets you work on geometry at the vert/edge/face level like Maya, but also lets you to work by flat islands, polygroup islands and more.

![zmodeler tank frame](zmodeler_tank_1.png)
An in-progress model with the zmodeler brush hilighting an edge.

Watch a little of the Metal Slug tank modeling tute by Joseph Drust. Jump in around 13:40, watch a few minutes, skip around.

{{< youtube jHOk2kCPK8Y >}}

![zmodeler edge actions](zmodeler_edge_actions.png)
Hitting <kbd>space</kbd> while using zmodeler shows you what you can do to the component type under your cursor.

TODO: Screenshot of the custom zmodeler brushes


## Exercise 1: Explore breakfast

<!--Open scene with cube and magnifying glass good topo, mag bad topo, in layers, only cube visible.-->
Grab and open this ZBrush project
{{< imgcard "mug_subd_zb" Link "breakfast_zbrush.zip">}}
Breakfasty bits modeled in ZBrush.
{{< /imgcard >}}

<a class="btn btn-lg btn-primary mr-3 mb-4" href="breakfast_zbrush.zip" target="_blank">breakfast_zbrush.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

TODO: Add more to breakfast: fork with creases and control loops.

### Breakfast by Paul Chambers

This is the pic I was modeling from.

{{< imgproc style_big_breakfast_paul_chambers Resize "1024x" Link "style_big_breakfast_paul_chambers.png" >}}
Big breakfast. Click to zoom.
{{< /imgproc >}}

### Creases and control loops.

Turn on and off dynamic subdivs for the various bits. Look at the shapes we get.

### Control loops and ZModeler

Pros: fine control
Cons: Extra unwanted polygon density

### Arcade stick

{{< imgcard arcade_stick_zb Link "stick.zip">}}
Download, unzip and open the arcade stick in ZBrush
{{< /imgcard >}}

<a class="btn btn-lg btn-primary mr-3 mb-4" href="stick.zip" target="_blank">stick.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>
## Style reference is critical 

Detailed subdivision modelling is way beyond the scope of this subject. Instead, we'll use the techniques to add **charming roundness** and **light catching** chamfers to our props.

To do that in a cohesive way we'll use style reference.

#### Close Up: Paul Chambers

He's an artist who works at SuperCell.

{{< imgproc style_pancakes_paul_chambers Resize "1024x" Link "style_pancakes_paul_chambers.png" >}}
Pancake breakfast. Click to zoom.
{{< /imgproc >}}

{{< imgproc style_chest_paul_chambers Resize "1024x" Link "style_chest_paul_chambers.png" >}}
Chest. Click to zoom.
{{< /imgproc >}}
 
#### Zoomed out: Lulemero

Nice rounded softness in this scene gives us an idea of how to approach our modeling.

{{< imgproc klaayas_room_javier_rodriguez Resize "1024x" Link "klaayas_room_javier_rodriguez.jpg">}}
Everything looks sanded off, smooth to touch. Click to zoom.
{{< /imgproc >}}

## Homework

**Due Monday 12pm (midday)**

1. Watch Metal Slug tank modeling.
2. Watch Pavlovic Tutorials.
3. Model breakfast object/s with ZModeler.

Learning subdiv modeling requires time, **concentration** and **repetition**. There are multiple techniques **specific** to certain types of models/problems.

### 1. Watch metal slug tank modeling 

Watch at least half an hour of this 1 hour video. It doesn't have to be one sequential bit, you can pick 3 10 minute chunks for example. 

It's timelapsed but it has **commentary** through the whole thing by Pixologic's demo guy (and former industry modeler guy). It doesn't slowly teach you any given feature, but it will give you a great **understanding of how he breaks up the model** into pieces, then repeats a small set of processes in different ways. He also solves common problems, and you'll see him use masking, polygroups and visiblity controls just like with the other brushes. By the end you can see how appealing mechanical things can be made with the zmodeler brush/tools. 

{{< youtube jHOk2kCPK8Y >}}

<!-- https://www.youtube.com/watch?v=jHOk2kCPK8Y -->  

### 2. Watch Pavlovic tutorials

This guy is the absolute source. Learn with Michael Pavlovic: **watch videos *33-37*.**

[ZModeler in the 2021 intro to Zbrush series](https://www.youtube.com/watch?v=XcR5TzvIaoc&list=PLkzopwqcFevYP1Nm3wIKsyH-jQTkk8AhS&index=33)

### 3. Model object

Using zmodeler and dynamic subdivisions, have a go at modeling the knife in this pancake breakfast scene. **Hint:** don't make it one single piece. use separate meshes for the blade, the handle and the rivet. If you finish it and want to explore more, try the teapot: separate lid, handle, body and spout.

Post screenshots of the model with polyframe on and off, with dynamic subdivs on and off.

{{< imgproc style_pancakes_paul_chambers Resize "1024x" Link "style_pancakes_paul_chambers.png" >}}
Pancake breakfast. Click to zoom.
{{< /imgproc >}}

#### Submission

By midday Monday add a **reply** to your class's thread below and **insert your screenshots** so they're visible when we view the thread. If you click a link and it has to authorize it may drop you at the subject's blackboard homepage. If so, come back here and click again.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://torrens.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_115852_1&nav=discussion_board_entry&conf_id=_246176_1&forum_id=_1064204_1&message_id=_2899265_1" target="_blank">HW Thread<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>


<!-- 

### Working with cylinders

flipped normals how to model curved hard surfaces.
https://www.youtube.com/watch?v=u7hg6xjskoq

Some straightforward controlling of volume and end shapes:
{{< youtubetime iyZqmWf5x_c 223 >}}

But how do you add features to one small area without breaking the that perfectly circular cross section:
{{< youtubetime RCSijbeXujs 38 >}}

The first 10 minutes here show us how to break up the mesh without gaps and distortions.
{{< youtube ryPIKJkNzPI >}}

### More Complex

More by Elementza:

{{< youtube 0WZ8zfKOTr0 >}}

### Sharp Things, Hiding Triangles

One to subdivision modeling is that **pointy volumes** are naturally form **pyramids/triangles**: how do we handle those with quads?

{{< youtube "Z9wgKy-F1Rw" >}}

{{< alert title="Disaster: I don't know 3DS Max!" color= "danger" >}}
Relaxing. He's using 3DS Max, but he's using subdivision surfaces and **his solutions apply just as well in Maya**. The video's full of great techniques despite the weird tool names (turbosmooth = Maya's smoothed display, etc).
{{< /alert >}}

Another challenge he helps you manage: **adding details** means adding lots of edge loops. How do we **avoid a loopfest** that makes the model unmanageable and messes up curves?
* If we terminate those edges that'll make a triangle, right? Won't that mess up the surface?
  * First, there are **sneaky ways of shaping quads** 
  * Second, triangles and ngons  create bumpy artefacts on curved surfaces, but **flat surfaces handle bad geometry better**

## Summary

This week we
* Learned about high detail modelling using sub division surfaces
* Tried some basic techniques and learned about the challenges
* Covered our first assessment
* Introduced resources you'll need to learn from
* Have homework to do!

-->

<!--

 Homework

1. Watch videos provided, take notes about some of the techniques and challenges of subdivision/hard surface modeling that you discover.
2. Consider what techniques you think will solve your problems.
3. Draw over the concept in photoshop/krita to show pieces, and again to show ideas of edges/topology
4. Document your answers in **your own new thread** in the module one forum. [See my post for instructions](https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_89547_1&nav=discussion_board_entry&conf_id=_152757_1&forum_id=_866553_1&message_id=_2124709_1).

-->

<!--  

 NEW APPROACH
Biggest cross-subject problem right now: assignments are due on a sunday, not 1 week after the class.

W1: 
- Do not teach about the game mesh or painter yet! Introduce once this first idea is rock solid.
- Leave out "high" and "low" poly where possible. Use "unsmoothed" and "smoothed", "subdivided".
- Pic an object from the provided concept in first hour.
- Demo of SubD modeling. Understanding that the subd mesh has two views/states.
- Together we model something step by step
- They start on their model. Forget the whole planning angle, was too confusing. People mixed up all the meshes and though they thought they grocked the normals, it was usually misinterpreted.

W2: 
  - More subD modeling and refining, finishing
  - Looking at problems people have
  - Fixing one or two meshes for people in front of class
  - Get it finalised. Name everything part1_subd, thing_subd.

W3: 
- Describe goal: lets make a game mesh that is as close as possible to our subd in smoothed mode.
- You can start with a new mesh, or with a duplicate of the subd with all the supports removed.
- Call parts part1_game, thing_game.
- Key challenge? How do you model something in the same space as another model (the subd) and compare them?
  - Using layers with R turned on
  - Making objects visible/invisible
  - game res prefers staying inside the high res.
  - approximating smooth curves with minimal geometry (use example both big curves and tight curves)
Our game res model is going to have texture maps generated from the geometry of the smoothed subdiv!
Use always: Freeze modifiers, delete history! Especially important in UV.
- Uv unwrapping game model.
  - Recapping the unwrap process
  - How to set up our normals:
    - In edge mode, uv editor -> select -> select texture borders. Harden edges.
    - Inverse edge selection. Soften edges.
Has to be finishd this week. Post to journal.

W4: 
  - Work together demo: download and open painter demo scene. (maybe download all demo assets start of trimester?)
    - scene has a baked button in it when opened
    - edit -> project configuration, import a diff game meshes
    - Texture Set Settings -> Bake Mesh Maps, select diff subd meshes
    - Hit bake, see results.
    - Explain that the game res  mesh is our true mesh, and the new normal maps we just got are generated from the high res.
      - Diagram showing how it looks in front and behind, then uses angle of surface for x,y,z (r,g,b) values. 1,0,1 for purple.
  - Do it with theirs, debug what's not working.
Open painter sample scene
-->


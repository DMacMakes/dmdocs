---
title: "12. Final texture"
linkTitle: "12. Finalising"
weight: "120"
description: >
  Adding story to our textures, tuning style and wear.
---

## Today
Wrapping up Painter, assessment 3 work.
- Storytelling in texture
- Human eye vs algorithm: tuning textures with hand masking/painting.
- Help with stylising particular textures?
- Remember that dirt is on all of your model, it doesn't know which area has what material, so it should be above those masked layers. Same with, say, a dust layer or ambient occlusion pass.
- Working with post effects (exposure, contrast, vignette etc)
- Export to sketchfab?

## Assessment 3 submission details on dmdocs

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../assessments/#week-12-working-files-final-textures" target="_blank">How to submit assessment 3 (surfacing)<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## Recap - storytelling in texture. 

See the second part of the week 11 reviews:  

C11.2 <https://au-lti.bbcollab.com/recording/1b320fa84eec4bdb88f213f4bc06b8d4>

1. We settle the colour blocking, materials, the style and extent of wear and surface features  
2. We begin to tell the story of the object and reflect its functionality and environment in wear, stains, scorch marks, rust.  
  
 Ideally, picture | storytelling texture
 ---------------- | -----------------------------
 \[pic\] Hot zone | grease and smoke stains near seams/vents where hot components/motors are inside
  \[pic\] Wear zone | rust were movable panels meet: their action grinds dust and other schmoo into the paint, revealing bare metal, which oxidises (rusts)
 \[pic\] Exposed metal | If exposed metal doesn't rust, why? It's a precious metal maybe, or super fancy composite. It'll mostly be dull and oxidised/rusted if it is exposed except in spots where it's recently scratched or where it's constantly rubbing against a fabric or other soft abrasive.
 \[pic\] Streaks of rust/grease | water gets into seams where rubbing/vibration has caused the coating to crack/wear, and then trails of rust descend from there
 \[pic\] Paint ageing | Paint fades and glossy clearcoat is destroyed (becoming matte) under years of UV exposure. That's always on the surface pointing most directly at the sun, so upper areas.
 \[pic\] Ground | Things that rest on the ground get dust, mold, rock scratches, rust from moisture in the ground/dew on grass.
 \[pic\] Dust | Gravity is a thing. It makes fine schmoo in the air fall down eventually, and it lands on the top surfaces of objects.

## When the texturing is done

Post effects, exporting. 

### Post effects

{{< imgcard post_colour_correction>}}
An example of colour correction in Substance Painter (from the docs)
{{< /imgcard >}}

Once the texture is on the model and the camera and lighting have been positioned/tweaked, what else can we do? From *ZBrush* we exported to *Photoshop* to do a bit of compositing, applying some post-processing by hand. That's fine for a single render, but a game engine renders 60+ frames per second - humans need minutes or hours in photoshop, so we're out. 

Only a computer could composite/post process those rendered frames fast enough, and that's what post-effects shaders/filters are for.


{{< alert title="Definition: Post effects (post processing)" color= "primary" >}}
*Post-Effects* are filters than can be applied to the images rendered in the viewport of Substance Painter to simulate common camera effects.

*Post processing* is the general term for modifying the image/frame (by hand or by script/filter/plugin) produced by the 3D rendering process or produced by a camera. Post = after, as in post-mortem.
{{< /alert >}}

Each effect is broken down in the Substance documentation:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://docs.substance3d.com/spdoc/post-processing-172818692.html" target="_blank">Post effects on Substance Docs<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### Don't use IRay

At least not for submitting this assessment. We're producing game assets for real time rendering, so we'll work on making that look as good as we can. Iray's renders require many seconds to minutes to produce, so it's giving us a view of our asset that would never appear in game. That really limits its usefulness for assessing our work.

## Sketchfab

> Sketchfab is a service that hosts 3D models and textures as well as offering an embeddable, webgl based viewer with advanced real-time rendering capabilities and handy tools for inspecting the model and textures.

**Let's create an account.** The free account has 1 model per month. Feel free to create the account with your school email.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://sketchfab.com/signup" target="_blank">Register a free Sketchfab account<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

<div class="sketchfab-embed-wrapper"> <iframe title="Mini Axe" frameborder="0" allowfullscreen mozallowfullscreen="true" webkitallowfullscreen="true" allow="fullscreen; autoplay; vr" xr-spatial-tracking execution-while-out-of-viewport execution-while-not-rendered web-share width="480" height="480" src="https://sketchfab.com/models/c580dcae6f6e46568e5759eba18d3dc7/embed"> </iframe> <p style="font-size: 13px; font-weight: normal; margin: 5px; color: #4A4A4A;"> <a href="https://sketchfab.com/3d-models/mini-axe-c580dcae6f6e46568e5759eba18d3dc7?utm_medium=embed&utm_campaign=share-popup&utm_content=c580dcae6f6e46568e5759eba18d3dc7" target="_blank" style="font-weight: bold; color: #1CAAD9;"> Mini Axe </a> by <a href="https://sketchfab.com/dmacdraws?utm_medium=embed&utm_campaign=share-popup&utm_content=c580dcae6f6e46568e5759eba18d3dc7" target="_blank" style="font-weight: bold; color: #1CAAD9;"> dmacdraws </a> on <a href="https://sketchfab.com?utm_medium=embed&utm_campaign=share-popup&utm_content=c580dcae6f6e46568e5759eba18d3dc7" target="_blank" style="font-weight: bold; color: #1CAAD9;">Sketchfab</a></p></div>

[See mini axe on Sketchfab](https://sketchfab.com/3d-models/mini-axe-c580dcae6f6e46568e5759eba18d3dc7)

Exporting once you have an account:

Step | Screenshot
---- | ----
**1** Go to *file -> export*, choose *sketchfab*, log in. | ![export 1](sketchfab__export_1.png)
**2** Configure the *Title*, *Description* etc | ![export 2](sketchfab__export_2.png)
**3** Wait for the sketchfab elves to prep the model (a few minutes). | ![export 3](sketchfab__export_3.png)
**4** Configure 3D settings - camera angle, transform, post effects etc. | ![sketchfab 3d settings](sketchfab_3d_settings.jpg)

<!-- 

1. Some feedback  
2. Defining the last task for the assessment (how to render it this week)  
3. Some learnin: How you might retopo your model for painter in your holidays/future  

## Finishing

Rendering with Orb's setup.
Save this [step-by-step tutorial by Orb/Michael Vicente](https://laureateaus-my.sharepoint.com/:v:/g/personal/daniel_mcgillick_laureate_edu_au/Ea6azVT_8EpKjeq_YFqng-ABfNCHg1-LgWcGkiTcwCYEWA?e=meF9tb), where he explains and demonstrates his rendering process in ZBrush.

If you take the time to follow it, put in the work, having your renders look this good and demonstrating your effort will be worth solid marks, taking you up into distinction territory.

Don't make your file overly heavy! You should be able to get all your necessary stone details in 250K-350K points each, for example, less on the boring stones. Overly heavy means you are trying to work with the scene and it's uber slow, maybe rendering takes forever etc.

## Decimation And Topo Demo

For learning's sake.
The goal here is to take our high res model from ZBrush to maya and draw game res topology onto it. Kinda like tracing. ZBrush high res meshes are heavy though, so we'll decimate one down to medium res and trace that instead.

### 1. ZBrush Decimation
**CAPTURING PICS DURING DEMO.**

1. Make a copy/duplicate of what you want to retopologise.
2. If you have subdivs, choose the level that has most of the detail but it doesn't have to be super sharp.
3. I delete my lower and higher subdivs, and then decimate 
   - preprocess the decimation
   - Try decimating to the lowest number that gives you all the info you need about the surface, but is light enough for maya.
     - maybe 1-5K for a wharf brick? Similar for a plank. A character face might be 15K?
4. Export fbx or sent to Maya with GoZ.

Extra decimation techniques/info from Pav:
{{< youtube TitIPlM2Xnk >}}
{{< youtube 7BoRmlCEq9g >}}

Tessimating and decimating!
{{< youtube ogSldTT6slc >}}

### 2. Maya retopo
**CAPTURING PICS DURING DEMO.**
Here's a video of the FlippedNormal guys demoing it as well, watch this later for a refresher/anything I missed.

{{< youtube xpDWta5O3n8 >}}

We'll use two new features for this: _live surface_ and _quad draw_.
1. Import medium res into Maya (or receive via GoZ)
2. (optional) Drop it into a new layer, and make a new layer for the game res topology.
3. Right click the medium res mesh and click **make live** in the popup menu.
4. Open the _Modeling Toolkit_ and click **quad draw**
5. Left click the live mesh to drop points on it. Your goal is to draw the corners of four sided faces.
6. Where you've dropped four points, shift click in the open space between them to make a face.
7. Ctrl click to insert edge loop. Ctrl-shift click to delete things. Ctrl-shift-middle drag to move edge loop.
8. Tab-drag to extrude border edges, making whole new rows of quads!

[Click here for all the controls](https://knowledge.autodesk.com/support/maya-lt/learn-explore/caas/CloudHelp/cloudhelp/2017/ENU/MayaLT/files/GUID-ED28E6BC-6141-491C-8C1B-2AE6FC813284-htm.html) or, in Maya, look at the bottom of the modeling toolkit when quad draw is activated (you might have to expand the tool tips section/scroll down).

## Submitting This Week

Deliverables and how to submit them on the assessments (dmdocs) page:
<a class="btn btn-lg btn-primary mr-3 mb-4" href="../assessments/#assessment-3-high-poly-environments">Assessment 3</a>

-->
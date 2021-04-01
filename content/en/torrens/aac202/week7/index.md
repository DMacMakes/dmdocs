---
title: "7: ZModeler 3 - Detailing hard surface models"
linkTitle: "7. Detailing"
weight: 70
description: >
  Starting a second model, the radio. How do we add parts? New primitives, import from Maya? 
resources:
- src: "barrel_alvaro_vera.jpg"
  params:
    byline: "Art: Alvaro Vera"
---

 ## What we'll learn today

* What to deliver for A2
* Stamping details onto high resolution surfaces
* Creating bumpy/noisy surfaces
* Texturing?

## Assessment 2:
* 10 days left
* Complete and detail the NES pad, make some nice renders.
* Updating assessment page today, creating forum threads
* Week 7 progress thread submission
* Week 8 final submission

## Dpad bending
The d pad:
{{< imgproc dpad_from_boxes Resize "200x" Link "dpad_from_boxes.jpg" >}}
The dpad as made from boxes, only bending is left.
{{< /imgproc >}}

Things to try:
* Masking with fall off + gizmo or deformation palette transform
* Lattice modifier with gizmo

## Stamping in ZBrush

*Stamping* here refers back to how a regular ink stamp bangs down a whole, repeatable image in one go. A smiley face, the word "DENIED", a cafe's logo on a coffee cup.

![coffee cup stamp](stamp_coffee.jpg)

Stamps are basically instant ways to draw a thing **once you've done the work** of crafting the original image. When I say stamping in *ZBrush* I mean using a brush on a surface to emboss an image into the surface or onto it. It's a bit more like pressing something into play-doh than stamping onto a sheet of paper, but it relies on the same thing - a finished piece of art.

TODO: pic of stamped surface in zbrush and play doh

### Alphas

Alphas are **greyscale images** that can be applied to a brush and act as a mask or filter: where the image is white the brush has maximum effect, where the alpha is black it has none of the effect. Where the image is grey, the effect is applied proportionately.

![ornament alphas by jro](alphas_jro_ornament.jpg)
*Ornament pack alphas by JRO on [the Flipped Normals store](https://flippednormals.com/downloads/ornament-alphas-vol-1/)*
### Using alphas to stamp

Dragrect brush stroke

1. Pin brush palette to left of UI 
2. try different stroke types - drag dots, dragrect.
3. Try combining alpha and stroke with different brush types 
  
Here are some links to Pavlovich explaining alpha usage in depth (youtube) and reference info (zbrush official docs).

Page      |       Link
----      | -----
Using dragrect, other stroke types | [Michael Pavlovich Youtube](https://www.youtube.com/watch?v=AdkZe1yKFTU&list=PLkzopwqcFevYP1Nm3wIKsyH-jQTkk8AhS&index=16)
Alpha options | [Michael Pavlovich Youtube](https://www.youtube.com/watch?v=vjDZ3-fjwt8&list=PLkzopwqcFevYP1Nm3wIKsyH-jQTkk8AhS&index=17)
Masking with alphas and more | [Michael Pavlovich Youtube](https://www.youtube.com/watch?v=8kWFv1cZlCE&list=PLkzopwqcFevYP1Nm3wIKsyH-jQTkk8AhS&index=20)
Skin alphas with process gifs | [Flipped Normals Store](https://www.zbrushguides.com/zbrush-skin-brushes-pack/)
JRO using alphas (beware flashing images) | [Youtube (flashing images)](https://www.youtube.com/watch?v=dNUHjB4YK5c)
Alpha palette reference | [ZBrush Docs](http://docs.pixologic.com/reference-guide/alpha/)
Alphas and sculpting reference | [ZBrush Docs](http://docs.pixologic.com/user-guide/3d-modeling/sculpting/sculpting-brushes/alphas/)

Demo not on the pad but on sample objects: a block, a sphere.
* Making/sourcing an alpha. Setting the alpha.
* Brush drag modes: drag rect, dots.
* What brush to use? Layer? Standard? Chisel?
* How much resolution to support our alpha? Density and evenness of polygons.

{{< alert title="Booleans: keep your originals!" color= "secondary" >}}
Creating geometry from a boolean commits you to a certain topology that isn't easy to change: you won't be able to add loops easily or add bevels. If we create them early and delete our original separate objects (including cutters) we lose our ability to make those changes. This'll be fine.. if you've perfectly predicted everything you'll need.

Bingeing disaster shows on netflix/youtube tells us to always assume there's something you haven't predicted. 

Until you get to the final stages of your model it can be hard to know (in detail) everything you'll need your mesh to do. You'll discover things that change the situation a little, like maybe a font that has very thin elements or the way an alpha with a spiral creates weird effects at a certain resolution.

{{< youtube kjWM0wJHVTY >}}
*If you feel like making predictions, spend a few hours watching Plainly Difficult's collection of brief documentaries. It'll fix you right up.*
{{< /alert >}}

## Screws
Insert multimesh brushes!

{{< youtube "U5u3RpI9In4" >}}

## NoiseMaker

Bumpy surface on face of graphics insert (with nintendo, button names).

## Cable bend protection

It's a boolean hole containing two halfs of a trumpet thingy. How to make?

Two circles using cylinder of 32 sides to generate. Bridge em with interactive elevation?. Crease ends. Dynamic subdiv settings. Cut it in half with boolean to make little gap? Cut in half with subdivs and hopefully still get rounded shape? Use more curves.

## Homework

* Keep refining and finalising buttons.
* Colour things
* Duplicate your d pad and use alphas to create the arrow keys. You can make the bowl in the middle with alphas or geometry
* Use booleans to cut the holes for the buttons into their trims.

---
title: "7: ZModeler 3 - Radio"
linkTitle: "7. Hard 3 Radio"
weight: 70
description: >
  Starting a second model, the radio. How do we add parts? New primitives, import from Maya? 
resources:
- src: "barrel_alvaro_vera.jpg"
  params:
    byline: "Art: Alvaro Vera"
---

## Assessment 2:
 10 days left
 Complete and detail the NES pad, make some nice renders.

 ## What we'll learn today

* Stamping details onto high resolution surfaces
* Review: Generate a nice boolean

## Stamping in ZBrush

Demo not on the pad but on sample objects: a block, a sphere.
* Making/sourcing an alpha. Setting the alpha.
* Brush drag modes: drag rect, dots.
* What brush to use? Layer? Standard?
* How much resolution to support our alpha? Density and evenness of polygons.

{{< alert title="Booleans: keep your originals!" color= "secondary" >}}
Creating geometry from a boolean commits you to a certain topology that isn't easy to change: you won't be able to add loops easily or add bevels. If we create them early and delete our original separate objects (including cutters) we lose our ability to make those changes. This'll be fine.. if you've perfectly predicted everything you'll need.

Bingeing disaster shows on netflix/youtube tells us to always assume there's something you haven't predicted. 

Until you get to the final stages of your model it can be hard to know (in detail) everything you'll need your mesh to do. You'll discover things that change the situation a little, like maybe a font that has very thin elements or the way an alpha with a spiral creates weird effects at a certain resolution.

{{< youtube kjWM0wJHVTY >}}
*If you feel like making predictions, spend a few hours watching Plainly Difficult's collection of brief documentaries. It'll fix you right up.*
{{< /alert >}}

## Cable bend protection

It's a boolean hole containing two halfs of a trumpet thingy. How to make?

Two circles using cylinder of 32 sides to generate. Bridge em with interactive elevation?. Crease ends. Dynamic subdiv settings. Cut it in half with boolean to make little gap? Cut in half with subdivs and hopefully still get rounded shape? Use more curves.


## Homework



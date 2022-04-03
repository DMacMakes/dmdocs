---
title: "7. Style in texturing, Assessment 3"
linkTitle: "7: PBR Style"
weight: "70"
description: >
  Style applied to texturing.
---

## Learning this week

1. A3 Deliverables due this week
2. Surfacing from macro to micro
3. Implementing style

## A2 Deliverables due this week
**30% of assessment 2 marks,** according to the rubric, are tied to the process you go through in these first 3 weeks **as evidenced in your post to the discussion thread this week**. If you don't post to the thread you're risking a lot of marks, potentially a fail.

![Subtle metaphor](./baby_marks.gif)  
*Subtle metaphor.*

## Surfacing from macro to micro
It's easy to get lost in:
* The layer palette.
* The first or second surface you start texturing, for ever.
* The poperties palette for a material, a layer, an alpha etc.
* The fine details in one tiny nook of your model.
* The library of materials, filters, alphas, generators, brushes
* The web docs/lessons/discussions of all of the above.

It's the same problem when we're programming, 3d modelling, drawing characters and backgrounds, anything reall. We get so scared of the details and the finished product that we forget lots of things we know. Especially because we know those things so well, we forget we know them.. or don't know we know them.

All of these things can lead to:
  * a model that, while textured, looks strange and digital, awkward for reasons that are hard to define, 
  * A massive file with lots of duplicated work
  * Wonky, complicated layer structure, friction that stops you making changes.
  * Sadness.
  
### Thinking macro!

![macro thumbnails muddycolors](macro_thumbnails_muddycolors.jpg)
*https://www.muddycolors.com/2020/02/10-errors-to-avoid-when-composing-thumbnails/*

![Matisse steps back](macro_step_back_matisse.jpg)
Henri Matisse demonstrates stepping back for the big picture, also slick stick tricks.

### Working down in steps to micro

1. What affects the whole/multiple sections of model?
   * Dust, rain fall from above.
   * Dirt/splatters/damage from ground/near ground contact.
   * Ambient occlusion
   * Unifying tints/overlays
   * Artistic lightening of the focal point (often face and chest)
   * Various muck associated with usage
   * Emissions/secretions
2. What affects all of a single surface type, say varnished cherry wood
   * The same kind of surface damage due to it all being the same hardness
   * The same kind of UV fading/yellowing/dessication/cracking from sun exposure on all upward facing surfaces of that kind
3. What differentiates each surface of that same single type (again varnished wood)
   * Wood grain is different on the planks/panels of wood that came from different sections of one or many trees. If the grain goes from panel to panel it'll look unnatural, and it's something we'll all feel in a picture, though many of us will not realise what's actually wrong. Thinking about the big picture though, if you're making a giant wooden tank you probably would know that it's not going to be carved from a single, enormous piece of wood. Equally, a 5cm long carved wooden tank is probably not going to be make of 20 separate components, it'll be from one small piece of wood (a *blank*, if you're looking for a term).

### Saving time big to small

Working large at first, hitting all your surfaces with a basic material, balancing them against eachother as you iterate. This will save you a lot of time in reversing work later, or struggling to find a complementary material for a mismatched set as you get deeper. 

If you get the relationships close at the start, then can modify them easily in the early stages - since you don't have any complex layer stacks yet - you'll find that the easy read and broad appeal of the overall model will reduce the amount of detail you feel you need to pack in to get it working. 

### You'll always overestimate the need for fine details

We often don't see models from certain angles, or closer than a certain distance. Maybe we see the bottom of the feet, but only rarely, and heavily shadowed.

Detail also looks detailed not because there's so much detail.. but because an adjacent surface or feature has less detail. Our vision and cognition are based on movement and contrast - sharp vs soft, light vs dark, detailed/busy vs not.

Detail can also be too heavy when it happens in multiple colours, but fine if it's all in a given hue, changing only in tone (brightness).

The Valve [Dota 2 Character Workshop Character Art Guide](https://help.steampowered.com/en/faqs/view/0688-7692-4D5A-1935)

### ..and underestimate the importance of big, unifying details
  
This is often what makes work look appealing and/or real, work we'll subconsciously upgrade to "professional".  
  
* Top down dust, uv fading.  
* Inconsistent finish - every mm of a conceptually uniform surface is different.   
  
Even the toy-like simplicity of the Cars in Cars 3 is not as simple as your brain tells you it was. While you were watching, by the way, that same brain was kept happy by all the subtle details.  
  
An incredible resource: <https://renderman.pixar.com/stories/cars-3>  
  
![louise_1](https://pixar-community-production.s3-us-west-1.amazonaws.com/Cars_3/louise-nash-micro-vs-wide.jpg)

![louise_2](https://pixar-community-production.s3-us-west-1.amazonaws.com/Cars_3/louise-nash-micro-vs-closeup.jpg)

![louise render](cars3_louise_render.jpg)

## Style in video games
We touched on this last week as a concept. Implementing requires some deeper detail.

### Defining terms
When we all hear the same words all the time, we tend to define them the same way and like to agree about it.  

<img src="troll_face.png" width="200" />

#### *Realistic* game art:

![last of us 1](realism_lastofus2_1.jpg)
  
Element | Approach
--- | ---
**Characters, props and environments** | Have lots of fine, life-like detail referenced from real life. Cloth wrinkles, tree bark, anatomy and wear/dirt/damage are mostly laid out in according with the laws of physics/biology/material science, with little/no regard for rhythm, contrast, readability.  
**Lighting** | Comes from sources available in the environment and is reflected by objects in accordance with the properties of their real life counterparts, or the closes thing if we're dealing with fantasy/sci fi.  
**Post effects/filters\*** | Will usually enhance detail and contrast but in line with film grading of movies/tv. They'll often recreate the physical properties of lenses, and the way cameras are affected by light and the environment.  

\* *graphic effects applied to the whole screen once the scene is rendered in 3d*

![last of us 2](realism_lastofus2_2.png)

#### *Stylized* game art  

Element | Approach
--- | ---
**Characters, props and environments** | Often have only as much detail as is required to communicate broadly the nature of their surface and materials. Cloth wrinkles, tree bark, anatomy and wear/dirt/damage are often rendered in a simplified way, sufficient to communicate their nature, and often grouped, altered or exaggerated to add contrast, improve readability, add appeal and rhythm.  
**Lighting** | May come from sources available in the environment but also from hidden lights, or extra lighting is implied in shaders. It will often be reflected by objects in ways that are correct on some level but also exaggerated/simplified to improve our ability to read silhouettes, distinguish materials more readily, add an exciting dynamism or to alter mood dramatically.   
**Post effects/filters** | Can be used in a huge variety of ways. They too may add contrast and enhance detail. Typically they'll be used in many varied/creative ways that are often based more on principles of graphic design or illustration/painting than on physical properties of lenses/film. They'll do so to create mood, control/encourage the eye towards important characters/features (exaggerated depth of field), enhance a sense of action/motion, to evoke a style of poster/cartoon/school of painting, the possibilities are endless.  

## Homework

Complete the work specified in class (and listed for reference in the discussion threads) and post it in the Week 7 discussion threads. You can find links to the **Ultimo** and **Online** discussion threads in the assessments page:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../assessments/#submitting-your-work" target="_blank">Submitting A2 Week 7 Progress<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>
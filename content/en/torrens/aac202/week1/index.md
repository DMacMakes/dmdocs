---
title: "1: Characters in ZBrush"
linkTitle: "1. Characters"
weight: 10
description: >
  ZBrush is a critical tool for modern games studios; it's also the best way to sculpt on a computer.
---

## Welcome back

..and hello new people!

* Modern, current-generation 3D graphics.
* Learning Maya, ZBrush, some Substance.
* Immerse yourself in modeling. Practise always, just like drawing.
* Get your hands on a wacom or other drawing tablet! From week 5 we'll be using it every class and for homework.
* Assessments.

<!-- 

## Join the Discord server

Join the Torrens class discord server if you haven't already. Follow the instructions there to receive roles for each subject so you don't miss news/updates.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://discord.gg/a87M8dr" target="_blank">Torrens Class Discord Server<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

-->

### Recap

ACR103: 
  - Low poly modeling
    - Blocking out
    - Detailing
  - Rendering
  - UV unwrapping
  - Hand painted textures

## High detail modeling

This semester we're going to be working towards current-gen assets, with techniques that apply to both cartoony and realistic models.

{{< imgproc klaayas_room_wireframe_javier_rodriguez Resize "600x" Link "klaayas_room_wireframe_javier_rodriguez.jpg">}}
Round vs sharp, countour control!
{{< /imgproc >}}

Last trimester our goal was to make **low surface detail** props, using **hundreds of triangles**. To make up for the lacking geometry, we'd use [diffuse](https://docs.unity3d.com/Manual/shader-NormalDiffuse.html) textures, flat hand-painted images. Something like you see here:

{{< imgproc barrels_low_poly_textured Resize "500x" >}}
Low poly cartoony barrels.
{{< /imgproc >}}

**High detail** meshes can be made many ways and are **defined differently** depending on whether you're making games or film, whether the year's 2005 or 2020 and so on. Then those high poly details are brought into games using some tricks that we'll worry about that later.

{{< imgproc destiny_gun_1 Resize "900x" Link "destiny_gun_1.jpg" >}}
caption
{{< /imgproc >}}

{{% alert title="Why more polygons?" %}}
The end goal of adding polygons is to support **smoothly curving surfaces** and **fine details**.
{{% /alert %}}

More barrels can be found on my [aac202 Pinterest board](https://www.pinterest.com.au/dmacdraws/aac202/).

You could work toward high detail assets using our low poly process but.. on its own it would take a looong time. 

## ZBrush installation

You should all have now have ZBrush installed, lets add our custom UI, brushes etc. 

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../resources/#custom-zbrush-ui-and-resources">AAC202 Software Resources<i class="fas fa-arrow-alt-circle-right ml-2"></i>
</a>

### Brush testing project.

A ZBrush project containing a variety of forms to test out the main sculpting brushes.
<a class="btn btn-lg btn-primary mr-3 mb-4" href="trying-out-brushes.zip">Download trying-out-brushes.zip<i class="fas fa-arrow-alt-circle-right ml-2"></i>
</a>

## Digital sculpting?

{{< imgproc zbrush_trial Resize "600x">}}
ZBrush 2020.1
{{< /imgproc >}}

* What is sculpture (some classical, modern pics)
* Isn't Maya 3D sculpting?
  * Technically, sure
  * In practise it's focussed on points and edges and faces It uses transforms.
  * Generally useful in the < 100K polygons space
(One pic of Maya with smoothed object, maybe joystick)

{{< imgcard maya_app_witcher >}}
The Witcher 3 by CD Projekt S.A.
{{< /imgcard >}}

* ZBrush 
  * Focussed on smooshing and building and carving surfaces
  * Provides tools  a sculptor would recognise
  * Tries to automate the polygon part away
  * Happily works with millions of "polygons" by using a different paradigm internally

{{< imgcard zbrush_app_goblin >}}
Goblin by <a href="https://www.youtube.com/watch?v=Zp07GW3rND0" target="_blank">Flipped Normals</a>
{{< /imgcard >}}

{{< imgcard brushes_additional Link "brushes_additional.jpg" >}}
Many kinds of sculpting brushes
{{< /imgcard >}}

{{< youtube L6kYhShKXKY >}}

### From film to games

Many wrinkly monsters, festy zombies and gnarled trees in film have been created with ZBrush.

* When it was first made, games couldn't integrate ZB level 3D except in cinematics
* Won Oscar for contribution to film effects
* GPU accelerated normal maps came along, you could now steal the details from those high res models and approximate them on game models.
* Unreal engine (and whatever doom 3 was on??)

### Doom 3

{{< imgcard doom_3 Link "doom_3.png">}}
Doom 3, maybe the first big normal mapped game
{{< /imgcard >}}

{{< imgcard doom_3_2 Link "doom_3_2.png">}}
Doom 3 again
{{< /imgcard >}}

### Doom Eternal

Very current normal mapped assets

{{< imgcard doom_eternal_marauder Link "doom_eternal_marauder.jpg">}}
{{< /imgcard >}}

{{< imgcard doom_eternal Link "doom_eternal.jpg">}}
{{< /imgcard >}}

{{< imgcard doom_cyberdemon Link "doom_cyberdemon.jpg">}}
Original Cyberdemon Zbrush sculpt
{{< /imgcard >}}

## Intro to ZBrush

Using ZBrush on the uni computers or your own.

* Open a **STARTING SCENE I PROVIDE**
* Import the settings I give out (basic right click nav, not saving undo)
* Navigate
  - Right drag tumble
  - Right drag shift snap top/front/left etc
  - alt-right-drag pan
  - ctrl-right-drag zoom
* Save settings.

First marks:
* On provided sphere
* Standard brush: `b, s, t`
* Dam standard: `b, d, s`
* Move brush: `b, m, v`

{{< imgcard brushes_default Link "brushes_default.jpg" >}}
What you'll see when you press `b`
{{< /imgcard >}}

Brush controls:

Press space to access brush controls near the cursor.

{{< imgcard space_menu >}}
{{< /imgcard >}}

Adding mass:
* Still on sphere
* Clay buildup `b, c, b`
* Inflate `b, i, n`
* Smooth brush `shift`
* Snake hook `b, s, h`

More cleaning, subtools:
* Trim Dynamic `b, t, d`
* HPolish `b, h`
* Pinch (on dam standard) `b, p, i`
* Switch to cube subtool, solo.
* trim dynamic, hpolish the corners
* Now smooth, pinch

Pixelation?? Subdivision up down
* Subdivide: `Ctrl + D`
* Step up, down `d`, `shift+d`

## Free play

Play around and make a madball for 25 mins. 

Screenshot it and paste it into the **#discussion-aac202** channel on our Discord class server.

{{< imgcard madballz Link "madballz.png">}}
Madballz
{{< /imgcard >}}

## More Basics

Auto masking:
* switch to skinny object
* Show how sculpting damages back faces
* Backface auto masking
* Inflate brush (without backface mask)

Different Materials:
* how materials affect our perception: detail pops when shiney, not matte.
* Stylised materials a little
* Colours vs material

Getting Out Of Trouble
* things aren't moving - Lost edit mode (hit t)
* 

Watch out:
* Exiting edit mode by mistake (T)
* Getting back into it.

## Homework 

Pick a different Madball (the real foam ball, not a 2D  drawing from their site) and sculpt it as faithfully as you can in 2 hours. Do starting from the base sphere provided in `Trying_Out_Brushes.zpr`. If you already overwrote that file working on the class Madball, download it again for a fresh copy.  Use brushes like the standard, dam standard, pinch, inflate, move, hpolish and smooth to reproduce the  clean surfaces and creases. 

{{< alert title="Deliverables and Submission" color= "primary" >}}

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://torrens.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_120652_1&nav=discussion_board_entry&conf_id=_270525_1&forum_id=_1127461_1&message_id=_3008344_1" target="_blank">Madball Homework Submission ONLINE<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://torrens.blackboard.com/webapps/discussionboard/do/forum?action=list_threads&course_id=_120651_1&nav=discussion_board_entry&conf_id=_270524_1&forum_id=_1127446_1" target="_blank">Madball Homework Submission ULTIMO<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>
{{< /alert >}}

_**Bonus:**_ ZBrush has a super helpful filter called **Clay Polish**. Look it up in the zbrush documentation or on youtube. To try it out, add some random shapes to your free-play sculpt and hit Clay Polish. For this kind of sculpt it's a bit of a magic "make art" button.

{{< imgcard mb_detail_skullface Link "mb_detail_skullface.jpg">}}
Skullface Detail
{{< /imgcard >}}

{{< imgcard mb_views_skullface Link "mb_views_skullface.jpg">}}
Skullface
{{< /imgcard >}}

{{< imgcard mb_detail_slobulus Link "mb_detail_slobulus.jpg">}}
Slobulus Detail
{{< /imgcard >}}

{{< imgcard mb_views_slobulus Link "mb_views_slobulus.jpg">}}
Slobulus
{{< /imgcard >}}

{{< imgcard mb_detail_hornhead Link "mb_detail_hornhead.jpg">}}
hornhead Detail
{{< /imgcard >}}

{{< imgcard mb_views_hornhead Link "mb_views_hornhead.jpg">}}
Hornhead
{{< /imgcard >}}

{{< imgcard madballz Link "madballz.png">}}
Madballs
{{< /imgcard >}}

## Learning Resources

#### Great sculpts

A playlist of great sculpts, many of them timelapsed to <10 mins. Most of them were added over a year ago but they're no less great.

https://www.youtube.com/watch?v=e4LjwgFV8xw&list=PLfWza-ietxyywGqWIFLIuDeBK7DZ7Sych

{{< imgcard sculpts_preview_follygon_troll Link "https://www.youtube.com/watch?v=e4LjwgFV8xw&list=PLfWza-ietxyywGqWIFLIuDeBK7DZ7Sych">}}
One of the great vids by Follygon in this playlist.
{{< /imgcard >}}


#### Standard Brush with Michael Pavlovic

{{< youtube Rm5ZWj1h9GI >}}

#### Brush Palette and Move Brush

{{< youtube fb7WHVhKxu8 >}}

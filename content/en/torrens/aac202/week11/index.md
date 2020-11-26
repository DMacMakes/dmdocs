---
title: "11. Environments"
linkTitle: "11: Enviro 3"
weight: "110"
description: >
  Polishing our models, rendering for art director review. Submission!
---

## Covering today

- Week 10 post-review work
- Avoiding heavy, slow ZBrush scenes. Keeping your subdivisions as low as you can while getting just enough detail.
- Previewing/touching on week 12 and final target for assessment so you can work ahead now.
- Going back and forth with Maya, if needed, for shapes that are slow to make with your new ZBrush ZModeler skills, or simply beyond them. Here to deliver, not prove ourselves the mightiest ZBrush Warrior.

## Reviewing week 10 post-review work

How did you go extending your view to the pavers and trim, moving around your scene and balancing the levels of detail?

## Keeping your scene light.

Don't deliver a mammoth 800MB ZBrush file packed with multi-million polygon pavers and stones.

- If you have even loop coverage/polygon density to start with you should be able to get more detail with less subdivisions
- Aim to keep your bricks, even final deliverable ones, below 400K. 1m is too many.
- Pavers will be smaller than that. The top trim might be a million or a bit more?
- When you're done detailing a brick, drop the subdivisions down a level or two: enough to still see the style (or you can screenshot them) and/or shape. This will use less memory and zbrush will require less processor power, leading to smoother frame rates and quicker changes.

## Touching on Week 12 and A3 delivery

You'll be delivering some nice renders of your scene using just a single material, the Orb Clay gloss. To do so, you'll be following his lighting and rendering tutorial to produce sweet, composited images of your work.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../week12/" target="_blank">Week 12 notes<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## ZBrush to Maya and Back

{{< imgcard goz_menus>}}
Places you can 
{{< /imgcard >}}

GoZ! 
1. We close Maya and configure GoZ from within ZBrush. We set the path to Maya 2020, also choosing Maya as our GoZ target. 
2. We keep a minimal number of items visible for reference and send visible subtools to Maya. It'll send them at their lower subdivs iirc.
3. We can create and edit an item in maya (say a bent pipe) and then send it back to Maya.
4. If you need to send something in high detail but not with so many polygons you can duplicate + decimate a complex item, then send it to ZBrush. It'll have crazy triangle topology but it'll look pretty accurate and have as little as 5% of the orginial's poly count.

Feature | Documentation
------ | -------
GoZ | <http://docs.pixologic.com/user-guide/zbrush-other-programs/goz/>
Decimation master | <http://docs.pixologic.com/user-guide/zbrush-plugins/decimation-master/>

<!-- I saw people have commented. If you haven't updated your discussion post with your pier/wharf bits all added and polished, do it now!
-->
[Wharf/Pier discussion thread](https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_89547_1&nav=discussion_board_entry&conf_id=_152757_1&forum_id=_866562_1&message_id=_2100668_1)

## Homework due next week

After feedback this week:  

{{< alert title="" color= "primary" >}}  
1. Go ahead and **finish+place** your remaining wood/stone elements to wrap up the **main structures**.  

2. Using Maya+GoZ, or directly in ZBrush, create the quad-based geometry for **other items in the scene**: the heat pipes and vent on the side of the wharf, or the lifesaver+mussles+tin can+wavey water of the pier.  

3. Do some **first pass refinement** on them but don't go ham until you have some feedback 👍  
{{< /alert >}}

This homework is basically _recommended progress_, so you'll be ready for next class and on track to finish the  assessment. it isn't a marked deliverable in itself. 

Still I'd like you all to take screenshots and post it to the discussion 🙏

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_89547_1&nav=discussion_board_entry&conf_id=_152757_1&forum_id=_866563_1&message_id=_2254758_1" target="_blank">Week 11 progress thread<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>


### ZBrush Primitives

Ways to make primitives in ZBrush.
1. Primitives + init + make polymesh3d
4. Intermediate: Using the Gizmo cog.

Creating starting shapes using _primitives_
{{< youtube "wkBo64Ciapc" >}}

Turning a primitive into a usable, sculptable _polymesh3D_
{{< youtube "2cFUMTjGz6I" >}}



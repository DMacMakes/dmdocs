---
title: "6: Hard surfaces with subdivs 2"
linkTitle: "6. Hard surf 2"
weight: 61
description: >
  Modelling nes pads as smooth, very high resolution models, leveraging subdivision surfaces. 
resources:
- src: "*paul_chambers*"
  params:
    byline: "Art: Paul Chambers (Artstation)"
- src: "*krzysztof-maziarz*"
  params:
    byline: "Art: Krzysztof Maziarz (Artstation)"
---

## New resources!

Grab 'em from the [resources page](../resources//#custom-zbrush-ui-resources) and let's install.

## Modelling from objects
NES pad!

[AAC202 Hard surface board on Pinterest \(register if you don't have a Pinterest account\)](https://www.pinterest.com.au/dmacdraws/aac202/hard-surface/)

## Exercise (together)
Begin modeling the snes controller. Do I have to be able to understand and easily reproduce the wacom pen button modeling bit (including surrounds with crease) in zbrush to defensibly start with the snes pad? What about an NES pad? Or the radio/other boxier things?

![NES pad](nes_pad.jpg)

### Plan

How would we model the nes pad? To make something this structured and with multiple pieces we need at least a rough plan.

#### Body
Rounded box. Exceptions to this?
* Tray in middle for select/start
* Cable opening
* Notch
* Button openings? Around buttons there's a small gap, sharp cut.

![NES pad back](nes_pad_back.jpg)
![NES pad classic top](nes_pad_classic.jpg)
![NES pads crusty](nes_pads_crusty.jpg)

#### Buttons
Buttons have a variety of shapes, finishes and top surface profiles.

Buttons     |  Shape   |  Top profile  |   Material
----  | ---- | ---- | ----
A B | circle | concave (valley) | red shiny plastic
Start / Select | Line rounded ends | convex (hill) | black matte rubber
D Pad | plus | spherical concave<sup>&dagger;</sup> | black shiny plastic 

*<sup>&dagger;</sup> Like a large sphere has pushed down into the plus, leaving a rounded depression.*

### Files
Grab the project folder. This gives you an example project folder structure, which you need when you're combining multiple programs to get your results.

[Download nes_pad.zip](https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/EY-qTlynY2dPrr_goeiuh5wBHOw2ls9hx8VCyHtBjKYyMg?e=VycjRi)

<!-- 

## TODO: Is radio actually easier?

It doesn't have those shoulder buttons to worry about, or the off-angle start and option buttons needing bevels.
Maybe change how the middle is added so we're not as bothered by extra geo?
Adding flat colours early to help our eye.


## The rest

* Cut off bits of end cylinders
* bridge ends
* Add geo to middle alrea
* Making buttons
* Bevel around buttons? Can do later with booleans when we're more settled on their shape?
* Adding and tweaking d pad?

-->

## Homework

Keep working on nes pad model.

Plan feature a.
Implement a and b.

Post progress in forum.

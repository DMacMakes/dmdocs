---
title: "12. Finishing Assessment 2"
linkTitle: "12. Finish A2"
weight: 120
description: >
 Finalising details, texturing in ZBrush, rendering.
---

## Assessment 3 Final push 

What are we delivering? That'll define how we spend our last few days on the project.

[Assessment 3 - NES Controller on dmdocs](../assessments/#2-hard-surface-model-nes-controller)

## Last 5 percent

Details should be 95% done (or done) by now, but you might have one or two hard-solves left to figure out.

### Hard geometry problems

Hit me with any surprise hard geo problems now, I might have easy solutions.

### Week 7 problems - alphas/imm

Any issues with alphas and insert mesh brushes that weren't covered in class or review?

## Materials and textures

Note: If you absolutely *can't* texture the insert you can try photoshopping it into a render/composite. You'll do better marks-wise if you get this nutted out.

### Standard Materials - when Matcaps won't do it.
Matcaps use an image and some fancy tricks to act like materials do in other 3d renderers (think Arnold in Maya for example) while being less work for your computer. They're really limited though; matcaps get darker not only in colour as you add black, their fake lighting/hilights disappear too.

If you want more control over the materials on your NES pad you can use the Zbrush *Standard Materials*.

{{< imgcard standard_materials Link "standard_materials.png">}}
The standard materials are found below the matcaps in the materials popup palette.
{{< /imgcard >}}

Here's an example of using a basic material to get closer (than zbro paint) to the shiny black plastic of the dpad. I used a dark grey, lowered the "diffuse" (non-shiney lighting) and raised the specular (shiney hilight brightness), while messing with the specular falloff curve (blurrier shiney hilight).

{{< imgcard dpad_basic_material Link "dpad_basic_material.png">}}
Turning up the specular lets the rounded edge pick up bright hilights.
{{< /imgcard >}}mgcar

{{< alert title="Making new materials is WEIRD" color= "primary" >}}
To use another instance of a standard material like Basic Material or Toy Plastic you have to click *Copy Mat* (in the material palette), select another standard material *that you're happy to lose* and then *Paste Mat*. 

ZBrush is definitely not a world class materials/rendering program.
{{< /alert >}}

### Material exercise

Reproduce the d-pad's black plastic material. Duplicate it and make a red plastic, which will have a sharper hilight and be much brighter/more saturated.

## Texture mapping

Texture-mapping the graphic insert. Let's do it together.

### Exercise

Right click and save these images to your project folder.  

<img src="insert_texture_buttons.png" width=320 /><img src="insert_texture_rough.png" width=320 />

1. In your project, select your graphics insert (the piece of plastic with writing printed on it). Make a duplicate to work on, turn off the original's visibility (eye) icon.  
2. Under *tool -> texture map* click the big empty texture and click *import*. Load `insert_texture_buttons.png`. Note it's not visible on your mesh. You might have even been warned that it doesn't have uvs.   
![import texture](import_texture.png)  
3. Open the *UV Map* palette (above the Texture Map one), set the *UV Map Size* slider to 1024 and just click *Create -> UVP*. Turn off the floor (shift-p) to make sure you can see the new texture.  
![uvmap uvp](uvmap_uvp.png)  
4. It might be dim or coloured strangely. Fill the graphics insert with ZBro paint (matcap) and white (colour) - the texture map is tinted/rendered based on whatever material is under it. Annoyingly, the texture has it's own Fill mat, so expand *Tool -> Texture Map -> Fill* and click *Fill Mat*  
5. You can check the alignment of your buttons etc against this texture map, but this one's a really dodgey hack job. Make a polished version of the texture with clean lettering/shapes and better colouring. Add noise to the surface with noisemaker if you haven't already.  

{{< imgcard textured_inset_rough_zbro Link "textured_inset_rough_zbro.png">}}
The graphics insert with the rough texture applied and visible in the viewport+renders.
{{< /imgcard >}}

<!--
## Transferring the details

Normal mapping!
Substance Painter!

{{< imgcard axe_zb Link "https://dmcgits.github.io/mds/workshops/painter/painter_notes.html">}}
Click here to open the Painter workshop notes
{{< /imgcard >}}

Requirements:

**Two collections of meshes.** Each collection can be saved into an fbx format file.

1. Very **detailed meshes** of the prop parts that look very nice but are too heavy for games. 
2. The **game ready mesh** with uv maps.
   * These should have hard edges wherever there are seams/texture borders in the uv map, and soft edges everywhere else.
   * Freeze any scaling (probably already done for uv unwrap)

**Magic software:** It **scans the surface** of the high detail meshes, tosses away the polygons, and **makes an image** from their skin that **the game ready mesh will wear** like a suit.

![](skin_suit.jpg)

### Our mug exports

![](mug_export_game_subd.png)

1. **mug_game.fbx**: The _game meshes of the mug body, handle and coffee. 
   * This is only about 50KBs.
   * Make sure they all have the same material.
2. **mug_subd.fbx**: The _subd meshes of the mug parts, but subdivided and smoothed for real. We'll use Maya to export the subd meshes and apply the smooth and subdivide algorithms along the way, producing tens or hundreds of thousands of real triangles.
   * This sounds backwards but you have to have _smooth meshes_ **un**selected when you export the subd meshes, or they'll export the unsmoothed versions. You got it right if the file will be megabytes in size.

## Baking your model in Painter

Grab these:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="A1_bake.zip">A1 Painter Baking Files<i class="fas fa-arrow-alt-circle-right ml-2"></i>
</a>

Watch this:

{{< youtube v5b0z5FLXDk >}}

-->

## Week 4 Final Submission details

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../assessments/#week-4-submission-details">Week 4 submission details<i class="fas fa-arrow-alt-circle-right ml-2"></i>
</a>  

<!--   
Open your Maya projects. We're going to try to resolve any problems you're having exporting your files for baking in Painter.

First, if you:
- Don't know what meshes to make or what to export, then it's very possible you haven't carefully read through the updated week 3 notes that were mentioned in the announcement sent out on Saturday: 
  - Read those (don't skim), and check if your question was already answered.
    - Grab and examine the updated Maya project.
  
  https://dmdocs.netlify.com/torrens/aac202/week3/#how-it-all-works
  
Other problems we'll look at:
  - Fixing any weird subds and smooth preview errors
  - Errors stopping Maya unfolding/laying out your game mesh.
  - Everything looks to be set up right.. but the bake is failing/has errors  
  - It's baking but the result still looks low poly

### Updated Arcade Stick Files

These also contain the baking project you'll use today to import your model.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/ETl9ulaSrI9LlLCR05OObgoBjILw7NO0KUpV_aFLyMV66w?e=HFsDQb">Arcade Stick V2 Maya<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>
<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_laureate_edu_au/EbGYxoT6oiNLlvRKy42Gt-gBla0ZvIzXG04Akn0MG_GzLA?e=SsJOGf">Arcade Stick V2 Painter<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

## Substance

First, looking through the updated arcade stick scene.

{{< imgcard arcade_stick_baked_painter Link "arcade_stick_baked_painter.png">}}
Wireframe over normal mapped game mesh, normal mapped game mesh, roughly textured game mesh.
{{< /imgcard >}}

### Starting With Configured Scene

I've created a _Substance Painter_ project you can use for baking.  The settings are already tweaked for our workflow and for checking the quality of the baked maps. There are a few straightforward steps to using it:

First, in _Maya_ (as in week 3 notes):
* Append `_game` to the end of all your game mesh names (as above)
* Append `_subdiv` to the end of all your subd mesh names (as above)
* rename the material on your game meshes to game_meshes_mat
* Ensure your **game mesh has been UV mapped** and unwrapped. The **subd mesh doesn't require a uv map.**
* Ensure your game mesh UVs all fit within 0-1 uv space (the default square in UV editor)
* export all `subd meshes` together as a `single file` (eg `joystick_parts_subd.fbx`)
* export game meshes together as another single file (eg `joystick_parts_game.fbx`)

In _Painter_:
* Open the `firstname_lastname_baking.spp` scene.
* Click _Edit -> Project Configuration_ (image below)
* Click _Select_
* Choose your `thing_parts_game.fbx` file
* In the _Texture Set Settings_ panel click _Bake Mesh Maps_ and then the tiny document icon beside the _High Definition Meshes_ list.
* Choose your `thing_parts_subd.fbx` file.
* Click _Bake game_meshes_mat Mesh Maps_


{{< imgcard baking_project_configuration Link "baking _project_configuration.png">}}
The baking project has a button and its trim. You'll replace the meshes with your own.
{{< /imgcard >}}

### Baking

Next we'll click _Bake Mesh Maps_ in _Texture Set Settings_

{{< imgcard texture_set_pre_bake Link "texture_set_pre_bake.png">}}
The texture set dialogue before you bake anything. 
{{< /imgcard >}}

{{< imgcard painter_bake_settings Link "painter_bake_settings.png">}}
In the Joystick scene I used 2048, start with your resolution at 512 or 1024 for a quicker test.
{{< /imgcard >}}

{{< imgcard texture_set_post_bake Link "texture_set_post_bake.png">}}
If your bake succeeds, Painter connects all the new textures.
{{< /imgcard >}}

### Reference: Map Types

|  Map Type           |  What It Contains              |
|-------------------  | ----------------------------------------------------------------------|
| Normals             |  Info about where a polygon was facing at this point on high res mesh |
| World Normals       |  The same info, relative to the worl (not the given game mesh poly)   |
| Ambient Occlusion   |  Results of any bounced (indirect) light (soft and blurry)            |
| Color ID/Clown map  |  In this case, a different colour for each subdiv object that was separate in maya. |
| Curvature           |  White where the subd was convex, black where it was concave          |
| Position            |  Location in the world of every triangle in the smoothed subd         |
| Thickness           |  White means subd was thick, black means thin. Good for candles, skin etc |


### Environment settings (show wires, rendering quality, studio lighting, rotate environment)

We'll step through these.

## Deliverable This Week

You'll create images and submit them in an archive with one of your scene files.

###  Painter images
Pic a 2 or 3 camera angles to show off your object. For each one, capture at least two images:

1: Object with normal maps enabled, using default white material.  
2. The same again with wireframes enabled.  
3. This time turn on any materials you’ve applied, and turn off wireframes.  

###  Maya Images
Hide your game meshes, unhide all your subd meshes. Pick two angles and take screen shots with `wireframe on shaded` enabled and:
1. Normal view enabled (press `1`)
2. Subd smoothing enabled (press`3`)

### Scene File
Do **one** of the following:

1: If you successfully bake your textures, submit your *Painter* `spp` file.
2: Otherwise submit your *Maya* `.ma` or `.mb` scene file

### Archive  
1. Gather your images and scene file in one folder. **compress** the folder with `.7zip` or `zip`
2. Name the archive:
   `firstname_lastname_A1_AAC202.zip`
3. Submit on Blackboards assessment 1 page.

If you have trouble with the large file size, upload it to a service like *Dropbox* and submit the link.

## Texturing

Mask by color selection.

## Presenting Our Results

* Real time rendering.
* Screenshots
* Environments
* Post effects
  * Don't go overboard on these. It's a rabbit hole, and won't fix mesh problems :\

### Summary
1. Finalising models
2. Exploring updated Arcade Stick files
3. Importing meshes and baking high res details to texture maps.
3. Deliverables
3. Lighting/materials
-->


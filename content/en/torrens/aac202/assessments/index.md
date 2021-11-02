---
title: "AAC202 Assessments"
linkTitle: "Assessments"
weight: 5
description: >
  Assessment dates, briefs, deliverables.
---

{{< alert title="Note: Order of assessment change" color= "warning" >}}
Your assessments won't be delivered in the order shown on Blackboard. We'll be **completing them in the order shown in the table below**.  

Due dates have been manually updated, so we're golden 👍
{{< /alert >}}

Order  | Deliverable       | Due     | Blackboard number
---    | ---               | ---     | ---
1      | character sculpt  | Week 4  | 3
2      | prop model        | Week 8  | 1
3      | prop texture      | Week 12  | 2


## 1. High Poly Character (week 4)

**Create a bust from an existing 2D concept:**  
1. Select one of the heads from the concept art [below](#concepts)  
2. Starting with a clean copy of the provided base mesh, sculpt a high quality, polypainted 3D model of the character. Draw on what you've learned in your first attempt plus your week 3 ZBrush class (polypaint, merging, dynamesh).
3. **Progress Delivery:** Before your **Module 3 review** session, show your progress [in the week 3 forum thread](https://torrens.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_115852_1&nav=discussion_board_entry&conf_id=_246176_1&forum_id=_1064202_1&message_id=_2874224_1) provided by your lecturer. Your participation and display of process **is worth 30% of total marks** for this assessment..
4. **Final Delivery:** Deliver your final ZBrush project and renders at the end of **Module 4** for the **remaining 70%** as described below.

{{< alert title="Final (Module 4) Delivery" color= "primary" >}}

**Elements:**  
1. Your final **ZPR file**  
2. **Renders** (`shift+r`) of your character from multiple angles, with polypaint on.  
   * **Side, front, back** (with perspective enabled: press `p`)  
   * A **beauty render 3/4 angle** to show off the character. You can polish it a bit in photoshop.  
   * Don't have the character tiny in the middle of the canvas. Move zbrush to your largest screen and have the character take up most of the canvas.  

**Zipping and delivering:**  
1. Put your beauty render, other ZB screenshots and your final ZPR file in a folder.  
2. **Rename that folder** `AAC202_A1_Lastname_Firstname` and archive it with zip or 7zip.  
3. The file is likely large, so use the Torrens LFS to upload it. If you haven't used it, instructions are at [the end of this page](#torrens-large-file-system).   
4. Submit on Blackboard under **Assessment 3** (Character model)
{{< /alert >}}  

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://torrens.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_10055547_1&course_id=_115852_1" target="_blank">Online Students: Submit Character Assessment<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>


### Concepts  
Choose one of the concepts below, or click one and visit Patri Balanovsky's page to pick another **from the same artstation page** (not all of his artstation content). Be careful not to pick one that requires extra meshes (hair, horns, eyepatches) if you're not confident creating new meshes. Don't stretch the head to support large horns, hair etc.  

{{< imgproc "patri-balanovsky-alien-faces-5" Resize "600x" Link "https://www.artstation.com/artwork/n6X1r" >}}
faces-5
{{< /imgproc >}}

{{< imgproc "patri-balanovsky-alien-faces-8" Resize "600x" Link "https://www.artstation.com/artwork/n6X1r" >}}
faces-8
{{< /imgproc >}}

{{< imgproc "patri-balanovsky-alien-faces-12" Resize "600x" Link "https://www.artstation.com/artwork/n6X1r" >}}
faces-12
{{< /imgproc >}}

### Some polishing ideas:
  * Cropping to a nice composition
  * Warming/cooling shadows, maybe improving the contrast
  * Adding rim light  
  * Adding gloss/specular hilight/shine to some elements
  * Painting in eyelashes and eyebrows that you didn't have geometry for



---

## 2. Hard surface model: NES Controller   


Model the NES pad as close as you can to completion. Focus on controlling the silhouettes and sharpness/softness of transitions between surfaces.  

![Nes pad](nes_pad.jpg)

More info on level of detail and finish is [available below](#level-of-detail).

### What to submit

Create a zip file named *aac202_a2_Lastname_Firstname.zip* containing the following.

* Renders/screenshots showing your finished model off from varous angles, including closeups where they help.
* At least one beauty render, preferably composited and polished.
* Your final ZPR project file.

### Delivery

While this our second assessment, you'll be delivering it to the *Assessment 1* section on Blackboard.  Upload your zip file to Torrens LFS (instructions below) and submit your link to Blackboard:


<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://torrens.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_10055546_1&course_id=_115852_1" target="_blank">Online Hard Surface assessment blackboard<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

#### Level of detail

Element       | Detail
---- | ----
Objects | Focus on using edge loops and creases to **control all the silhouettes and contours** as well you can. Use **booleans** to cut openings around the buttons so they don't merge into solid plastic. In those places where you can see inside the model, put black blocking objects inside to **prevent seeing through**. Use **real subdivisions and alphas** to add embossed details to the d pad, and **noise maker** to add realistic bumpy finish to the graphics inset (bit with the button names). 
Materials | At a minimum use the ZBro Paint matcap. Try other materials to see if you can represent the glossy red plastic and metal screws better. 
Color | If using ZBro paint, at a minimum fill with flat colour. You can add more subtle aging and colouration with polypaint if you like. If you use metal matcaps or pre-coloured plasticy matcaps, you might need to fill with just white to get the right result.



## Assessment 3: PBR Texturing

<!--  

**Final Submission: Midday, Wednesday May 12** 

Texture on of the provided models using Substance Painter.

Name | Pic | Substance File 
---- | ---- | ----
Service Drone | ![service_drone](service_drone.png) | [service_drone.7z](https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_torrens_edu_au/ESXh4gp2iJFFh9dLbNnYjzQBcArqiT2OAQvl9KWQGmbrRA?e=P7a6xz)
Mini Axe | ![mini axe](mini_axe.png) | [mini_axe.7z](https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_torrens_edu_au/EWhxYg7NmZdPh7KgPYHbdlkBOaJsUuUIa6EtRoPqywDvzw?e=dBlWxO)
Knife | ![knife](knife.png) | [knife.7z](https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_torrens_edu_au/ESwqpRmQvNNOjqrgkizkBk0BlHujqs_HVOlJoG9drjwX9A?e=DLMBho)
Arcade Stick | ![arcade stick](arcade_stick.png) | [arcade_stick.7z](https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_torrens_edu_au/ER_K_UxRxOdBqUDZFWVbBzwBlrSSWW8zO-r_5ojKb7IFQA?e=OKKpYR)
Boot* | ![boot](boot.png) | [boot_david.7z](https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_torrens_edu_au/ESFT4HJ9hD9Nv8MSnHhUzVoBHw2VI6-SmQdHtq5nln6dcQ?e=NmFmkR)  
  
\* *Boot is here because David Neselius (online class) wanted to texture his own model, but you're welcome to choose it too - just remember to credit him as the modeller if it ends up inyour folio* 👍  

### Reference   
Here's some reference for cartoony styled 3D using with a PBR look:

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureateaus-my.sharepoint.com/:u:/g/personal/daniel_mcgillick_torrens_edu_au/ERA4hias9nhIhR7BR7gRS-wBxOEJcPHfESPt26k3y8Qayg?e=hiFZFO" target="_blank">PBRCartoonyLook1.pur.7z<i class="fas fa-arrow-alt-circle-right ml-2"></i></a> 

### Submitting your work:

#### Week 11: Submit progress to Blackboard threads:

You can find the submission threads and the requirements at the following links:

Class location | Link to discussion thread
----------- | ------------
Ultimo class | [submission thread](https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_102604_1&nav=discussion_board_entry&conf_id=_201885_1&forum_id=_968751_1&message_id=_2632676_1)
Online class | [submission thread](https://laureate-au.blackboard.com/webapps/discussionboard/do/forum?action=list_threads&course_id=_102086_1&nav=discussion_board_entry&conf_id=_201367_1&forum_id=_968736_1)


#### Week 12: Final submission 

**Due: Midday, Wednesday May 12** 

What to Submit:
1. Final Painter project (*.spp file)
2. Screenshots 
3. Your real life and style reference.
4. Sketchfab link to your uploaded model

How to submit:
1. **Zip** your final painter project, reference files(pur) and screenshots into a single zip
2. Upload it to Torrens LFS. 
3. Export the final version of your model+textures to Sketchfab.
4. Submit the **LFS link and the Sketchfab link** to Blackboard under *Assessment 2: Model Surfacing*.

Class | Submission link
----  | -----
Ultimo | [Assessment 2 on Blackboard](https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_9586561_1&course_id=_102604_1)
Online | [Assessment 2 on Blackboard](https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?course_id=_102086_1&content_id=_9586490_1)

-->  


<!--

For Assessment 1 you'll create a **high detail, normal mapped** prop using **techniques shown in class** and developed at home. These will include subdivision modeling, normal mapping and PBR textures.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_9223157_1&course_id=_94273_1" target="_blank">A1 submission and brief on Blackboard<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

You'll be **targeting an environment concept** provided in the Week 1 notes, and **working to a style** provided there:
[Assessment 1 in Week 1 Notes](../week5/#assessment-1-high-detail-props)

There are deliverables for **week 1**, **week 2** and **week 4**.

### Week 5: Concept, style, tutorials
**Select** a prop to model, share your choice. Choose style reference, watch and take notes on subdivision modeling videos. Follow the link for details and to submit your work:

NEEDS UPDATING

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_94273_1&nav=discussion_board_entry&conf_id=_170634_1&forum_id=_902732_1&message_id=_2295833_1" target="_blank">A1 Week 1 Submissions<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### Week 6: Assessing, drafting, modelling.

**Assessing** style, **drafting** your topology, **modelling** your prop. You'll share the results with your classmates and offer eachother **feedback**. Follow the link to the discussion forum for details and to submit your work:

NEEDS UPDATING
<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_94273_1&nav=discussion_board_entry&conf_id=_170634_1&forum_id=_902733_1&message_id=_2278364_1" target="_blank">A1 Week 2 Submissions<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

-->

<!--

#### Work to do  

Copy the concept image into a new file and:  
  1. Add notes/drawings to the concept of the prop to **plan style**
  2. Add notes and draw over a duplicate of the concept to plan your **topology**
 
**Model** your prop :
  1. **Block in** the model (in pieces) with:   
      * dynamic silhouettes considered   
      * topology that won't cause problems for subdivisions  
  2. Then use edges and creases to create **bevelling/rounding** and smooth shapes.  
  3. **Refine** your model, add details.
  
#### Process images due TUESDAY by end of day:

1. Add a reply to [the discussion here](https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_89547_1&nav=discussion_board_entry&conf_id=_152757_1&forum_id=_866554_1&message_id=_2100660_1), containing:
    * **1 image** of the concept with your notes/drawings planning style and topology solutions
    * **2+ images** of your model with smooth preview off (press `1`)
    * **2+ images** of your model with smooth preview on (press `3`)
    * **1 image** of your model with all parts selected and the **outliner** visible (to see your objects and their naming)
  
{{< alert title="Image qualities" color= "secondary" >}}
> All images should have plenty of resolution (at least **1024x768** and preferably higher). Deliver as 24bit PNGs or JPGs of 85% or greater quality.  
> 
> Screenshots of the model in Maya:
> * Have shaded view, wireframe on shaded and ambient occlusion enabled
> * Use camera angles that show off the model and also the geometry you used to achieve the right smoothed forms.
> * Are from a viewport that is large and with the model zoomed large within it, producing clear images. No tiny thumbnails.
{{< /alert >}}
  
#### Comments due WEDNESDAY, before class (3pm)
Comment on two other students work, offering well thought out feedback:
1. In matching capturing the concepts and matching the 3D style what did they do well?
2. What changes/additions might improve the model?

-->

<!--
### Week 8 submission details

**Delivery:**
1. Create a folder for your final deliverables. Call it `Firstname_Lastname_A1Final_AAC202`
2. Copy into the folder:
    * Your **final maya scene file**. In your scenes folder, find your latest `.ma` or `.mb` file. This contains your final `_game` and `_subd` meshes.
    * The **renders and screenshots** described below
3. Zip up the folder and submit the `Firstname_Lastname_A1Final_AAC202.zip` file to the [assessment 1 page on blackboard](https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_8989774_1&course_id=_89547_1)

**Images Required:**
**Normal Mapped Renders**  
Screenshots of your normal mapped prop in Substance Painter (as shown in week4 baking video). Bake your textures at 2048 and turn on 4x4 anti aliasing.

**Hero shots** Pick a camera angle and lighting that shows your model at its best. Then screenshot once with wireframes on, once with them off (also in baking video)
**3/4 isometric** shot. From 45 degree vantage points as seen below
**Detail shots**. A few closer in shots of your details, showing how the normal mapping worked out.

{{< imgproc isometric_angle_rgbfumes Resize "300x">}}
Isometric projection.
{{< /imgproc >}}

Deliver **PNG24 files** or jpgs of at least 85% (8.5/10) compression quality.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../week4/#baking-your-model-in-painter">Back to Week 4 Baking<i class="fas fa-arrow-alt-circle-right ml-2"></i>
</a>

-->

<!--

---


## Assessment 3: High Poly Environments

Team of two: Work as Stone Mason (building a wharf) and Carpenter (building the wooden pier).
Individual: Pick one role or the other.


LINKS NEED UPDATING 

First, the [view the pdf brief on Blackboard](https://laureate-au.blackboard.com/bbcswebdav/pid-8989823-dt-content-rid-18209833_1/xid-18209833_1)

You will model the stone wharf or wooden pier in the concept art found in week 9's lecture notes

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../week9/#assessment-3-rock-n-wood" target="_blank">Concept in Week 9 Notes<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

### Deliverable 1:
Images, answers to questions, comments on classmates work in the discussions for:
  * [week 9](https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_89547_1&nav=discussion_board_entry&conf_id=_152757_1&forum_id=_866561_1&message_id=_2243100_1) and  
  * [week 10](https://laureate-au.blackboard.com/webapps/discussionboard/do/message?action=list_messages&course_id=_89547_1&nav=discussion_board_entry&conf_id=_152757_1&forum_id=_866562_1&message_id=_2100668_1)   
  
  **Deliverables and guidelines** are in the **first post** in each thread.

### Deliverable 2:  

Watch the step-by-step tutorial provided in the [finishing section of the week 12 notes](https://dmdocs.netlify.app/torrens/aac202/week12/#finishing). Create the required work, and submit the LFS file link on Blackboard.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_8989776_1&course_id=_89547_1" target="_blank">Final A3 Submission on Blackboard<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>

{{< alert title="Submitting Your Files" color= "primary" >}}
1. Put your beauty render, other ZB screenshots (described below) and your final ZPR file in a folder.
2. **Rename that folder** `AAC202_A3_Lastname_Firstname`, zip it up.
3. Use the Torrens LFS to upload it (instructions at bottom of page).
4. Submit the link on the Blackboard submission page.
{{< /alert >}}

**Images**
1. Using orb's method of rendering and then compositing in photoshop, **produce one final beauty render** of your model from what you feel is the best angle to show it off. Make sure it's not tiny on screen, we need resolution.
   - I'd first investigate if the angle in the concept art is best, it may well be. 
   - Export the image from photoshop (File - Export - Export As) as a 24 bit png.
2. Take some screenshots of renders done within zbrush (shift-r) as well, showing off your work from various angles/zoom. **No more than 4** screenshots.
-->

---

## Torrens Large File System

{{< alert title="Linking a zip file from _LFS_" color= "primary" >}}
The **_Torrens Large File Submission_** cloud drive is where you upload your large assessment files. 

1. Follow the **video instructions** on the front page (scroll down) to upload your file into the `Trimester2 / ACR103 folder`  
2. generate the **_share_ link** you need for your Blackboard submission.  
  
<a class="btn btn-lg btn-primary mr-3 mb-4" href="https://lfs.torrens.edu.au" target="_blank">Torrens LFS<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>
{{< /alert >}}


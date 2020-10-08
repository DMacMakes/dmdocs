
---
title: "Week 4: Threads at war"
linkTitle: "4. Thread war"
weight: "40"
description: >
  Creating order from chaos, and effiency from planning.
---

## Weeks 1-4 and assessment 1 update

| W | **Topic**  | Class and assessment  |
|----|-------------- |-------  |
| 1 | **Computer abstractions**, hello | PC arch. Build videos and textbook diagrams, forum intros |
| 2 | **Parallel processors: Intro threads.** | Threads in theory and in C++. Lab: quicksort multiple lists. Graphing. |
| 3 | **Threading challenges, sync** | lab: threads to sell movie tickets, observing challenges. | 
| 4 | **OS, Process/thread mgmt** | implementing solutions to thread challenges. Mutex, User vs kernel space, cost threads. |

## Assessment 1 Final week

Lab 3 is our final part of assessment 1 and due this Sunday.

<a class="btn btn-lg btn-primary mr-3 mb-4" href="../assessments/#lab-3" target="_blank">Go To Lab 3<i class="fas fa-arrow-alt-circle-right ml-2"></i></a>


## Greedy threads

We don't give any priority to our threads, and we give them lots of work while limiting their resources. This leads to frenzied competition, and we've left the operating system in control. It's a bit like at those weddings where they have a buffet and there's not enough meat/good dessert, or if you have a fill-your-own lolly bag setup. At worst, it's a free for all. Under better conditions, a relative steps up and starts trying to limit the damage and make sure everyone gets a bit.

(At a wedding queueing doesn't work without public shaming, so make sure the buffet is accessible from both sides and people are standing around being judge. If you don't, aunties who come first get all the chocolate etc and there's only green jellybeans and those nasty little dry banana lollies for everyone else. 

### Oversubscription

 We can make as many threads as we want. But should we? Like most problems worth solving.. it depends.
 
 You might think 8 threads on a 2 or core machine is fine. Or 16 on an 8 core. 

Let's look at at my lying drawing of threads being orderly. Threads aren't doing that though. They all want in right now, and the operating system is all flustered and trying to serve them all at once. 

{{< imgcard "oversubscription_quicksort">}}
From no threads, to just enough, to too many.
{{< /imgcard >}}

Load balancing means anyone waiting gets a shot unless they've been deprioritized. We don't have direct control over that without getting very cpu specific, so what can we do? Manage!

## Race conditions

We covered these in the work review last week. Essentially, when multiple workers (threads) can access and change variables, things get very unpredictable.

* You both check a variable at the same time, do something with it (like add 1) and write back. 1 + 1 + 1 = ... 2.
* You see an item at your store is in stock, and you begin to sell it. In the mean time your assistant (who had checked the stock just before you before you) sells the stock and marks it as sold. Depending on your system, you end up selling the same tickets, or being rejected by the system as you go to finalise your sale. 

### Exercise: Get money

1. Lao and Penny are looking really bad. Type out the code, find out how bad. Screenshot the result to Discord.

{{< imgcard get_money_race Link "get_money_race.png">}}
Lao and Penny are working hard, but are they RIPPING ME OFF?
{{< /imgcard >}}

2. Fix it with mutex!
3. Fix it with Atomic!

### Mutual exclusion

Mutual (both) exclusive (one only.)
Both agree that only one of you may access a thing at a time, under certain conditions.

* Service station/cafe toilet. One key, you can only get in once the key is returned. 
* Held stock: When ordering online, once you put something in your cart (or enter the checkout) you may have x minutes to buy before it goes back on the shelf. Otherwise it could be bought out from under you while you continue buying more, a nasty experience.
* 

### In our cinema

Why is it good to use mutual exclusion if it removes the thing we were after: parallel execution?
* Anyone who's worked in retail know this much: customers take time to decide, to order, and to gather their stuff, put away their change/cards, argue/goof with their partner/kids/mates and leave.  We had sleep at start of sellSeats for that, I should have added some at the end too, and made it longer. 

## System considerations

- Operating system security rings
- Kernel vs user space

* sum: threads in cpp are in user space. os has secure kernel space and less secure user. takes time to switch, and special rights to set priority. we're not doing that, so the os is making scheduling decisions, and probably the c++ compiler builds in default scheduling decisions.
* it takes time and incentive (projects with specific needs) to learn all the ins and outs, but what you *can* learn is awareness of the category of provlems, how to check for their symptoms, how to code safely for them, and the terminology to google and read deeper into it!

{{< alert title="Key terms to remember" color= "primary" >}}
You gain power over a topic (and there are plenty of topics in software engineering/computer science) by learning the big abstractions. These are the umbrella ideas that cover a whole complicated area, and let you research, discuss and solve problems. 

Why are they so powerful?? If you remember the term for each abstraction, you can spot the signs of these big problems and **look up the details** when you need to go deeper. You join the solutions together like constructicons to make super killer solutions!

- paralellism (multiprocessing)
- concurrency
- threads
- hardware threads
- operating system
- security rings
- kernel
- kernel space
- user space

{{< /alert >}}lert

---
title: "Week 12: Benchmarking and analysis" 
linkTitle: "12: Benchmark"
weight: "120"
description: >
  Testing performance, interpreting the results..
---

## benchmarking

### What are you testing?
You have to know the subject to test it well. Where does it really start and end? What influences the outcome?

### How will you test it? 
  - Where in the cycle/flow? Are you timing what you think you’re timing?
  - What precision is needed? Is your timer precise enough?
  - is timer accurate/operational in the conditions?
1. 

## Expectations
  - what outcomes can you imagine? Do you think one is more likely? Can you imagine a scenario you’re wrong? You need _detailed reasons_ here based on technical knowledge of hardware, os, language. Only answer is study.

## Analysis

Benchmarking doesn't mean you have any idea what's actually going on. That takes work to test and prove.

### Known knowns

Things you know you know, for example the specs and capabilities of your hardware.

Assuming you've checked. If you don't know how fast your ram is, the number of cores in your cpu, how many instructions it can process per second per core, how many cuda cores your gpu has ( and their ipc ) how the heck can you interpret the results??

This is basic leg work. If you don't look it up, you're not doing benchmarking.

### Known unknowns

Things you know will influence the outcome, but not by what amount.

### Unknown unkowns

Things that can influence the results that you don't know exist/thought were irrelevant.

Don't throw out results because they're unexpected, and don't just assume your testing was wrong. Think on it. Think of ways to check the results, what could they imply?

## A3 Questions/progress

## Looking at Timer

How does it work? How would you do this timing yourself with the standard library?

What hidden factors are involved?
---
jupytext:
  formats: ipynb,md:myst
  main_language: python
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.2
kernelspec:
  display_name: ''
  name: ''
---

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(week7)=
# Interfacing to Analogue I/O with C

```{image} ../week3/pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

## Introduction
C is a high-levelled structured programming language which is often used for writing microcontroller applications. This section looks at how I/O operations are performed on analogue inputs.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} ../week3/pictures/contents_image.png
:alt: Decorative image used as a slide background
:width: 50%
```
### Topics discussed

In this section we will be looking at how we can read analogue signals into a microcontroller using an analogue to digital converter. The lecture starts by introducing analogue signals  and the fundamental principals of an ADC before moving to look at the ADC contained on the Atmel ATmega328 microcontroller, focussing on the key registers and how to use them. The section concludes with an example program for the Atmel ATmega328 microcontroller which reads the voltage from a potentiometer and turns on some LEDs based on the voltage.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Contents

* {ref}`wk7:sect1`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* {ref}`wk7:sect2`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* {ref}`wk7:sect3`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* {ref}`wk7:sect4`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk7:sect1)=
## What are analogue signals?

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk7:sect2)=
## ADC Components

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### ADC Architecture

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### SAR based ADC Architecture

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk7:sect3)=
## The Atmel ATmega328 Analog-digital-converter

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk7:sect4)=
## Analogue I/O Example program

+++ {"editable": true, "slideshow": {"slide_type": ""}}

## Summary

+++ {"editable": true, "slideshow": {"slide_type": ""}}

## On Canvas

```{code-cell}
---
editable: true
slideshow:
  slide_type: ''
---

```

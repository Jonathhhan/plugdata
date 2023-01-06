---
title: pimp

description: Control phasor+imp

categories:
- object

pdcategory:

arguments:
- description: frequency in hertz
  type: float
  default: 0
- description: initial phase offset
  type: float
  default: 0

inlets:
  1st:
  - type: float
    description: frequency in hz
  2nd:
  - type: float
    description: phase sync (ressets internal phase)

outlets:
  1st:
  - type: float
    description: "phase" value from 0 to 127
  2nd:
  - type: bang
    description: output a bang at period transitions

flags:
  - name: -rate <float>
    description: rate period in ms (default 5, min 0.1)

methods:
  - type: rate <float>
    description: rate period in ms

draft: false
---

This is like the [pimp~] but operates in a control rate (with a maximum resolution of 1 ms).

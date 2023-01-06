---
title: resonant2~
description: Resonant filter with attack/decay time

categories:
 - object

pdcategory: DSP

arguments:
- type: float
  description: center frequency in herz
  default: 0
- type: float
  description: attack time in ms
  default: 0
- type: float
  description: decay time in ms
  default: 0

inlets:
  1st:
  - type: signal
    description: singal to be filtered or excite the resonator
  2nd:
  - type: float/signal
    description: central frequency in hertz
  3rd:
  - type: float/signal
    description: attack time in ms
  4th:
  - type: float/signal
    description: decay time in ms

outlets:
  1st:
  - type: signal
    description: resonator/filtered signal

  
methods:
- type: clear
    description: clears filter's memory
  
draft: false
---    

[resonant2~] is a resonator just like [resonant~], but you you can specify an attack time besides a decay time.
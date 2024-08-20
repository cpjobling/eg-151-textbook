#!/bin/bash
jupyter-book build eg_151 --builder latex
cd eg_151/_build/latex
make
cp eg-151-microcontrollers.pdf ../html 

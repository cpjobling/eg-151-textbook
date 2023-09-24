#!/bin/bash
jupyter-book build eg_151
jupyter-book build eg_151 --builder pdflatex
cp eg_151/_build/latex/eg-151-microcontrollers.pdf eg_151/_build/html
ghp-import --no-jekyll --push --no-history eg_151/_build/html 

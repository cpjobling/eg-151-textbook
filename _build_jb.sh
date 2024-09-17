#!/bin/bash
jupyter-book build eg_151
# jupyter-book build eg_151 --builder pdflatex
# rm eg_151/_build/html/eg-151-microcontrollers.pdf
#cp eg_151/_build/latex/eg-151-microcontrollers.pdf ~/OneDrive\ -\ Swansea\ University/3\ Resources/shared_documents

echo "update gtihub pages ... disabled"
#ghp-import --no-jekyll --push --no-history eg_151/_build/html 

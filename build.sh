#!/bin/bash
jupyter-book build eg_151
ghp-import --no-jekyll --push --no-history eg_151/_build/html 
jupyter-book build --builder pdflatex eg_151

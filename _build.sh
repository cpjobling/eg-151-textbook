#!/bin/bash

echo "Building website"
quarto render website --to html

echo "Building slides"
rm -rf slides/_slides
quarto render slides 
echo "Copying slides to website"
rsync -avzd slides/_slides/ website/_build/html/slides

echo "Building PDF"
rm -rf book/_book/*
quarto render book --to pdf
cp book/_book/EG-151-Microcontrollers-2024-2025.pdf website/_build/html


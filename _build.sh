#!/bin/bash

echo "Building PDF"
cd book
quarto render --to pdf
cd ..
cp book/_book/EG-151-Microcontrollers-2024-2025.pdf website/_build/html



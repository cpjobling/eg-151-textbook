#!/bin/bash

# Relink images
echo "Relinking images from lecture files"
rm pictures/*.{png,jpg}
ln -f ../website/lectures/pictures/* pictures
ln -f ../website/lectures/lecture01/pictures/* pictures 
ln -f ../website/lectures/lecture02/pictures/* pictures
#ln -f ../website/lectures/lecture03/pictures/* pictures

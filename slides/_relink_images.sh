#!/bin/bash

# Relink images
echo "Relinking images from lecture files"
rm pictures/*.{png,jpg}
ln -f ../website/lectures/pictures/* pictures
ln -f ../website/lectures/week01/pictures/* pictures 
ln -f ../website/lectures/data_representation/pictures/* pictures
ln -f ../website/lectures/week02/pictures/* pictures
ln -f ../website/lectures/week03/pictures/* pictures

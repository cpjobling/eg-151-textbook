#!/bin/bash

# Relink images
echo "Relinking images for book"
rm pictures/*.{gif,svg,png,jpg}
ln -f ../website/lectures/pictures/* pictures
ln -f ../website/lectures/week01/pictures/* pictures
ln -f ../website/lectures/data_representation/pictures/* pictures
ln -f ../website/lectures/week02/pictures/* pictures
ln -f ../website/lectures/week03/pictures/* pictures
ln -f ../website/lectures/week04/pictures/* pictures
ln -f ../website/lectures/week05/pictures/* pictures
ln -f ../website/lectures/week06/pictures/* pictures
ln -f ../website/lectures/week07/pictures/* pictures
ln -f ../website/lectures/week08/pictures/* pictures
ln -f ../website/lectures/week09/pictures/* pictures
ln -f ../website/appendix/pictures/* pictures
ln -f ../website/lab_intro/pictures/* pictures
ln -f ../website/labs/get_started/pictures/* pictures
ln -f ../website/labs/lab01/pictures/* pictures
ln -f ../website/labs/lab02/pictures/* pictures
ln -f ../website/labs/lab03/pictures/* pictures
ln -f ../website/labs/lab05/pictures/* pictures
ln -f ../website/projects/pictures/* pictures

cd ..#!/bin/bash
echo "Enter Directory"
read directory
cd $HOME/$directory
ls -l *.?

cd $HOME
cd $1
ls $2

echo No of users are `who|wc -l`
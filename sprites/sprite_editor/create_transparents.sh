#!/bin/sh

for dir in .
do

for file in $dir/*.JPG
do
echo Converting $file
len=$(expr length $file - 4)
file=$(expr substr $file 1 $len)
convert -sample 40% -verbose -type TrueColorMatte -transparent white $file.JPG $file.tga
convert -verbose $file.tga $file.png
convert -verbose -flop $file.tga $file-flip.png
echo
rm -f $file.tga
#ini=$(expr length $dir + 2)
#onlyf=$(expr substr $file $ini $len)
done  #file

done  #dir

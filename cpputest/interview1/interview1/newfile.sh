#!/bin/bash

newfilename=`tr '[A-Z]' '[a-z]' <<< $1` # small
newfilename='ltoj_'${newfilename// /_} # Replace the space with '_'

sed 's/$1/'$newfilename'/g' ltoj.cpp > $newfilename.cpp

newnamespace=`tr '[a-z]' '[A-Z]' <<< $newfilename` 
sed -i '' 's/$2/'$newnamespace'/g' $newfilename.cpp

d=`date '+%Y-%m-%d'`
sed -i '' 's/$d/'$d'/g' $newfilename.cpp

echo 'Create the new file: '$newfilename.cpp

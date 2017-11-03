#!/bin/bash
X=456
rev=0
while [ $X -gt 0 ]
do
  echo $X
  X=$((X+1))
  rev = $(($rev*10 + X%10))
  X=$((X/10))
done
echo rev

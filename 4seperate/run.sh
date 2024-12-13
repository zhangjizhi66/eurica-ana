#!/bin/bash
if [ ! -d "../SeperateData" ]; then
  mkdir ../SeperateData
fi

make seperate

z=$1
a=$2

run=1010
while [ $run -le 5138 ]
do
  if [ -f "../CorrectData/decay$run.root" ]; then
    ./seperate $run $z $a
  fi
  let "run++"
done



command="hadd -f ../SeperateData/decay$z""_$a.root"
command1="rm"

run1=1010
while [ $run1 -le 5138 ]
do
  if [ -f "../SeperateData/decay$z""_$a""_$run1.root" ]; then
    command=$command" ../SeperateData/decay$z""_$a""_$run1.root"
    command1=$command1" ../SeperateData/decay$z""_$a""_$run1.root"
  fi
  let "run1++"
done

$command
$command1
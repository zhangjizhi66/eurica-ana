#!/bin/bash
if [ ! -d "../CorrectData" ]; then
  mkdir ../CorrectData
fi

make correct

run=1010
while [ $run -le 5138 ]
do
  if [ -f "../DecayData/decay$run.root" ]; then
    ./correct $run
  fi
  let "run++"
done
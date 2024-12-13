#!/bin/bash
if [ ! -d "../CombineData" ]; then
  mkdir ../CombineData
fi

make combine

run=$1
while [ $run -le $2 ]
do
  if [ -f "../RawData/bigrips/bigrips_run$run.root" ]; then
    ./combine $run
  fi
  let "run++"
done
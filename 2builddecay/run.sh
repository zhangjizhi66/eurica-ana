#!/bin/bash
if [ ! -d "../DecayData" ]; then
  mkdir ../DecayData
fi

make builddecay

run=$1
while [ $run -le $2 ]
do
  if [ -f "../CombineData/combine$run.root" ]; then
    ./builddecay $run
  fi
  let "run++"
done
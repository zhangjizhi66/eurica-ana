#!/bin/bash

if [ ! -d "log" ]; then
  mkdir log
fi

nohup ./run.sh $1 $2 > log/run$1_$2.log 2>&1 &
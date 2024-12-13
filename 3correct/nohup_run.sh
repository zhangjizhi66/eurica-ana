#!/bin/bash

if [ ! -d "log" ]; then
  mkdir log
fi

nohup ./run.sh > log/run.log 2>&1 &
#!/bin/bash

python sleeper.py "hello world 1" &
pr1=$!
python sleeper.py "hello world 2" &
pr2=$!
echo "---------- Process[$pr1] and Process[$pr2] started... ----------"

kill -19 $pr1
echo "-------------------- SIGSTOP Process[$pr1] ----------------------"

echo "USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND"
ps ux | grep $pr1 | grep -v grep

kill -18 $pr1
echo "-------------------- SIGCONT Process[$pr1] ----------------------"

echo "USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND"
ps ux | grep $pr1 | grep -v grep

kill -15 $pr1 $pr2
echo "---------- Process[$pr1] and Process[$pr2] terminated! ---------"

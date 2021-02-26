#!/usr/local/bin/bash

mkfifo fifo0 fifo1
./prog > fifo0 < fifo1 &
python checker.py < fifo0 > fifo1

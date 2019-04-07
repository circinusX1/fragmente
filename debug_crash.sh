#!/bin/bash

# 
# make sure the program has symbols: CXX & CC FLAGS   +=  '-DDEBUG -g'

ulimit -S -c unlimited /path/to/binary/mybinary
sysctl -w kernel.core_pattern=/home/path/to/binary/dump

######################################################################
# after crash go to /home/path/to/binary/dump
# gdb -c dump-file-......
# (gdb)file /path/to/binary/mybinary
# (gdb) bt


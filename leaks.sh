#!/bin/sh
make clean
make
leaks -atExit -- ./pacman |grep LEAK:
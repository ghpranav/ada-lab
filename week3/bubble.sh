#!/bin/bash

set xrange [0:1000]
set yrange [0:500000]
set title "Bubble Sort"
set xlabel "Input Size"
set ylabel "Basic Operation Count"
set style data lines
plot "bubble_bc.txt" title "Best Case" smooth unique, "bubble_wc.txt" title "Worst Case" smooth unique

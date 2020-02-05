#!/bin/bash

set xrange [0:1000]
set yrange [0:500000]
set title "Selection Sort"
set xlabel "Input Size"
set ylabel "Basic Operation Count"
set style data lines
plot "selection.txt" title "Number of Comparisons" smooth unique

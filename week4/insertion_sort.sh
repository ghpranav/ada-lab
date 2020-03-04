#!/bin/bash

set xrange [0:500]
set yrange [0:130000]
set title "Insertion Sort"
set xlabel "Input Size"
set ylabel "Basic Operation Count"
set style data lines
plot "ins_sort_bc.txt" title "Best Case" smooth unique, "ins_sort_wc.txt" title "Worst Case" smooth unique

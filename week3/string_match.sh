#!/bin/bash

set xrange [0:500]
set yrange [0:300000]
set title "String Matching"
set xlabel "Input Size"
set ylabel "Basic Operation Count"
set style data lines
plot "string_match_bc.txt" title "Best Case" smooth unique, "string_match_wc.txt" title "Worst Case" smooth unique

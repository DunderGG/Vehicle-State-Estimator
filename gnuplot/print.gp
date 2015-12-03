set xlabel "X"
set ylabel "Y"
set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"
set autoscale
set terminal postscript portrait enhanced mono dashed lw 1 'Helvetica' 
12
set style line 1 lt 1 lw 3 pt 3 linecolor rgb "red"
set output 'groundTruth.eps'
plot 'gps-2column-parsed.txt' using 2:1 w points title "Kalman Filter 
Ground Truth"

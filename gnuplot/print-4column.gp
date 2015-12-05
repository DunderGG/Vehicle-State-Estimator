# execute using 
# gnuplot print.gp

set xlabel "X"
set ylabel "Y"
set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"
set autoscale
set terminal postscript portrait enhanced color dashed lw 1 'Helvetica' 12
set style line 1 lt 1 lw 3 pt 3 linecolor rgb "red"
set output 'xxx.eps'
plot for [i=1:2] "xxx.txt" u (column(2*i)):(column(2*i-1)) w lp

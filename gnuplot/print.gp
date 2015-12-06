# execute using 
# gnuplot print.gp

set xlabel "X"
set ylabel "Y"
set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"
set autoscale
set terminal postscript portrait enhanced color dashed lw 1 'Helvetica' 12
set style line 1 lt 1 lw 3 pt 3 linecolor rgb "red"
set output 'vehiclePlotData.eps'

# plot 4 lines
plot for [i=1:4] "mauroCar.dat" u (column(3*(i-1)+1)):(column(3*(i-1)+2)) w lp


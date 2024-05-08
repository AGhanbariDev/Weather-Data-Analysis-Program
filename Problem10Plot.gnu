#makes the xdata in time format	
set xdata time
set timefmt "%Y-%m-%d"

#set to years
set format x "%Y"

#sets the scale and proper amount of tic marks
set xrange ["2000-01-01":"2015-01-01"]
set xtics "2000-01-01", 31536000, "2016-12-01"
set mxtic 12
unset key
set ytics nomirror

#adds labels
set xlabel "Years (by Month)"
set ylabel "Temperature (°C)"
set title "Average Monthly Temperatures (2000-2015)"

#plots data with errorbars
plot "prob10.dat" using 1:2:3 with errorbars, \
     "prob10.dat" using 1:2 with lp 
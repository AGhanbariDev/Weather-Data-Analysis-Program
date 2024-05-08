set terminal svg enhanced size 1250,750

#set style to histogram and multiplot (1 by 3)
set style data histogram
set multiplot layout 1,3 columns

#labels for the plots
set xlabel 'Centuries'
set ylabel 'Temperature (°C)'
#overarching title
set label 1 "Temperature Comparisons by Century" at screen 0.513, 0.99 center

#change scaling to be more precise
set ytics 1
set grid ytics
#bar widths
set boxwidth 0.75
#linestyle settings
set style line 1 linecolor rgb 'pink'
set style line 2 linecolor rgb 'orange'
set style line 3 linecolor rgb 'brown'

set style fill pattern 9

#average temperature plot
set title 'Average Temperatures'
set yrange [0:15]
#resize plots to better fit
set origin 0, 0
set size 0.3, 0.97
#plot graphs with row settings to specify more settings
plot 'prob9.dat' every ::0::0 using 1:2:xtic(1) title "19th century" with boxes ls 1, \
	 'prob9.dat' every ::1::1 using 1:2:xtic(1) title "20th century" with boxes ls 2, \
	 'prob9.dat' every ::2::2 using 1:2:xtic(1) title "21st century" with boxes ls 3, \
     
#max temperature plot
set title 'Maximum Temperatures'
set yrange [0:20]
#resize plots to better fit
set origin 0.35, 0
set size 0.3, 0.97
#plot graphs with row settings to specify more settings
plot 'prob9.dat' every ::0::0 using 1:3:xtic(1) title "19th century" with boxes ls 1, \
	 'prob9.dat' every ::1::1 using 1:3:xtic(1) title "20th century" with boxes ls 2, \
	 'prob9.dat' every ::2::2 using 1:3:xtic(1) title "21st century" with boxes ls 3, \
     
#min temperature plot    
set title 'Minimum Temperatures'
set yrange [0:10]
#resize plots to better fit
set origin 0.7, 0
set size 0.3, 0.97
#plot graphs with row settings to specify more settings
plot 'prob9.dat' every ::0::0 using 1:4:xtic(1) title "19th century" with boxes ls 1, \
	 'prob9.dat' every ::1::1 using 1:4:xtic(1) title "20th century" with boxes ls 2, \
	 'prob9.dat' every ::2::2 using 1:4:xtic(1) title "21st century" with boxes ls 3, \
     
     
     
     
     
     
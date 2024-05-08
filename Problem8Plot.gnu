# Setting Labels on 'x' and 'y' axis
set xlabel 'Years'
set ylabel 'Yearly Averages'

# Setting Main Title
set title 'Problem 8 - LandAverageTemperature, LandMaxTemperature, and LandMinTemperature over time'

# Changing the spaces between numbers on the x axis
set xtics 25

# Plotting data from the file with different colours and the weight of the second column in the file bieng thicker
plot 'problem8_data.dat' using 1:2 lw 5 linecolor 0 linetype 7 with lines title 'Temperature Average', '' using 1:3 linecolor 1 linetype 7 with lines title 'Land Max Temperature', '' using 1:4 linetype 7 linecolor 2 with lines title 'Land Min Temperature'
set terminal svg enhanced size 800,480 #Set a certain size for the plot to be displayed
set title 'Yearly Temperatures for Years 1760-2015' #Adds a title to the plot
set xlabel 'Years' #Labels x-axis
set ylabel 'Average Temps' #Labels y-axis
set xrange[1750:2020] #Allows the graph to be plotted from 1750 to 2020
set yrange[6.5:10] #Allows the graph to be plotted from 6.5 to 10
set xtics 20 #Increases the xtics by increments of 20
plot 'problem1.txt' title 'Temperature' with l lc "blue" #Plot the graph, add a legend, and a blue line


     
     
     
     
     
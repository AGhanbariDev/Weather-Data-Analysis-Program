set terminal svg enhanced size 850,480 #Set a certain size for the plot to be displayed
set title 'Yearly Temperatures for 19th and 20th centuries' #Adds a title
set xlabel 'Years' #Adds a x-axis title
set ylabel 'Average Temps' #Adds a y-axis title
set yrange[6.5:10] #Allows the graph to be plotted from 6.5 to 10
set xtics 10  #Increases the xtics by increments of 10
plot "problem7_data.dat" using 1:2 with lines title "19th Century Temperatures", \
 "problem7_data.dat" using 1:3 with lines title "20th Century Temperatures" #Plot two lines on the graph using different temperatures for each line and add a legend corresponding to each line
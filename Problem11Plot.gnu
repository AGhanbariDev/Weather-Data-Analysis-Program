set terminal svg enhanced size 800,480 #Set a certain size for the plot to be displayed
set title 'Land and Ocean Average Temperature for Years 1850-2015'#Adds a title
set xlabel 'Years' #Adds a x-axis title
set ylabel 'Average Temps' #Adds a y-axis title
set xtics 20 #Increases the xtics by increments of 20
plot 'problem11_data.dat' using 1:2 title 'Land Average Temperature' with l lc "blue", \
'problem11_data.dat' using 1:3 title 'Land and Ocean Average Temperature' with l lc "red" #Plot two lines on the graph using different temperatures, adds a legend corresponding to each line and make one line red and the other blue

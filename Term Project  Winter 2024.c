#include <stdio.h>
#include <unistd.h> // To change Directory
#include <stdlib.h>
#include <string.h>

/* Function created for Problem 4*/
char *monthConvert(int month) { 
	switch (month){
		case 1:
			return "January";
        	case 2:
            	return "February";
        	case 3:
            	return "March";
        	case 4:
            	return "April";
        	case 5:
            	return "May";
        	case 6:
            	return "June";
        	case 7:
            	return "July";
        	case 8:
            	return "August";
        	case 9:
            	return "September";
        	case 10:
            	return "October";
        	case 11:
            	return "November";
        	case 12:
            	return "December";
        	default:
			return "";
    }
}


int main(void) {

    /* Problem 1 - Code & File Type Conversion */
    printf("Problem 1 - Data:\n");
    FILE *in, *out, *fp;
    char *source_file = "GlobalTemperatures.csv", *destination_file = "GlobalTemperatures.txt", line[250], date[11], ch, symb = 248; // 248 for degree symbol 
    int year, month;
    double temperature, average, sum;
    
    in = fopen(source_file, "r");
    out = fopen(destination_file, "w+"); // Opens to read and write
    fp = fopen("problem1.txt", "w");
    
    // Error message if unable to access source file
    if (in == NULL) {
        printf("Access to '%s' unsuccessful.\n", source_file);
        exit(1);
    }
	
	// Copy-Pasting data from source file to destination file 
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }
    fclose(in);

	// Resetting file pointer
    rewind(out);

     while (fgets(line, sizeof(line), out)) {
        
        // Divide the line to extract date and temperature
        if (sscanf(line, "%10[^,],%lf", date, &temperature) == 2) {
            
            // Extract the year from the date
            sscanf(date, "%d-%d", &year, &month);
            if (month == 1) { // A new year started
                if (year > 1760 && year <= 2015) {
					average = sum / 12; // Calculate average for the previous year
					printf("Year: %d, Average Temperature: %.3lf%cC\n", year - 1, average, symb);
					fprintf(fp, "%d %.3lf\n", year - 1, average);
                }
                sum = 0; // Reset sum to calculate the next year 
            }
            sum += temperature; // Calculate the sum for the current year
        }
    }

    // Print the average temperature for the last year (2015)
    average = sum / 12;
    printf("Year: 2015, Average Temperature: %.3lf%cC\n", average, symb);
    fprintf(fp, "2015 %.3lf\n", average);
    
    fclose(out);
	fclose(fp);
	


	/* Problem 2 - Code */
    printf("\nProblem 2 - Data:\n");
    double average_18th, sum_18th, average_19th, sum_19th, average_20th, sum_20th, average_21st, sum_21st;
	
	// Accessing file
	out = fopen("GlobalTemperatures.txt", "r");
	
	// Error message if unable to access source file
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
        exit(1);
    }
	
	// Resetting file pointer & variables
    rewind(out);
    temperature = 0;

	// Loop that gathers sum of each century
	while (fgets(line, sizeof(line), out)){
        
        sscanf(line, "%10[^,],%lf", date, &temperature); // Extract date "YYYY-MM-DD" and temperature
        sscanf(date, "%d", &year); // Extract year from date
        
        if (year >= 1760 && year <= 1799) {
            sum_18th += temperature; // Calculate the sum for the current century
        }
        
        else if (year >= 1800 && year <= 1899) {
            sum_19th += temperature; // Calculate the sum for the current year
        }
        
        else if (year >= 1900 && year <= 1999) {
            sum_20th += temperature; // Calculate the sum for the current year
        }
        
        else if (year >= 2000 && year <= 2015) {
            sum_21st += temperature; // Calculate the sum for the current year
        }
    }
    
    // Displaying data
    average_18th = sum_18th / ((1799 - 1760 + 1) * 12); // Calculate average for the century
    printf("Average Temperature for 18th Century: %.3lf%cC\n", average_18th, symb);
    
    average_19th = sum_19th / ((1899 - 1800 + 1) * 12); // Calculate average for the century
    printf("Average Temperature for 19th Century: %.3lf%cC\n", average_19th, symb);
    
    average_20th = sum_20th / ((1999 - 1900 + 1) * 12); // Calculate average for the century
    printf("Average Temperature for 20th Century: %.3lf%cC\n", average_20th, symb);
    
    average_21st = sum_21st / ((2015 - 2000 + 1) * 12); // Calculate average for the century
    printf("Average Temperature for 21st Century: %.3lf%cC\n", average_21st, symb);
    
	fclose(out);

    /* Problem 3 - Code */
    printf("\nProblem 3 - Data:\n");
    double total_years, jan_sum, feb_sum, mar_sum, apr_sum, may_sum, jun_sum, jul_sum, aug_sum, sep_sum, oct_sum, nov_sum, dec_sum;
    
    out = fopen("GlobalTemperatures.txt", "r"); // Opens to read and write
    
    // Error message if unable to access source file
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
        exit(1);
    }

	// Resetting file pointer & variables
    rewind(out);
    temperature = 0;

    while (fgets(line, sizeof(line), out)) {
        
        // Divide the line to extract date and temperature
        if (sscanf(line, "%10[^,],%lf", date, &temperature) == 2) {
            
            // Extract the year from the date
            sscanf(date, "%d-%d", &year, &month);
            
            if (year >= 1900 && year <= 2015) {
                if (month == 1) { // January 
					jan_sum += temperature;
                } else if (month == 2) { // February
                    feb_sum += temperature;
                } else if (month == 3) {
                    mar_sum += temperature;
                } else if (month == 4) {
                    apr_sum += temperature;
                } else if (month == 5) {
                    may_sum += temperature;
                } else if (month == 6) {
                    jun_sum += temperature;
                } else if (month == 7) {
                    jul_sum += temperature;
                } else if (month == 8) {
                    aug_sum += temperature;
                } else if (month == 9) {
                    sep_sum += temperature;
                } else if (month == 10) {
                    oct_sum += temperature;
                } else if (month == 11) {
                    nov_sum += temperature;
                } else if (month == 12) {
                    dec_sum += temperature;
                }
                
            }
        }
    }

    total_years = (2015-1900+1);

    printf("The January Average is: %.3lf%cC\n", jan_sum/total_years, symb);
    printf("The February Average is: %.3lf%cC\n", feb_sum/total_years, symb);
    printf("The March Average is: %.3lf%cC\n", mar_sum/total_years, symb);
    printf("The April Average is: %.3lf%cC\n", apr_sum/total_years, symb);
    printf("The May Average is: %.3lf%cC\n", may_sum/total_years, symb);
    printf("The June Average is: %.3lf%cC\n", jun_sum/total_years, symb);
    printf("The July Average is: %.3lf%cC\n", jul_sum/total_years, symb);
    printf("The August Average is: %.3lf%cC\n", aug_sum/total_years, symb);
    printf("The September Average is: %.3lf%cC\n", sep_sum/total_years, symb);
    printf("The October Average is: %.3lf%cC\n", oct_sum/total_years, symb);
    printf("The November Average is: %.3lf%cC\n", nov_sum/total_years, symb);
    printf("The December Average is: %.3lf%cC\n", dec_sum/total_years, symb);

    fclose(out);
	

    /* Problem 4 - Code */
    printf("\nProblem 4 - Data:\n");
	int hottestM, hottestY, coldestM, coldestY;
    double hottestT, coldestT;
	
	// Opens file and checks if successful 
	out = fopen("GlobalTemperatures.txt", "r");
	
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' was unsuccessful.\n");
      	exit(1);
    }
	
    // Resseting pointer and variables
    rewind(out);
    temperature = 0;
    
    // Reads first line of date and temperature data
    sscanf(line, "%10[^,],%lf", date, &temperature); 
    sscanf(date, "%d-%d", &year, &month); 
    
    // Sets hottest/coldest info to the first line data
    hottestM = month;
    hottestY = year;
    hottestT = temperature; 
    coldestT = temperature;
    coldestM = month;
    coldestY = year;
        
	while (fgets(line, sizeof(line), out)){
		
      	// Reads date and temperature data
      	sscanf(line, "%10[^,],%lf", date, &temperature); 
      	sscanf(date, "%d-%d", &year, &month); 
        
      	// Checks if the current values are hotter/colder and reassigns accordingly
   		if (temperature >= hottestT) {
			hottestT = temperature;
			hottestY = year;
			hottestM = month;
		}
		if (temperature <= coldestT) {
			coldestT = temperature;
			coldestY = year;
			coldestM = month;
		}
    }	

	// Uses the monthConvert function to change the month value to its name
	char* hotMonth = monthConvert(hottestM);
	char* coldMonth = monthConvert(coldestM);
	
	// Prints the obtained hottest and coldest date and their respective temperatures
    printf("Hottest Month was on %s %d with an average Temp of: %.3lf%cC\n", hotMonth, hottestY, hottestT, symb);
    printf("Coldest Month was on %s %d with an average Temp of: %.3lf%cC\n", coldMonth, coldestY, coldestT, symb);

	fclose(out);

    /* Problem 5 - Code */
    printf("\nProblem 5 - Data:\n");
    FILE *fptr;

    // Open a file in read mode
    fptr = fopen("problem1.txt", "r");

    // Store the content of the file
    char myString[500];

    // Check if the file was opened successfully
    if (fptr == NULL)
    {
        printf("Error opening the file.\n");
        return 1; // Exit the program with an error
    }

    fgets(myString, sizeof(myString), fptr);

    // Create a map to store the values
    float value[500];
    int yr[500];
    int index = 0;

    // First token
    char *token = strtok(myString, " ");
    yr[index] = atoi(token);
    token = strtok(NULL, "");
    value[index] = atof(token);
    index++;

    while (fgets(myString, sizeof(myString), fptr) != NULL)
    {
        // Tokenize the string and store the values in the map
        token = strtok(myString, " ");
        yr[index] = atoi(token);
        token = strtok(NULL, "");
        value[index] = atof(token);
        index++;

    }

    // Finding min and max of the value array
    float min = value[0];
    float max = value[0];
    int minIndex = 0;
    int maxIndex = 0;
    for(int i = 1; i < index; i++){
        if(value[i] < min){
            min = value[i];
            minIndex = i;
        }
        if(value[i] > max){
            max = value[i];
            maxIndex = i;
        }
    }

    // Print the min and max values
    printf("The coldest year: %d \n", yr[minIndex]);
    printf("The hottest year: %d \n", yr[maxIndex]);

    // Close the file
    fclose(fptr);

    /* Problem 7 - Code */
    // Varaible declarations
    FILE *dataF;
    int years[1000];
    double temp[1000];
 
	// Open the file and read it
    // Open the file and write to it
    fp = fopen("problem1.txt", "r");
    dataF = fopen("problem7_data.dat", "w");

    rewind(fp);

	// Tries to open the file and if it cannot be opened then an error will show up
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    // Scans for all the years and temperatures and stores them in an array
    fprintf(dataF,"Years\t19th\t20th\n");
    for (int i = 0; i < 500; i++){
        fscanf(fp, "%d %lf", &years[i], &temp[i]);
    }
    
    // Takes 19th and 20th century temperatures and outputs it
    for (int i = 0; i < 200; i++){
        if (years[i] >= 1799 && years[i] <= 1899) {
            fprintf(dataF, "%d %lf %lf\n", i-39, temp[i], temp[i + 100]);
        } 
    }
    
    /* Problem 8 - Code */
    double land_max, land_min, uncertainty1, uncertainty2, average_temp, sum_temp, average_min, sum_min, average_max, sum_max;

	// Accessing files
	out = fopen("GlobalTemperatures.txt", "r");
	in = fopen("problem8_data.dat", "w");
	
	// Error message if unable to access source file
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
        exit(1);
    }
	
	// Resetting file pointer
    rewind(out);

	while (fgets(line, sizeof(line), out)){
        
        // Placeholders uncertainty 1 & 2 required to avoid using length modifier with assignment suppression
        sscanf(line, "%10[^,],%lf,%lf,%lf,%lf,%lf", date, &temperature, &uncertainty1, &land_max, &uncertainty2, &land_min); // Extract date "YYYY-MM-DD", temperature, land maximum temperature, and minimum temperature
        sscanf(date, "%d-%d", &year, &month); // Extract year and month from date
        
        if (month == 1) { // A new year started
                if (year > 1850 && year <= 2015) {
					average_temp = sum_temp / 12; // Calculate average for the previous year
					average_max = sum_max / 12;
					average_min = sum_min / 12;
					fprintf(in, "%d %.3lf %.3lf %.3lf\n", year - 1, average_temp, average_max, average_min);
                }
                sum_temp = 0; // Reset sum to calculate the next year 
                sum_max = 0;
                sum_min = 0;
            }
        sum_temp += temperature; // Calculate the sum for the current year
        sum_max += land_max;
        sum_min += land_min;
        }
    

    // Print the average temperature for the last year (2015)
    average_temp = sum_temp / 12;
	average_max = sum_max / 12;
	average_min = sum_min / 12;
    fprintf(in, "2015 %.3lf %.3lf %.3lf\n", average_temp, average_max, average_min);
    
	fclose(out);
    fclose(in);

    /* Problem 9 - Code */

	double avgTemp, avgUnc, maxTemp, maxUnc, minTemp;
	int count = 0;
	

	out = fopen("GlobalTemperatures.txt", "r");
    in = fopen("prob9.dat", "w");
    
    if (out == NULL) {
        printf("Access to Data unsuccessful.\n");
        exit(1);
    }

    // Resetting Variables and File Pointers
	rewind(out);
    year = 0;
    month = 0;

	double centuryAvg = 0, centuryMin = 0, centuryMax = 0;
	
	while (fgets(line, sizeof(line), out)){
		
        // checks if its the beginning of a century and resets the values
		if ((year == 1849 && month == 12) || (year == 1999 && month == 12) || (year == 1899 && month == 12)){
			count = 1;
			centuryAvg = 0;
			centuryMin = 0;
			centuryMax = 0;
		}
			
        // reads date and temperature data
        sscanf(line, "%10[^,],%lf,%lf,%lf,%lf,%lf", date, &avgTemp, &avgUnc, &maxTemp, &maxUnc, &minTemp); 
        
        // gets the year and month from the date string
        sscanf(date, "%d-%d", &year, &month); 
        
        // totals up the values
        centuryAvg += avgTemp;
        centuryMin += minTemp;
        centuryMax += maxTemp;
        
        // checks if its the end of a century then prints the values
        if((year == 1899 && month == 12) || (year == 1999 && month == 12) || (year == 2015 && month == 12)) {
			// averages the values
			centuryAvg = centuryAvg/count;
	        centuryMin = centuryMin/count;
			centuryMax = centuryMax/count;
			if (year == 1899)
				fprintf(in, "19th\t");
			else if (year == 1999)
				fprintf(in, "20th\t");
			else if (year == 2015)
				fprintf(in, "21st\t");
			fprintf(in, "%lf\t%lf\t%lf\n", centuryAvg, centuryMax, centuryMin);
		}
		count++;
	}	
	
	fclose(in);
	fclose(out);


    /* Problem 10 - Code */
    double uncertainty;

    out = fopen("GlobalTemperatures.txt", "r");
    in = fopen("prob10.dat", "w");
    
    if (out == NULL) {
        printf("Access to Data unsuccessful.\n");
        exit(1);
    }

	rewind(out);

	while (fgets(line, sizeof(line), out)){
		
        // Reads date and temperature data
        sscanf(line, "%10[^,],%lf,%lf", date, &temperature, &uncertainty); 
        sscanf(date, "%d", &year); 
        // Checks if the year is between 2000 and 2015
        if (year >= 2000 && year <= 2014) {
			fprintf(in, "%s\t%lf\t%lf\n", date, temperature, uncertainty);
		}
	}	
	fclose(in);
	fclose(out);

    /* Problem 11 - Code */

    double avgLandOceanTemp, avgLandOceanUnc, sumOcean, finalLandOceanAvg, land_minUnc;

    out = fopen("GlobalTemperatures.txt", "r");
    in = fopen("problem11_data.dat", "w");

    // Error message if unable to access source file
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
        exit(1);
    }

    // Resetting file pointer
    rewind(out);

    fprintf(in, "#Year AverageLandTemp AverageLandOceanTemp\n");
    
    while (fgets(line, sizeof(line), out)) {

        // Placeholders uncertainty 1 & 2 required to avoid using length modifier
        // with assignment suppression
        // Extracts all the values within the csv file
        sscanf(line, "%10[^,],%lf,%lf,%lf,%lf,%lf,%lf,%lf, %lf", date, &temperature, &uncertainty1, &land_max, &uncertainty2, &land_min, &land_minUnc, &avgLandOceanTemp, &avgLandOceanUnc); 
        sscanf(date, "%d-%d", &year, &month); // Extract year and month from date
        if (month == 1) {                     // A new year started
            if (year > 1850 && year <= 2015) {
                average = sum / 12;
                finalLandOceanAvg = sumOcean / 12;
                fprintf(in, "%d %.3lf %.3lf\n", year - 1, average, finalLandOceanAvg);
            }
        // Reset sum values
        sum = 0;
        sumOcean = 0;
        }
        // Add the temperatures to the sum
        sumOcean += avgLandOceanTemp;
        sum += temperature;
    }

    // Print the average temperature for the last year (2015)
    finalLandOceanAvg = sumOcean / 12;
    average = sum / 12;
    fprintf(in, "2015 %.3lf %.3lf\n", average, finalLandOceanAvg);

    // Close the files
    fclose(out);
    fclose(in);

	return(0);
}

#include "../inc/Job.h"

// Default Constructor
analysis::analysis() : average(0), median(0), mean(0) {}

// Overloaded Constructor
//analysis::analysis(const float& in_average, const float& in_median, const float& in_mode) : average(in_average), median(in_median), mode(in_mode) {}

// get the average
float analysis::get_average() const {
    return average;    
}

// get the median
float analysis::get_median() const {
    return median;
}

// get the median
float analysis::get_median() const {
    return mode;
}


// set average 
void analysis::set_average(const float data[][], int rows) {
	float sum;
	//int rows =  sizeof data / sizeof data[0]; 

	for(int i = 0; i < rows; i++){
		sum += data[i][1];
	}
	average = sum / rows;	
}

// set median
void analysis::set_median(const float data[][], int rows) {
	float temp;
	
	//int rows =  sizeof data / sizeof data[0]; 
	float data1[rows];
	
	for(int i = 0; i < rows; i++){
		data1 = data[i][1];
	}
		
	for(int i=0;i<rows;i++){		
		for(int j=i+1;j<n;j++){
			if(data1[i]>data1[j]){
				temp  = data1[i];
				data1[i]=data1[j];
				data1[j] = temp;
			}
		}
	}
	
	int x = rows/2;
	median = data1[x];
}

void analysis::set_mode(const float data[][], int rows) {
    float temp;
	
	//int rows =  sizeof data / sizeof data[0]; 
	float data1[rows];
	
	for(int i = 0; i < rows; i++){
		data1 = data[i][1];
	}
		
	for(int i=0;i<rows;i++){		
		for(int j=i+1;j<n;j++){
			if(data1[i]>data1[j]){
				temp  = data1[i];
				data1[i]=data1[j];
				data1[j] = temp;
			}
		}
	}
	
	int number = data1[0];
	int mod = number;
	int count = 1;
	int countMode = 1;
i
	for (int i = 1; i < rows; i++){
    	if (data1[i] == number) { // count occurrences of the current number
         ++count;
      	}
      	else{ // now this is a different number
        	if (count > countMode) {
                  countMode = count; // mode is the biggest ocurrences
                  mod = number;
            }
           count = 1; // reset count for the new number
           number = data1[i];
  		}
	}
	mode = mod;
}



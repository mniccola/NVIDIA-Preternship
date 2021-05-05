#include "../inc/analysis.h"
#include <iterator>

// calculates the average memory of a list of Jobs
double calc_avg_mem(const std::forward_list<Job>& the_list) {
    double count = 0;
    double sum = 0;
    for(auto i = the_list.begin(); i != the_list.end(); i++) {
        sum += i->get_memory();
        count += 1;
    }
    return sum / count;
}

// finds the median of a job list
double calc_med_mem(const std::forward_list<Job>& the_list) {

    std::forward_list<Job> temp_list = the_list;
    temp_list.sort();
    long int length = std::distance(temp_list.begin(), temp_list.end());
    long int mid = length / 2 - 1;
    std::forward_list<Job>::iterator curr = temp_list.begin();
    long int index = 0;

    if((length % 2) == 0) {
        //incrememnt iterator to middle
        while(index < mid) {
            curr++;
            index++;
        }
        // if the list has an even number of elements return avg of middle two
        return ((curr++)->get_memory() + (curr)->get_memory()) / 2;
    } else {
        //incrememnt iterator to middle
        while(index < mid) {
            curr++;
            index++;
        }
        // list has odd number of elements so return middle one;
        curr++;
        return curr->get_memory();
    }
}


double calc_stdev_mem(const std::forward_list<Job>& the_list) {
    double first_mean = calc_avg_mem(the_list);
    double sum = 0;
    double count = 0;

    for(auto i = the_list.begin(); i != the_list.end(); i++) {
        sum += pow((i->get_memory() - first_mean), 2);
        count+= 1;
    }

    return sqrt(sum / count);
}






// set average
// void analysis::set_average(const float data[][], int rows) {
// 	float sum;
// 	//int rows =  sizeof data / sizeof data[0];
//
// 	for(int i = 0; i < rows; i++){
// 		sum += data[i][1];
// 	}
// 	average = sum / rows;
// }
//
// // set median
// void analysis::set_median(const float data[][], int rows) {
// 	float temp;
//
// 	//int rows =  sizeof data / sizeof data[0];
// 	float data1[rows];
//
// 	for(int i = 0; i < rows; i++){
// 		data1 = data[i][1];
// 	}
//
// 	for(int i=0;i<rows;i++){
// 		for(int j=i+1;j<n;j++){
// 			if(data1[i]>data1[j]){
// 				temp  = data1[i];
// 				data1[i]=data1[j];
// 				data1[j] = temp;
// 			}
// 		}
// 	}
//
// 	int x = rows/2;
// 	median = data1[x];
// }
//
// void analysis::set_mode(const float data[][], int rows) {
//     float temp;
//
// 	//int rows =  sizeof data / sizeof data[0];
// 	float data1[rows];
//
// 	for(int i = 0; i < rows; i++){
// 		data1 = data[i][1];
// 	}
//
// 	for(int i=0;i<rows;i++){
// 		for(int j=i+1;j<n;j++){
// 			if(data1[i]>data1[j]){
// 				temp  = data1[i];
// 				data1[i]=data1[j];
// 				data1[j] = temp;
// 			}
// 		}
// 	}
//
// 	int number = data1[0];
// 	int mod = number;
// 	int count = 1;
// 	int countMode = 1;
// i
// 	for (int i = 1; i < rows; i++){
//     	if (data1[i] == number) { // count occurrences of the current number
//          ++count;
//       	}
//       	else{ // now this is a different number
//         	if (count > countMode) {
//                   countMode = count; // mode is the biggest ocurrences
//                   mod = number;
//             }
//            count = 1; // reset count for the new number
//            number = data1[i];
//   		}
// 	}
// 	mode = mod;
// }

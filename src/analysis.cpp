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

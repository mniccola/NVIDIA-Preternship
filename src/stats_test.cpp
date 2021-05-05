#include <iostream>
#include "../inc/Job.h"
#include "../inc/analysis.h"
#include <forward_list>

int main() {

    std::forward_list<Job> Even_List;
    std::forward_list<Job> Odd_List;
    std::forward_list<Job> dist_List;

    for(int i = 1; i < 11; i++) {
        Job j(0, (double)i);
        Even_List.push_front(j);
    }

    for(int i = 1; i < 10; i++) {
        Job j(0, (double)i);
        Odd_List.push_front(j);
    }

    double avg = calc_avg_mem(Even_List);
    double med = calc_med_mem(Even_List);
    double stdev = calc_stdev_mem(Even_List);

    std::cout <<"Average of even list: " << avg << std::endl;
    std::cout <<"Median of even list: " << med << std::endl;
    std::cout <<"STDEV of even list: " << stdev << std::endl;

    avg = calc_avg_mem(Odd_List);
    med = calc_med_mem(Odd_List);

    std::cout <<"Average of odd list: " << avg << std::endl;
    std::cout <<"Median of odd list: " << med << std::endl;

    for(int i = 1; i < 10; i++) {
        Job j(0, (double)i*i);
        dist_List.push_front(j);
    }

    avg = calc_avg_mem(dist_List);
    med = calc_med_mem(dist_List);
    stdev = calc_stdev_mem(dist_List);

    std::cout <<"Average of distributed list: " << avg << std::endl;
    std::cout <<"Median of distributed list: " << med << std::endl;
    std::cout <<"STDEV of distributed list: " << stdev << std::endl;

    return 0;
}

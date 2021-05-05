#include <iostream>
#include <cmath>
#include "Job.h"
#include <forward_list>


double calc_avg_mem(const std::forward_list<Job>& the_list);

double calc_med_mem(const std::forward_list<Job>& the_list);

double calc_stdev_mem(const std::forward_list<Job>& the_list);

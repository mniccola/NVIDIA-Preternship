#include "../inc/Job.h"

// Default Constructor
Job::Job() : time(0), memory(0) {}

// Overloaded Constructor
Job::Job(const float& in_time, const float& in_memory) : time(in_time), memory(in_memory) {}

// get the compute time used by a Job
float Job::get_time() const {
    return time;    
}

// get the memory used by the Job
float Job::get_memory() const {
    return memory;
}

// get set the time used by the Job
void Job::set_time(const float& in_time) {
    time = in_time;
}

// set the memory used by the Job
void Job::set_memory(const float& in_memory) {
    memory = in_memory;
}

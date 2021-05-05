#include "../inc/Job.h"

// Default Constructor
Job::Job() : time(0), memory(0) {}

// Overloaded Constructor
Job::Job(const double& in_time, const double& in_memory) : time(in_time), memory(in_memory) {}

// get the compute time used by a Job
double Job::get_time() const {
    return time;
}

// get the memory used by the Job
double Job::get_memory() const {
    return memory;
}

// get set the time used by the Job

void Job::set_time(const double& in_time) {
    time = in_time;
}

// set the memory used by the Job

void Job::set_memory(const double& in_memory) {
    memory = in_memory;
}

bool Job::operator<(const Job& rhs) const {
    return memory < rhs.memory;
}

bool Job::operator>(const Job& rhs) const {
    return memory > rhs.memory;
}

std::ostream& operator<<(std::ostream& out, const Job& J) {
    out << std::setprecision(5) << std::setw(5) <<  "Memory: " << J.memory << " Time: " << std::setw(6) << std::setprecision(5) <<  J.time;
    return out;
}

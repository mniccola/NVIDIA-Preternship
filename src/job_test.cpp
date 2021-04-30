#include "../inc/Job.h"
#include <iostream>

int main() {

    //uninitialized obj
    Job J1;

    // should print out 0s here
    std::cout << "Uninitialized Job Object" << std::endl;
    std::cout << "Job 1 memory: " << J1.get_memory() << std::endl;
    std::cout << "Job 1 time  : " << J1.get_time() << std::endl;

    J1.set_memory(3);
    J1.set_time(3);



    std::cout << "Set vals using set_memory() & set_time()" << std::endl;
    std::cout << "Job 1 memory: " << J1.get_memory() << std::endl;
    std::cout << "Job 1 time  : " << J1.get_time() << std::endl;


    Job J2(3, 5);

    std::cout << "Values initialized (overloaded constructor)" << std::endl;
    std::cout << "Job 2 memory: " << J2.get_memory() << std::endl;
    std::cout << "Job 2 time  : " << J2.get_time() << std::endl;

    return 0;
}

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <ctime>
// #include <cstdlib>
// #include <time.h>
#include "../inc/Job.h"
#include "../inc/mainFunc.h"
#include <forward_list>


int main(){

	std::string filename;
    std::string membuf;
    std::string timebuf;
    std::forward_list<Job> Job_List;
	double mem;
	double Jtime;

	//Set random seed
	srand((unsigned) time(0));

	//generate data in file and set filename
	std::string data_file = generate_data();

	std::ifstream infile(data_file);

	while (getline(infile, membuf, ',') && getline(infile, timebuf)){

		//convert string data to double
        mem = std::stod(membuf);
        Jtime = std::stod(timebuf);

		//create job and add to list
        Job j(Jtime, mem);
        Job_List.push_front(j);
	}

	//close file
	infile.close();

	//print out list
    while(!Job_List.empty()) {
        std::cout << Job_List.front() << std::endl;
        Job_List.pop_front();
    }

	return 0;
}

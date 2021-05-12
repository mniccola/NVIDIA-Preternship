// #include <iostream>
// #include <fstream>
// #include <string>
// #include <ctime>
// #include <cstdlib>
// #include <time.h>
#include "../inc/Job.h"
#include "../inc/mainFunc.h"
#include "../inc/analysis.h"
#include <forward_list>


int main(){

	std::string file_name;
    std::string membuf;
    std::string timebuf;
    std::forward_list<Job> Job_List;
	double mem;
	double Jtime;

	//Set random seed
	srand((unsigned) time(0));

	//generate data in file and set filename

	double m_min, m_max, t_min, t_max, num;
	//read filename from user input...
	std::cout << "Where would you like to put the generate_data (filename): ";
	std::cin >> file_name;
	std::cout << "Enter a range for Memory: ";
	std::cin >> m_min >> m_max;
	std::cout << "Enter a range for Time: ";
	std::cin >> t_min >> t_max;
	std::cout << "How many data points: ";
	std::cin >> num;
	std::cout << "...Generating data..." << std::endl;

	//std::string data_file = generate_data();

	data_generator(file_name, num, m_min, m_max, t_min, t_max);

	std::ifstream infile(file_name);

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

	double mean = calc_avg_mem(Job_List);
	double median = calc_med_mem(Job_List);
	double stdev = calc_stdev_mem(Job_List);
	double suggestion = 0;

	if(mean > median + 5) {	// skewed right
		suggestion = mean + stdev / 4;
		std::cout << "skewed right" << std::endl;
	} else if(mean < median -5) {
		suggestion = mean - stdev / 4; // skewed left
		std::cout << "skewed left" << std::endl;
	} else { // symmetric
		suggestion = mean;
		std::cout << "symmetric" << std::endl;
	}

	suggest_file(suggestion, mean, median, stdev, 0, m_min, m_max, file_name);
	//print out list
    while(!Job_List.empty()) {
        std::cout << Job_List.front() << std::endl;
        Job_List.pop_front();
    }

	return 0;
}

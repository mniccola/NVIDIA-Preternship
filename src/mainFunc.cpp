#include "../inc/mainFunc.h"

//Random double generator
double fRand(double a, double b) {
	return ((double)rand() / RAND_MAX) * (b - a) + a;
	// return (rand() % b) + a;
}


// Random Data Generator double file
void data_generator(const std::string& in_file, const int num, const double min_M, const double max_M, const double min_T, const double max_T) {
	double memory;
	double Jtime;

	std::ofstream out_file(in_file);

	for(int i = 0; i < num; i++) {

		memory = fRand(min_M, max_M);
		Jtime = fRand(min_T, max_T);
		out_file <<  memory << "," << Jtime << "\n";
	}

	out_file.close();

}

std::string generate_data() {
	std::string file_name;

	//read filename from user input...
	std::cout << "Where would you like to put the generate_data (filename): ";
	std::cin >> file_name;

	std::cout << "...Generating data..." << std::endl;

	data_generator(file_name, 1000, 0, 100, 1, 5);

	return file_name;
}

#include "../inc/mainFunc.h"


//Random double generator
double fRand(double a, double b) {
	return ((double)rand() / RAND_MAX) * (b - a) + a;
	// return (rand() % b) + a;
}


// Random Data Generator double file
void data_generator(const std::string& in_file, const double num, const double min_M, const double max_M, double min_T,  const double max_T) {
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
//
// std::string generate_data() {
// 	std::string file_name;
// 	double m_min, m_max, t_min, t_max;
// 	int num;
// 	//read filename from user input...
// 	std::cout << "Where would you like to put the generate_data (filename): ";
// 	std::cin >> file_name;
// 	std::cout << "Enter a range for Memory: ";
// 	std::cin >> m_min >> m_max;
// 	std::cout << "Enter a range for Time: ";
// 	std::cin >> t_min >> t_max;
// 	std::cout << "How many data points: ";
// 	std::cin >> num;
// 	std::cout << "...Generating data..." << std::endl;
//
// 	data_generator(file_name, num, m_min, m_max, t_min, t_max);
//
// 	return file_name;
// }

void suggest_file(const double& suggestion, const double& mean, const double& median,
	const double& stdev, const double& outlier, const double& min, const double& max, const std::string& file)
{
	std::ofstream output_file("suggest.txt");

	output_file << "Suggestion: " << std::setprecision(5) << suggestion << "\n";
	output_file << "Mean: " << std::setprecision(5) <<  mean << "\n";
	output_file << "Median: " << std::setprecision(5) <<  median << "\n";
	output_file << "Stdev: " << std::setprecision(5) <<  stdev << "\n";
	output_file << "Outliers: " << std::setprecision(5) <<  outlier << "\n";
	output_file << "Min: " << std::setprecision(5) <<  min << "\n";
	output_file << "Max: " << std::setprecision(5) <<  max << "\n";
	output_file << "data_file: " << file << "\n";
	output_file.close();
}

double outliers(double a, double b) {
	return ((double)rand() / RAND_MAX) * (b - a) + a;
}

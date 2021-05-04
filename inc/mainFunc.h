#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <time.h>

//generates data with parameters and writes it to a file
void data_generator(const std::string& in_file, const double num, const double min_M, const double max_M, const double min_T, const double max_T);

//Core random number generator
double fRand(double a, double b);

//handles user interaction for data generation process
std::string generate_data();

void suggest_file(const double, const double, const double, const double, const double);

#include <iostream>
#include <fstream>
//#include <string>
//#include <Windows.h>
#include <ctime>
#include <cstdlib>
//#include <chrono>
//#include <thread>

/* Functions */

//Random double generator
double fRand(double a, double b)
{
	return ((double)rand() / RAND_MAX) * (b - a) + a;	
}

// Random Data Generator into file
void rand_generator(){
	double memory;
	int num, time = 0;
		
	std::ofstream myfile("tempSrc.txt");

	while(num != 50){
		
		memory = fRand(14.0, 35.0);
		
		time = rand()% 13 + 1;
		
		myfile <<  memory << "," << time << "\n";
		
		num = rand()% 1000 + 1;	

	//	std::chrono::duration<int, std::milli> timespan(1000);
	//	std::this_thread::sleep_for(timespan);
		
	}

	myfile.close();

}

int main(){
	
/*
	char* filename; 
	int key;
	double mem;
	double time;
*/

	rand_generator();

/*	std::cout << "Type in the file of the name: ";

	stdcin >> filename;

	ifstream myfile (filename);

	while (getline(key, mem, time, ',')){
		
	}
	*/
	return 0;
}

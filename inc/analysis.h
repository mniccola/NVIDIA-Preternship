#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>

class analysis
{
	private:
		float average;
		float median;
		float mode;

	public:
		float get_average() const;
		float get_median() const;
		float get_mode() const;

		// Default Constructor
		analysis();
	
		// Overloaded Constructor
	//	analysis(const float &in_average, const float &in_median, const float &in_mode);

		void set_average(const float data[][]);
		void set_memory(const float data[][]);
		void set_mode(const float data[][]);

};

#endif

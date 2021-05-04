#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <iomanip>


class Job
{
	private:
		double time;
		double memory;

	public:
		double get_time() const;
		double get_memory() const;

		// Default Constructor
		Job();

		// Overloaded Constructor
		Job(const double &in_time, const double &in_memory);

		void set_time(const double &in_time);
		void set_memory(const double &in_memory);

		friend std::ostream& operator<<(std::ostream& out, const Job& J);

};

#endif

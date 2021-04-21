#include <iostream>

class Job
{
	private:
		float time;
		float memory;

	public:
		float get_time() const;
		float get_memory() const;

		// Default Constructor
		Job();
	
		// Overloaded Constructor
		Job(const float &in_time, const float &in_memory);

		float set_time(const float &in_time);
		float set_memory(const float &in_memory);

};

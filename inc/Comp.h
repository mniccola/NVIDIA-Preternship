#ifndef COMP_H
#define COMP_H

#include <iostream>

class Comp
{
	private:
		float totalMemory;
        float avaliableMemory;

	public:
		float get_memory() const;

        float get_avaliable() const;
		// Default Constructor
		Comp();

		// Overloaded Constructor
		Comp(const float &in_memory, const float &in_available);

		void set_memory(const float &in_memory);
        void update_avaliable(const float&in_avail);

};

#endif

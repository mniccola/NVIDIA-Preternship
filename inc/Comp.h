#ifndef COMP_H
#define COMP_H

#include <iostream>

class Comp
{
	private:
		float memory;

	public:
		float get_memory() const;

		// Default Constructor
		Comp();

		// Overloaded Constructor
		Comp(const float &in_memory);
		void set_memory(const float &in_memory);

};

#endif

#include "../inc/Comp.h"

// Default Constructor
Comp::Comp() : memory(0) {}

// Overloaded Constructor
Comp::Comp(const float& in_memory) : memory(in_memory) {}

// get memory used by computer
float Comp::get_memory() const {
	return memory;
}

// set memory used by computer
void Comp::set_memory(const float& in_memory){
	memory = in_memory;
}

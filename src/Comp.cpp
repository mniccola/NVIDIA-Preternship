#include "../inc/Comp.h"

// Default Constructor
Comp::Comp() : totalMemory(100) avaliableMemory(100) {}

// Overloaded Constructor
Comp::Comp(const float& in_memory, const float& in_available)
	: totalMemory(in_memory) avaliableMemory(in_available)  {}

// get memory used by computer
float Comp::get_memory() const {
	return totalMemory;
}

float Comp::get_avaliable() const {
	return avaliableMemory;
}

// set memory used by computer
void Comp::set_memory(const float& in_memory){
	memory = in_memory;
}

void Comp::update_avaliable(const float& in_available){
	avaliableMemory = in_available;
}

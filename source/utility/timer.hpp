#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <ctime> 

struct Timer {
	std::chrono::high_resolution_clock::time_point point = std::chrono::high_resolution_clock::now();

	void start() {
		point = std::chrono::high_resolution_clock::now();
	}

	uintmax_t get() {
		auto current = std::chrono::high_resolution_clock::now();
		uintmax_t micro =  std::chrono::duration_cast<std::chrono::microseconds>(current - point).count();
		return micro;
	}
};

#endif
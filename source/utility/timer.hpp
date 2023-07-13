#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <ctime> 

struct Timer {
	std::chrono::high_resolution_clock::time_point point;

	void start() {
		point = std::chrono::high_resolution_clock::now();
	}

	double_t get() {
		auto current = std::chrono::high_resolution_clock::now();
		int64_t milli =  std::chrono::duration_cast<std::chrono::milliseconds>(current - point).count();
		return milli / 1000.0; 
	}
};

#endif
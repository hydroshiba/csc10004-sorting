#ifndef UTIL_TIMER_HPP
#define UTIL_TIMER_HPP

#include <chrono>

struct Timer {
	std::chrono::high_resolution_clock::time_point point = std::chrono::high_resolution_clock::now();

	void start() {
		point = std::chrono::high_resolution_clock::now();
	}

	uintmax_t get() {
		auto current = std::chrono::high_resolution_clock::now();
		uintmax_t milli =  std::chrono::duration_cast<std::chrono::milliseconds>(current - point).count();
		return milli;
	}
};

#endif
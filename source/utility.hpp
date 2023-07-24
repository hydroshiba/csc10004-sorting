#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#define slash "\\"
#else
	#define slash "/"
#endif

#ifndef UTIL_HPP
#define UTIL_HPP

#include "utility/counter.hpp"
#include "utility/random.hpp"
#include "utility/timer.hpp"
#include "utility/DataGenerator.cpp"


namespace order {
	std::unordered_map<std::string, int> id = {
		{"-rand", 1}, 
		{"-sorted", 2},
		{"-rev", 3},
		{"-nsorted", 4}
	};

	const std::string name[] = {
		"Invalid",
		"Random",
		"Sorted",
		"Reversed",
		"Nearly sorted"
	};
}

namespace param {
	std::unordered_map<std::string, int> id = {
		{"-time", 1}, 
		{"-comp", 2}, 
		{"-both", 3}
	};
}

#endif
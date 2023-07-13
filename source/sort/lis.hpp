#ifndef SORT_LIS_HPP
#define SORT_LIS_HPP

#include <cstdint>
#include <algorithm>
#include "merge.hpp"

template <typename iter, class Compare>
iter* lis(iter begin, iter end, Compare &func) {
	auto argfunc = [&](const iter &a, const iter &b) {
		return func(*a, *b);
	};
	
	size_t size = end - begin;
	size_t len = 0;

	iter* dp = new iter[size + 1];
	iter* last = new iter[size + 1];

	dp[0] = end;
	for(size_t i = 0; i <= size; ++i) last[i] = end;

	for(iter i = begin; i != end; ++i) {
		size_t pos = std::upper_bound(dp + 1, dp + len + 1, i, argfunc) - dp;
		
		if(pos > len) dp[++len] = i;
		else if(!func(*dp[pos], *i)) dp[pos] = i;
		last[i - begin] = dp[pos - 1];
	}

	iter cur = dp[len];
	iter* res = new iter[len + 1];

	res[len] = end;
	while(cur != end) {
		res[--len] = cur;
		cur = last[cur - begin];
	}

	delete[] dp;
	delete[] last;
	return res;
}

template <typename iter, class Compare>
void lisSort(iter begin, iter end, Compare &func) {
	if(end - begin < 2) return;

	size_t size = end - begin, pos;
	iter* subsequence = lis(begin, end, func);

	for(pos = 0; subsequence[pos] != end; ++pos) {
		std::swap(*subsequence[pos], *(begin + pos));
	}
	
	delete[] subsequence;

	std::reverse(begin + pos, end);
	lisSort(begin + pos, end, func);
	merge(begin, begin + pos, begin + pos, end, begin, func);
}

template <typename iter>
void lisSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;

	auto func = std::less<Type>();
	lisSort(begin, end, func);
}

#endif
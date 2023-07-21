#ifndef SORT_LIS_HPP
#define SORT_LIS_HPP

/* ---------------------- LIS SORT ---------------------- */

// See codeforces.com/blog/entry/97703 for an in-depth exploration of this algorithm.
// Refer to source/sort/merge.hpp for merge function.

/*
- Average Complexity: O(N sqrt(N) log N)
- Best Complexity: O(N log N)
- Worst Complexity: O(N sqrt(N) log N)
- Space Complexity: O(sqrt(N))
- Stability: No
*/

#include <algorithm>
#include <iterator>
#include <utility>
#include "merge.hpp"

template <typename iter, class Compare, class CompareLoop>
iter* lis(iter begin, iter end, Compare &func, CompareLoop &loop) {
	auto argfunc = [&func](const iter &a, const iter &b) {
		return func(*a, *b);
	};
	
	size_t size = end - begin;
	size_t len = 0;

	iter* dp = new iter[size + 1];
	iter* last = new iter[size + 1];

	dp[0] = end;
	for(size_t i = 0; !loop(size, i); ++i) last[i] = end;

	for(iter i = begin; loop(i - begin, size); ++i) {
		size_t pos = std::upper_bound(dp + 1, dp + len + 1, i, argfunc) - dp;
		
		if(loop(len, pos)) dp[++len] = i;
		else if(!func(*dp[pos], *i)) dp[pos] = i;
		last[i - begin] = dp[pos - 1];
	}

	iter cur = dp[len];
	iter* res = new iter[len + 1];

	res[len] = end;
	while(loop(cur - begin, size)) {
		res[--len] = cur;
		cur = last[cur - begin];
	}

	delete[] dp;
	delete[] last;
	return res;
}

template <typename iter, class Compare, class CompareLoop>
void lisSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
	if(end - begin < 2) return;

	size_t size = end - begin, pos;
	iter* subsequence = lis(begin, end, func, loop);

	for(pos = 0; loop(subsequence[pos] - begin, size); ++pos) {
		std::swap(*subsequence[pos], *(begin + pos));
	}
	
	delete[] subsequence;

	std::reverse(begin + pos, end);
	lisSort(begin + pos, end, func, loop);
	merge(begin, begin + pos, begin + pos, end, begin, func, loop);
}

template <typename iter, class Compare>
void lisSort(iter begin, iter end, Compare &func) {
	auto loop = std::less<size_t>();
	lisSort(begin, end, func, loop);
}

template <typename iter>
void lisSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
	auto func = std::less<Type>();
	lisSort(begin, end, func);
}

#endif
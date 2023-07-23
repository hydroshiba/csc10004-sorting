#ifndef SORT_SHAKER_HPP
#define SORT_SHAKER_HPP

#include <iterator>
#include <utility>

template<class Compare>
void shakerSort(int *a, int n, Compare &func)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++func.count && Left < Right)
	{
		for (int i = Left; ++func.count && i < Right; i++)
		{
			if (++func.count && a[i] > a[i + 1])
			{
				std::swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; ++func.count && i > Left; i--)
		{
			if (func(a[i], a[i - 1]))
			{
				std::swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}


#endif
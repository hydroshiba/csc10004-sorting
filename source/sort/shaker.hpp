#ifndef SORT_SHAKER_HPP
#define SORT_SHAKER_HPP

template<class Comparator>
void shakerSort_countCMP(int *a, int n, Comparator &count)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++count && Left < Right)
	{
		for (int i = Left; ++count && i < Right; i++)
		{
			if (++count && a[i] > a[i + 1])
			{
				swapNum(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right;++count && i > Left; i--)
		{
			if (++count && a[i] < a[i - 1])
			{
				swapNum(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}


void shakerSort(int* a, int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swapNum(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swapNum(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

#endif
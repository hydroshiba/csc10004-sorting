#ifndef FLASH_SORT_
#define FLASH_SORT_

#include <vector>
#include <algorithm>
#include <vector>

template<class Compare>
void flashSort(std::vector<int>& arr, Compare &func) {
    int n = arr.size();

    if (n <= 1) return;

    int m = static_cast<int>(n * 0.43);
    if (m <= 2) m = 2;

    std::vector<int> L(m, 0);

    int max_val = arr[0], min_val = arr[0];
    for (int i = 1; i < n; ++i) {
        if (func(max_val, arr[i])) max_val = arr[i];
        if (min_val > arr[i]) {
            min_val = arr[i];
            func.count++;
        }
    }

    if (max_val == min_val) return;
    func.count++;
    auto calcK = [&](int x) {
        return (long long)(m - 1) * (x - min_val) / (max_val - min_val);
    };

    for (int i = 0; func(i, n); ++i) {
        ++L[calcK(arr[i])];
    }
    for (int i = 1; func(i,m); ++i) {
        L[i] += L[i - 1];
    }
    int count = 0;
    int i = 0;
    while (func(count, n)) {
        int k = calcK(arr[i]);
        while (i >= L[k]) {
            k = calcK(arr[++i]);
            func.count++;
        }
        int z = arr[i];
        while (i != L[k]) {
            func.count++;
            k = calcK(z);
            int y = arr[L[k] - 1];
            arr[--L[k]] = z;
            z = y;
            ++count;
        }
    }
    for (int k = 1; func(k, m); ++k) {
        for (int i = L[k] - 2; i >= L[k-1]; --i) {
            func.count++;
            if (arr[i] > arr[i + 1]) {
                func.count++;
                int t = arr[i];
                int j = i;
                while (t > arr[j + 1]) {
                    func.count++;
                    arr[j] = arr[j + 1]; 
                    ++j;
                }
                arr[j] = t;
            }
        }
    }
}


#endif
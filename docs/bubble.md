# Bubble Sort Algorithm Presentation

This is a presentation about the _`Bubble Sort`_ algorithm, which is represented by Nguyen Thanh Thai - Student ID: 22127383


## 🔴 IDEAS

`Bubble Sort` is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. 

The algorithm gets its name from the way smaller elements "bubble" to the top of the list while larger elements "sink" to the bottom. Bubble Sort is straightforward to understand but is not very efficient, especially for large datasets.

## 🔴 STEP-BY-STEP DESCRIPTION
1. _Start_ with the first element (index 0) as the current element.

2. _Compare_ it with the next element (index 1), and if it is greater, swap them.

3. _Move_ to the next element (index 1) and compare it with the following element (index 2), and so on.

4. After one pass through the list, the largest element will be at the last position.

5. _Repeat_ the process for the remaining unsorted portion of the list.

6. _Continue_ this process until the entire list becomes sorted.
## 🔴PSEUDOCODE
    for (i <- 0 to n - 2)
      for (j <- 0 to n - i - 1)
        if (a[j] > a[j + 1]) 
          then a[j] <-> a[j + 1]
      end for
    end for
    
## 🔴COMPLEXITY:
_Average Case Complexity:_ $O(N^2)$
- `Best Case Complexity:` $O(N)$
- `Worst Case Complexity:` $O(N^2)$
- `Space Complexity:` $O(1)$
- `Stability:` $Yes$

## 🔴VARIANTS/IMPROMENTS:

### 1. Modified Bubble Sort (or Short Bubble Sort)

This variant of `Bubble Sort` makes a small optimization to the standard `Bubble Sort`. The idea is to introduce a flag that keeps track of whether any swaps were made during a pass through the array. If no swaps were made during a pass, it means the array is already sorted, and the algorithm can terminate early. This helps to reduce the number of unnecessary comparisons and swaps, especially in nearly sorted arrays.

### 2. Comb Sort 

`Comb Sort` is another improvement over `Bubble Sort` that addresses some of its limitations. Instead of comparing and swapping adjacent elements, Comb Sort uses a "gap" value that starts as the length of the array and reduces in each pass until it becomes 1 (similar to the idea of `Shell Sort`). The gap value determines the distance between elements being compared and swapped. By using a larger gap initially, `Comb Sort` can quickly eliminate small elements at the end of the array and then progressively reduce the gap to perform smaller, more fine-grained comparisons and swaps.

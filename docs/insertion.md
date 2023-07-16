# Insertion Sort Algorithm Presentation

This is a presentation about the _`Insertion Sort`_ algorithm, which is represented by Nguyen Thanh Thai - Student ID: 22127383


## 🔴 IDEAS

The basic idea behind _`Insertion Sort`_ is to take an element from the unsorted portion of the array and insert it into its correct position in the sorted portion of the array. 

This process is repeated until the entire array is sorted.

## 🔴 STEP-BY-STEP DESCRIPTION
1. _Start_ with the first element of the array, considering it as the sorted portion.

2. _Take_ the next element from the unsorted portion of the array.

3. _Compare_ the selected element with the elements in the sorted portion, moving from right to left, until you find the correct position for the selected element.

4. While comparing, if you encounter an element in the sorted portion that is greater than the selected element, shift that element one position to the right to make space for the selected element.

5. _Insert_ the selected element into its correct position in the sorted portion.

6. _Repeat_ steps 2 to 5 for all remaining elements in the unsorted portion of the array.

7. _Continue_ this process until the entire array becomes sorted.

## 🔴PSEUDOCODE
    for (i <- 0 to n - 1) do
        x <- a[i]
        pos <- i - 1;
        while (pos >= 0 && a[pos] > x) do
            a[ pos + 1] = a[pos]
            pos <- pos - 1;
        end while
        a[pos + 1] = x
    end for

## 🔴COMPLEXITY:
_Average Case Complexity:_ $O(N^2)$
- `Best Case Complexity:` $O(N)$
- `Worst Case Complexity:` $O(N^2)$
- `Space Complexity:` $O(1)$
- `Stability:` $Yes$

## 🔴VARIANTS/IMPROMENTS:

### 1. Binary Insertion Sort

`Binary Insertion Sort` is a modification of the standard `Insertion Sort` that uses binary search to find the correct position to insert an element into the sorted portion of the array. In the standard `Insertion Sort`, finding the correct position involves linear search, which takes $O(n)$ time in the worst case. Binary search reduces this to $O(log n)$ time, resulting in a more efficient insertion process. However, the overall time complexity of `Binary Insertion Sort` remains $O(n^2)$ due to the shifting of elements.

### 2. Block Sort

`Block Sort` is another variant of `Insertion Sort` that sorts elements in blocks of fixed size. The sorting process is performed within these blocks using `Insertion Sort`. Once the blocks are sorted, they are merged to produce the final sorted array. `Block Sort` can improve the performance of `Insertion Sort` for large arrays by reducing the number of comparisons and movements.






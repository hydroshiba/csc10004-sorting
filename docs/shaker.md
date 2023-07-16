# Shaker Sort Algorithm Presentation

This is a presentation about the _`Shaker Sort`_ algorithm, which is represented by Nguyen Thanh Thai - Student ID: 22127383


## 🔴 IDEAS

`Shaker Sort`, also known as `Cocktail Shaker Sort` or `Bidirectional Bubble Sort`, is an improvement over the standard `Bubble Sort` algorithm. The idea behind `Shaker Sort` is to address one of the `Bubble Sort's` limitations, which is its inefficiency in sorting elements located towards the end of the array.

## 🔴 STEP-BY-STEP DESCRIPTION
1. _Start_ with the assumption that the entire array is unsorted.

2. _Set_ two pointers, left and right, initially pointing to the first and last elements of the array, respectively.

3. _Perform_ a forward pass (left to right) through the array, similar to the Bubble Sort algorithm. Compare adjacent elements and swap them if they are in the wrong order. After this pass, the largest element will "bubble up" to the last position.

4. _Decrement_ the right pointer to exclude the last element, as it is already in its correct position.

5. _Perform_ a backward pass (right to left) through the remaining unsorted portion of the array. Compare adjacent elements and swap them if they are in the wrong order. After this pass, the second largest element will be in its correct position, just before the largest element.

6. _Increment_ the left pointer to exclude the first element, as it is already in its correct position.

7. _Repeat_ steps 3 to 6 until the left and right pointers meet each other or cross each other. In each pass, one more element from each end of the array becomes sorted.


## 🔴PSEUDOCODE
    surface <- 0;
    bottom <- n - 1;
    k <- n - 1;
    while ( surface < bottom ) do
      for (j <- bottom to surface + 1) do
        if (a[j - 1] > a[j]) then
          a[j - 1] <-> a[j];
          k <- j;
        end if
      surface <- k;
      for (j <- surface to bottom - 1) do
        if (a[j] > a[j + 1]) then
          a[j + 1] <-> a[j];
          k <- j;
        end if;
      bottom <- k;
    end while
  

## 🔴COMPLEXITY:
_Average Case Complexity:_ $O(N^2)$
- `Best Case Complexity:` $O(N)$
- `Worst Case Complexity:` $O(N^2)$
- `Space Complexity:` $O(1)$
- `Stability:` $Yes$

## 🔴VARIANTS/IMPROMENTS:

### 1. Optimized Shaker Sort

An optimized version of `Shaker Sort` can use the same idea as the optimized `Bubble Sort`. In each pass, track the last swap index for both the forward and backward passes. By recording the last swap position, you can reduce the number of comparisons in subsequent passes, as all elements after that index are already in their correct positions. This optimization can save unnecessary comparisons and make the sorting process faster, especially for partially sorted or nearly sorted arrays.

### 2. Comb Sort 

`Comb Sort` is another improvement over `Bubble Sort` that addresses some of its limitations. Instead of comparing and swapping adjacent elements, Comb Sort uses a "gap" value that starts as the length of the array and reduces in each pass until it becomes 1 (similar to the idea of `Shell Sort`). The gap value determines the distance between elements being compared and swapped. By using a larger gap initially, `Comb Sort` can quickly eliminate small elements at the end of the array and then progressively reduce the gap to perform smaller, more fine-grained comparisons and swaps.

### 3. Library Sort (Adaptive Merge Sort)

`Library Sort` is a hybrid sorting algorithm that combines `Insertion Sort`, `Bubble Sort`, and `Merge Sort`. It is considered an improvement because it utilizes the strengths of `Bubble Sort` (`Shaker Sort` is a variant of `Bubble Sort`) for small subarrays and switches to `Merge Sort` for larger subarrays. This hybrid approach can be more efficient than pure `Bubble Sort` or `Shaker Sort` for larger arrays.

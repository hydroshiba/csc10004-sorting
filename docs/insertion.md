# Insertion Sort Algorithm Presentation

This is a presentation about the bubble sort algorithm, which is represented by Nguyen Thanh Thai - Student ID: 22127383


## 🔴 IDEAS

The basic idea behind Insertion Sort is to take an element from the unsorted portion of the array and insert it into its correct position in the sorted portion of the array. 

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
    for (i <- 0 to n - 2)

      for (j <- 0 to n - i - 1)
  
        if (a[j] > a[j + 1]) then a[j] <-> a[j + 1]
    
          end
      
    end

## 🔴COMPLEXITY:
_Average Complexity:_ $O(N^2)$
- `Best Complexity:` $O(N)$
- `Worst Complexity:` $O(N^2)$
- `Space Complexity:` $O(1)$
- `Stability:` $Yes$

## 🔴VARIANTS/IMPROMENTS:

### Modified Bubble Sort (or Short Bubble Sort)

This variant of `Bubble Sort` makes a small optimization to the standard `Bubble Sort`. The idea is to introduce a flag that keeps track of whether any swaps were made during a pass through the array. If no swaps were made during a pass, it means the array is already sorted, and the algorithm can terminate early. This helps to reduce the number of unnecessary comparisons and swaps, especially in nearly sorted arrays.

### Comb Sort:

`Comb Sort` is another improvement over Bubble Sort that addresses some of its limitations. Instead of comparing and swapping adjacent elements, Comb Sort uses a "gap" value that starts as the length of the array and reduces in each pass until it becomes 1 (similar to the idea of `Shell Sort`). The gap value determines the distance between elements being compared and swapped. By using a larger gap initially, `Comb Sort` can quickly eliminate small elements at the end of the array and then progressively reduce the gap to perform smaller, more fine-grained comparisons and swaps.






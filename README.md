# Algorithm Solutions

This repository contains solutions to various algorithm problems implemented in C++.

## Files and Algorithms

### [singleElementinSort.cpp](./singleElementinSort.cpp)

**Finds the single non-duplicate element in a sorted array**

-  Implements binary search to achieve O(log n) time complexity
-  Uses the property of sorted pairs to narrow down the search space
-  Returns the element that appears only once
-  Includes driver code to demonstrate functionality

### [removduplicates.cpp](./removduplicates.cpp)

**Removes duplicates from a sorted array**

-  Uses two pointers: one to track unique elements position, another to scan the array
-  When a new unique element is found, move it to the position after the last unique element

### [leftshift.cpp](./leftshift.cpp)

**Rotates an array to the right by k steps**

-  Reverses the entire array, then reverses first k elements, then reverses remaining elements
-  In-place solution with O(1) extra space

### [movezeros.cpp](./movezeros.cpp)

**Moves all zeros to the end of array**

-  Maintains a pointer to the position where next non-zero element should go
-  Iterate through array, move non-zeros to their positions, then fill remaining with zeros

### [missingNum.cpp](./missingNum.cpp)

**Finds missing number in range [0,n]**

-  Calculate expected sum formula: n\*(n+1)/2
-  Subtract actual array sum from expected sum to find missing number

### [maxconsec1.cpp](./maxconsec1.cpp)

**Finds maximum consecutive 1's**

-  Track current streak and maximum streak of 1's
-  Reset counter when 0 is found, update max when current exceeds it

### [singleNum.cpp](./singleNum.cpp)

**Finds single number among duplicates**

-  Uses XOR operation on all elements
-  Since a⊕a=0 and a⊕0=a, duplicates cancel out leaving only the single number

### [TwoArraysUnion.cpp](./TwoArraysUnion.cpp)

**Finds union of two sorted arrays**

-  Uses two pointers to compare elements from both arrays
-  Takes smaller element, skips duplicates, and advances appropriate pointer

### [LongestSubarrayWithSumK.cpp](./LongestSubarrayWithSumK.cpp)

**Finds longest subarray with sum k**

-  Uses prefix sum technique with a hashmap
-  Stores first occurrence of each sum and checks if (current_sum - k) exists in map

### [2Sum.cpp](./2Sum.cpp)

**Finds two numbers that sum to target**

-  Uses hashmap to store (value, index) pairs
-  For each element, checks if (target - current) is in the map

### [sortColor.cpp](./sortColor.cpp)

**Dutch national flag problem (sort 0,1,2)**

-  Uses three pointers (low, mid, high) to partition the array
-  Swaps elements based on their values to arrange all 0s, 1s, and 2s in order

### [largestfreq.cpp](./largestfreq.cpp)

**Finds majority element (>n/2 occurrences)**

-  Implements Boyer-Moore voting algorithm
-  Maintains a candidate and counter, incrementing for candidate and decrementing for others

### [majorityEl2.cpp](./majorityEl2.cpp)

**Finds elements appearing >n/3 times**

-  Extends Boyer-Moore algorithm to track two candidates
-  Verifies actual counts in a second pass

### [MaxSubarr.cpp](./MaxSubarr.cpp)

**Finds maximum subarray sum**

-  Implements Kadane's algorithm to find maximum sum subarray
-  Tracks current sum and resets to 0 when negative

### [bestTimetosell.cpp](./bestTimetosell.cpp)

**Finds maximum profit from single stock transaction**

-  Tracks minimum price seen so far
-  Calculates potential profit at each price and updates maximum profit

### [RearrangeArrwithSign.cpp](./RearrangeArrwithSign.cpp)

**Rearranges array with alternating positive/negative**

-  Separates positive and negative numbers
-  Places positives at even indices and negatives at odd indices

### [setMatrixZeroes.cpp](./setMatrixZeroes.cpp)

**Sets row and column to zero if element is zero**

-  Uses first row and column as markers for which rows/columns to zero
-  Processes matrix in specific order to preserve the markers

### [rotate2dArr.cpp](./rotate2dArr.cpp)

**Rotates matrix 90 degrees clockwise**

-  Transposes the matrix (rows become columns)
-  Reverses each row to complete the rotation

### [spiralmatrix.cpp](./spiralmatrix.cpp)

**Returns matrix elements in spiral order**

-  Processes matrix layer by layer from outside in
-  Uses boundary variables (top, right, bottom, left) that shrink after each direction

### [pascaltriangle.cpp](./pascaltriangle.cpp)

**Generates Pascal's Triangle**

-  First row is always [1], each subsequent row starts and ends with 1
-  Middle elements are calculated as sum of two elements above from previous row

### [reversePairs.cpp](./reversePairs.cpp)

**Counts reverse pairs where nums[i] > 2\*nums[j]**

-  Uses modified merge sort algorithm
-  Counts qualifying pairs during the merge process

### [insertPos.cpp](./insertPos.cpp)

**Finds insertion position in sorted array**

-  Implements binary search to efficiently find position
-  Returns index of target or position where it would be inserted if not found

### [lowboundUper.cpp](./lowboundUper.cpp)

**Finds range of target in sorted array**

-  Uses two binary searches: one for leftmost occurrence, one for rightmost
-  Returns [-1, -1] if target is not found

### [Search in Rotated Sorted Array II.cpp](./Search%20in%20Rotated%20Sorted%20Array%20II.cpp)

**Searches in rotated sorted array with duplicates**

-  Handles duplicates by shrinking range when arr[low]=arr[mid]=arr[high]
-  Determines which half is sorted and checks if target is in that half

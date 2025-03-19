# Algorithm Solutions

This repository contains solutions to various algorithm problems implemented in C++. Each solution is encapsulated in its own file with a corresponding main function to test the implementation.

## Files

-  [`removduplicates.cpp`](./removduplicates.cpp): Removes duplicates from a sorted array and returns the number of unique elements.
-  [`leftshift.cpp`](./leftshift.cpp): Rotates an array to the right by a given number of steps.
-  [`movezeros.cpp`](./movezeros.cpp): Moves all zeros in an array to the end while maintaining the relative order of non-zero elements.
-  [`missingNum.cpp`](./missingNum.cpp): Finds the missing number in an array containing distinct numbers in the range [0, n].
-  [`maxconsec1.cpp`](./maxconsec1.cpp): Finds the maximum number of consecutive 1's in a binary array.
-  [`singleNum.cpp`](./singleNum.cpp): Finds the single number in an array where every element appears twice except for one.
-  [`TwoArraysUnion.cpp`](./TwoArraysUnion.cpp): Finds the union of two sorted arrays and returns the result in sorted order.
-  [`LongestSubarrayWithSumK.cpp`](./LongestSubarrayWithSumK.cpp): Finds the length of the longest subarray where the sum of its elements is equal to a given value k.
-  [`2Sum.cpp`](./2Sum.cpp): Finds the indices of the two numbers in an array that add up to a given target.
-  [`sortColor.cpp`](./sortColor.cpp): Sorts an array of colors represented by integers 0, 1, and 2 in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
-  [`largestfreq.cpp`](./largestfreq.cpp): Contains the implementation of the `majorityElement` function and the driver code to test it.
-  [`majorityEl2.cpp`](./majorityEl2.cpp): Finds all elements that appear more than ⌊n/3⌋ times in the array using two different algorithms.
-  [`MaxSubarr.cpp`](./MaxSubarr.cpp): Contains the implementation of the solution and driver code.
-  [`MaxsumforMinsubarr.cpp`](./MaxsumforMinsubarr.cpp): Contains the implementation of the solution and driver code.
-  [`bestTimetosell.cpp`](./bestTimetosell.cpp): Contains implementation to find maximum profit that can be achieved by buying and selling stocks.
-  [`RearrangeArrwithSign.cpp`](./RearrangeArrwithSign.cpp): Contains implementation to rearrange an array with alternating positive and negative integers while preserving order.
-  [`setMatrixZeroes.cpp`](./setMatrixZeroes.cpp): Sets entire row and column to zero if an element in the matrix is zero.
-  [`rotate2dArr.cpp`](./rotate2dArr.cpp): Contains the solution and driver code to read input, rotate the matrix, and write the output.
-  [`spiralmatrix.cpp`](./spiralmatrix.cpp): Returns all elements of a matrix in spiral order.
-  [`pascaltriangle.cpp`](./pascaltriangle.cpp): Generates Pascal's Triangle up to a specified number of rows.
-  [`reversePairs.cpp`](./reversePairs.cpp): Counts the number of reverse pairs in an array using the merge sort algorithm.
-  [`insertPos.cpp`](./insertPos.cpp): Finds the index where a target value should be inserted in a sorted array.

## Overview of Each File

### [removduplicates.cpp](./removduplicates.cpp)

Removes duplicates from a sorted array in-place such that each unique element appears only once. The relative order of the elements is maintained. Returns the number of unique elements.

#### Approach

1. Use two pointers to iterate through the array.
2. One pointer keeps track of the position of the unique elements.
3. The other pointer iterates through the array to find unique elements.
4. Overwrite the array with unique elements.

### [leftshift.cpp](./leftshift.cpp)

Rotates an array to the right by a given number of steps. The rotation is performed in-place with O(1) extra space.

#### Approach

1. Reverse the entire array.
2. Reverse the first k elements.
3. Reverse the remaining elements.

### [movezeros.cpp](./movezeros.cpp)

Moves all zeros in an array to the end while maintaining the relative order of non-zero elements. The operation is performed in-place without making a copy of the array.

#### Approach

1. Use two pointers to iterate through the array.
2. One pointer keeps track of the position of non-zero elements.
3. The other pointer iterates through the array to find non-zero elements.
4. Swap non-zero elements with zeros.

### [missingNum.cpp](./missingNum.cpp)

Finds the missing number in an array containing distinct numbers in the range [0, n]. The solution uses a linear runtime complexity and constant extra space.

#### Approach

1. Calculate the expected sum of numbers from 0 to n.
2. Calculate the actual sum of the array elements.
3. The missing number is the difference between the expected sum and the actual sum.

### [maxconsec1.cpp](./maxconsec1.cpp)

Finds the maximum number of consecutive 1's in a binary array. The solution iterates through the array and keeps track of the maximum count of consecutive 1's.

#### Approach

1. Initialize a counter for the current streak of 1's.
2. Initialize a variable to keep track of the maximum streak.
3. Iterate through the array and update the counters accordingly.

### [singleNum.cpp](./singleNum.cpp)

Finds the single number in an array where every element appears twice except for one. The solution uses a linear runtime complexity and constant extra space by leveraging the XOR operation.

#### Approach

1. Initialize a variable to store the result.
2. Iterate through the array and XOR each element with the result.
3. The result will be the single number.

### [TwoArraysUnion.cpp](./TwoArraysUnion.cpp)

Finds the union of two sorted arrays and returns the result in sorted order. The union is defined as the set containing distinct common elements that are present in either of the arrays.

#### Approach

1. Use two pointers to iterate through both arrays.
2. Compare elements and add the smaller element to the result.
3. If elements are equal, add one of them to the result and move both pointers.
4. Add remaining elements from both arrays to the result.

### [LongestSubarrayWithSumK.cpp](./LongestSubarrayWithSumK.cpp)

Finds the length of the longest subarray where the sum of its elements is equal to a given value k. The solution uses a map to store prefix sums and achieves a linear runtime complexity.

#### Approach

1. Initialize a map to store prefix sums.
2. Initialize variables to keep track of the current sum and the maximum length.
3. Iterate through the array and update the current sum.
4. Check if the current sum minus k exists in the map.
5. Update the maximum length if a valid subarray is found.

### [2Sum.cpp](./2Sum.cpp)

Finds the indices of the two numbers in an array that add up to a given target. The solution uses a hash map to achieve a linear runtime complexity.

#### Approach

1. Initialize a hash map to store the indices of the elements.
2. Iterate through the array and check if the complement of the current element exists in the map.
3. If the complement exists, return the indices.
4. Otherwise, add the current element to the map.

### [sortColor.cpp](./sortColor.cpp)

Sorts an array of colors represented by integers 0, 1, and 2 in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. The solution uses a counting sort approach to achieve this in one pass with constant extra space.

#### Approach

1. Count the number of occurrences of each color (0, 1, 2).
2. Overwrite the array with the correct number of each color in the order 0, 1, 2.

### [largestfreq.cpp](./largestfreq.cpp)

Contains the implementation of the `majorityElement` function and the driver code to test it. The majority element is the element that appears more than ⌊n / 2⌋ times.

#### Approach

1. Use the Boyer-Moore Voting Algorithm to find the majority element.
2. Initialize a candidate and a counter.
3. Iterate through the array and update the candidate and counter accordingly.

### [majorityEl2.cpp](./majorityEl2.cpp)

Finds all elements in an array that appear more than ⌊n/3⌋ times using two different algorithms. At most, there can be two such elements in any array.

#### Approach 1: Hashmap Method

1. Use an unordered map to count the occurrences of each element.
2. Iterate through the map and add elements that appear more than ⌊n/3⌋ times to the result.

Time Complexity: O(n) where n is the size of the input array.
Space Complexity: O(n) for storing the hashmap.

#### Approach 2: Boyer-Moore Voting Algorithm

1. Since at most two elements can appear more than ⌊n/3⌋ times, we can extend the Boyer-Moore Voting Algorithm to track two candidates.
2. Iterate through the array to find two potential majority elements.
3. Verify the candidates by counting their actual occurrences.
4. Return the elements that appear more than ⌊n/3⌋ times.

Time Complexity: O(n) where n is the size of the input array.
Space Complexity: O(1) as we only use variables to track candidates and counters.

Example Input:

```
[3,2,3]
```

Expected Output:

```
[3]
```

Example Input:

```
[1,2]
```

Expected Output:

```
[1,2]
```

### [MaxSubarr.cpp](./MaxSubarr.cpp)

Contains the implementation of the solution and driver code.

### [MaxsumforMinsubarr.cpp](./MaxsumforMinsubarr.cpp)

Contains the implementation of the solution and driver code.

### [bestTimetosell.cpp](./bestTimetosell.cpp)

Implements a solution to find the maximum profit that can be achieved by buying and selling a stock. The problem requires finding the best single day to buy and best future day to sell.

#### Approach

1. Use a single pass through the array.
2. Keep track of the minimum price seen so far.
3. For each price, calculate potential profit if we sell at the current price.
4. Update the maximum profit if the current potential profit is greater.

Time Complexity: O(n) where n is the number of days.
Space Complexity: O(1).

Example Input:

```
6
7 1 5 3 6 4
```

Expected Output:

```
Best Time to Buy and Sell Stock Profit: 5
```

Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

### [RearrangeArrwithSign.cpp](./RearrangeArrwithSign.cpp)

Rearranges an array such that positive and negative integers alternate, starting with a positive integer while preserving the relative order of elements with the same sign.

#### Approach 1: Optimal Solution (Space Optimized)

1. Create a result array of the same size as the input array.
2. Maintain two pointers, one for positive integers (starting at index 0) and one for negative integers (starting at index 1).
3. Iterate through the original array. Place positive integers at even positions and negative integers at odd positions in the result array.
4. Increment the respective pointer by 2 after each placement.
5. Return the result array.

Time Complexity: O(n) where n is the size of the input array.
Space Complexity: O(n) for the result array.

#### Approach 2: Brute Force Solution

1. Create two separate arrays to store positive and negative integers.
2. Iterate through the original array, placing positive integers in the positive array and negative integers in the negative array.
3. Create a result array and place elements from the positive and negative arrays alternatively.
4. Return the result array.

Time Complexity: O(n) where n is the size of the input array.
Space Complexity: O(n) for the positive array, negative array, and result array.

Example Input:

```
3 1 -2 -5 2 -4
```

Expected Output:

```
3 -2 1 -5 2 -4
```

### [setMatrixZeroes.cpp](./setMatrixZeroes.cpp)

Sets entire row and column to zero if an element in the matrix is zero. The solution uses additional space to keep track of rows and columns that need to be zeroed.

#### Approach

1. Use two arrays to keep track of rows and columns that need to be zeroed.
2. Iterate through the matrix to find zero elements and mark corresponding rows and columns.
3. Iterate through the matrix again and set elements to zero based on the marked rows and columns.

### [rotate2dArr.cpp](./rotate2dArr.cpp)

Contains the solution and driver code to read input, rotate the matrix, and write the output.

### [spiralmatrix.cpp](./spiralmatrix.cpp)

Returns all elements of a matrix in spiral order.

### [pascaltriangle.cpp](./pascaltriangle.cpp)

Generates Pascal's Triangle up to a specified number of rows. Pascal's Triangle is a triangular array where each number is the sum of the two numbers above it.

#### Approach

1. Create the first row with just the element 1.
2. For each subsequent row:
   -  Start and end the row with 1.
   -  Calculate middle elements by summing the two elements above it from the previous row.

Time Complexity: O(n²) where n is the number of rows.
Space Complexity: O(n²) to store the triangle.

The program reads the number of rows from an input file, generates Pascal's Triangle, and writes the result to an output file as well as displaying it on the console.

Example Input (3 rows):

```
3
```

Expected Output:

```
Pascal's Triangle
1
1 1
1 2 1
```

### [reversePairs.cpp](./reversePairs.cpp)

Counts the number of reverse pairs in an array. A reverse pair is a pair (i, j) where 0 <= i < j < n and nums[i] > 2 \* nums[j].

#### Approach: Merge Sort

1. Use a modified merge sort algorithm to count reverse pairs during the sorting process.
2. During the merge step, count pairs that satisfy the condition before merging subarrays.
3. The solution leverages the divide and conquer paradigm to achieve O(n log n) time complexity.

Time Complexity: O(n log n) where n is the size of the input array.
Space Complexity: O(n) for the temporary array used during merging.

Example Input:

```
[1,3,2,3,1]
```

Expected Output:

```
2
```

Explanation: The reverse pairs are (1,4) and (3,4). For pair (1,4), nums[1]=3 > 2*nums[4]=2. For pair (3,4), nums[3]=3 > 2*nums[4]=2.

Example Input:

```
[2,4,3,5,1]
```

Expected Output:

```
3
```

### [insertPos.cpp](./insertPos.cpp)

Finds the index where a target value should be inserted in a sorted array. If the target is found in the array, returns its index. If not found, returns the index where it would be inserted while maintaining the sorted order.

#### Approach: Binary Search

1. Use binary search to efficiently locate the position of the target or the appropriate insertion point.
2. If the target is found, return its index.
3. If the target is not found, the insertion point is the position where the search algorithm terminates (low index).

Time Complexity: O(log n) where n is the size of the input array.
Space Complexity: O(1) as only a constant amount of extra space is used.

Example Input:

```
[1,3,5,6], target = 5
```

Expected Output:

```
2
```

Example Input:

```
[1,3,5,6], target = 2
```

Expected Output:

```
1
```

Example Input:

```
[1,3,5,6], target = 7
```

Expected Output:

```
4
```

## How to Run

1. Ensure you have a C++ compiler installed on your system.
2. Navigate to the directory containing the desired file.
3. Compile the file using the following command:
   ```sh
   g++ -o output filename.cpp
   ```
4. Run the compiled program:
   ```sh
   ./output
   ```

### Rotate 2D Array

1. Compile the program:

   ```sh
   g++ rotate2dArr.cpp -o rotate2dArr
   ```

2. Run the program:

   ```sh
   ./rotate2dArr
   ```

3. The output will be displayed on the console and written to `output.txt`.

### Spiral Matrix

1. Compile the program:

   ```sh
   g++ spiralmatrix.cpp -o spiralmatrix
   ```

2. Run the program:

   ```sh
   ./spiralmatrix
   ```

3. The output will be displayed on the console.

## Input and Output Files

-  `input.txt`: Contains input data for the programs.
-  `output.txt`: Contains output data from the programs.

## Screenshot

![Output Screenshot](./screenshot.png)

## License

This repository is licensed under the MIT License.

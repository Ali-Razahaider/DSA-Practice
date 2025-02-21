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
-  [`MaxSubarr.cpp`](./MaxSubarr.cpp): Contains the implementation of the solution and driver code.
-  [`MaxsumforMinsubarr.cpp`](./MaxsumforMinsubarr.cpp): Contains the implementation of the solution and driver code.
-  [`bestTimetosell.cpp`](./bestTimetosell.cpp): Contains implementation to find maximum profit that can be achieved by buying and selling stocks.

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

## Example

To compile and run `removduplicates.cpp`:

```sh
g++ -o removduplicates removduplicates.cpp
./removduplicates
```

To compile and run `largestfreq.cpp`:

```sh
g++ -o largestfreq largestfreq.cpp
./largestfreq
```

To compile and run `MaxSubarr.cpp`:

```sh
g++ -o MaxSubarr MaxSubarr.cpp
./MaxSubarr
```

To compile and run `MaxsumforMinsubarr.cpp`:

```sh
g++ -o MaxsumforMinsubarr MaxsumforMinsubarr.cpp
./MaxsumforMinsubarr
```

## Input and Output Files

-  `input.txt`: Contains input data for the programs.
-  `output.txt`: Contains output data from the programs.

## Screenshot

![Output Screenshot](./screenshot.png)

## License

This repository is licensed under the MIT License.

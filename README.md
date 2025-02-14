# Algorithm Solutions

This repository contains solutions to various algorithm problems implemented in C++. Each solution is encapsulated in its own file with a corresponding main function to test the implementation.

## Files

- [`removduplicates.cpp`](./removduplicates.cpp): Removes duplicates from a sorted array and returns the number of unique elements.
- [`leftshift.cpp`](./leftshift.cpp): Rotates an array to the right by a given number of steps.
- [`movezeros.cpp`](./movezeros.cpp): Moves all zeros in an array to the end while maintaining the relative order of non-zero elements.
- [`missingNum.cpp`](./missingNum.cpp): Finds the missing number in an array containing distinct numbers in the range [0, n].
- [`maxconsec1.cpp`](./maxconsec1.cpp): Finds the maximum number of consecutive 1's in a binary array.
- [`singleNum.cpp`](./singleNum.cpp): Finds the single number in an array where every element appears twice except for one.
- [`TwoArraysUnion.cpp`](./TwoArraysUnion.cpp): Finds the union of two sorted arrays and returns the result in sorted order.
- [`LongestSubarrayWithSumK.cpp`](./LongestSubarrayWithSumK.cpp): Finds the length of the longest subarray where the sum of its elements is equal to a given value k.
- [`2Sum.cpp`](./2Sum.cpp): Finds the indices of the two numbers in an array that add up to a given target.
- [`sortColor.cpp`](./sortColor.cpp): Sorts an array of colors represented by integers 0, 1, and 2 in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
- [`largestfreq.cpp`](./largestfreq.cpp): Contains the implementation of the `majorityElement` function and the driver code to test it.

## Overview of Each File

### [removduplicates.cpp](./removduplicates.cpp)

Removes duplicates from a sorted array in-place such that each unique element appears only once. The relative order of the elements is maintained. Returns the number of unique elements.

### [leftshift.cpp](./leftshift.cpp)

Rotates an array to the right by a given number of steps. The rotation is performed in-place with O(1) extra space.

### [movezeros.cpp](./movezeros.cpp)

Moves all zeros in an array to the end while maintaining the relative order of non-zero elements. The operation is performed in-place without making a copy of the array.

### [missingNum.cpp](./missingNum.cpp)

Finds the missing number in an array containing distinct numbers in the range [0, n]. The solution uses a linear runtime complexity and constant extra space.

### [maxconsec1.cpp](./maxconsec1.cpp)

Finds the maximum number of consecutive 1's in a binary array. The solution iterates through the array and keeps track of the maximum count of consecutive 1's.

### [singleNum.cpp](./singleNum.cpp)

Finds the single number in an array where every element appears twice except for one. The solution uses a linear runtime complexity and constant extra space by leveraging the XOR operation.

### [TwoArraysUnion.cpp](./TwoArraysUnion.cpp)

Finds the union of two sorted arrays and returns the result in sorted order. The union is defined as the set containing distinct common elements that are present in either of the arrays.

### [LongestSubarrayWithSumK.cpp](./LongestSubarrayWithSumK.cpp)

Finds the length of the longest subarray where the sum of its elements is equal to a given value k. The solution uses a map to store prefix sums and achieves a linear runtime complexity.

### [2Sum.cpp](./2Sum.cpp)

Finds the indices of the two numbers in an array that add up to a given target. The solution uses a hash map to achieve a linear runtime complexity.

### [sortColor.cpp](./sortColor.cpp)

Sorts an array of colors represented by integers 0, 1, and 2 in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. The solution uses a counting sort approach to achieve this in one pass with constant extra space.

#### Approach

1. Count the number of occurrences of each color (0, 1, 2).
2. Overwrite the array with the correct number of each color in the order 0, 1, 2.

#### Example

To compile and run `sortColor.cpp`:
```sh
g++ -o sortColor sortColor.cpp
./sortColor
```

### [largestfreq.cpp](./largestfreq.cpp)

Contains the implementation of the `majorityElement` function and the driver code to test it. The majority element is the element that appears more than ⌊n / 2⌋ times.

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

## Input and Output Files

- `input.txt`: Contains input data for the programs.
- `output.txt`: Contains output data from the programs.

## License

This repository is licensed under the MIT License.

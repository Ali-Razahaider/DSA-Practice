# Algorithm Solutions

This repository contains solutions to various algorithm problems implemented in C++. Each solution is encapsulated in its own file with a corresponding main function to test the implementation.

## Files

-  `removduplicates.cpp`: Removes duplicates from a sorted array and returns the number of unique elements.
-  `leftshift.cpp`: Rotates an array to the right by a given number of steps.
-  `movezeros.cpp`: Moves all zeros in an array to the end while maintaining the relative order of non-zero elements.
-  `missingNum.cpp`: Finds the missing number in an array containing distinct numbers in the range [0, n].
-  `maxconsec1.cpp`: Finds the maximum number of consecutive 1's in a binary array.
-  `singleNum.cpp`: Finds the single number in an array where every element appears twice except for one.
-  `TwoArraysUnion.cpp`: Finds the union of two sorted arrays and returns the result in sorted order.

## Overview of Each File

### removduplicates.cpp

Removes duplicates from a sorted array in-place such that each unique element appears only once. The relative order of the elements is maintained. Returns the number of unique elements.

### leftshift.cpp

Rotates an array to the right by a given number of steps. The rotation is performed in-place with O(1) extra space.

### movezeros.cpp

Moves all zeros in an array to the end while maintaining the relative order of non-zero elements. The operation is performed in-place without making a copy of the array.

### missingNum.cpp

Finds the missing number in an array containing distinct numbers in the range [0, n]. The solution uses a linear runtime complexity and constant extra space.

### maxconsec1.cpp

Finds the maximum number of consecutive 1's in a binary array. The solution iterates through the array and keeps track of the maximum count of consecutive 1's.

### singleNum.cpp

Finds the single number in an array where every element appears twice except for one. The solution uses a linear runtime complexity and constant extra space by leveraging the XOR operation.

### TwoArraysUnion.cpp

Finds the union of two sorted arrays and returns the result in sorted order. The union is defined as the set containing distinct common elements that are present in either of the arrays.

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

## Input and Output Files

-  `input.txt`: Contains input data for the programs.
-  `output.txt`: Contains output data from the programs.

## License

This repository is licensed under the MIT License.

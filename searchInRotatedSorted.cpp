/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>
#include <fstream>

class Solution {
    public:
        // Function to search for a target element in a rotated sorted array
        // Time Complexity: O(log n) - Binary search approach
        // Space Complexity: O(1) - Only using constant extra space
        int search(std::vector<int>& arr, int x) {
            int n = arr.size();
            int low = 0;
            int ans = -1;
            int high = n - 1;
    
            while (low <= high) {
                int mid = (low + high) / 2;
                
                // Case 1: Found the target
                if (arr[mid] == x) {
                    ans = mid;
                    break;
                } 
                // Case 2: Left half is sorted
                else if (arr[low] <= arr[mid]) {
                    // Check if target is in the sorted left half
                    if (arr[low] <= x && x < arr[mid])
                        high = mid - 1;  // Search in left half
                    else
                        low = mid + 1;   // Search in right half
                } 
                // Case 3: Right half is sorted
                else {
                    // Check if target is in the sorted right half
                    if (arr[mid] < x && x <= arr[high])
                        low = mid + 1;   // Search in right half
                    else
                        high = mid - 1;  // Search in left half
                }
            }
    
            return ans;
        }
    };

// Driver code to test the solution
int main() {
    Solution sol;
    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.txt");
    
    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }
    
    int numTestCases;
    inFile >> numTestCases;
    
    int passed = 0;
    int total = 0;
    
    for (int t = 0; t < numTestCases; t++) {
        int n;
        inFile >> n;
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            inFile >> nums[i];
        }
        
        int target;
        inFile >> target;
        
        total++;
        int result = sol.search(nums, target);
        
        outFile << "Test Case " << total << ":\n";
        outFile << "Array: [";
        for (int i = 0; i < n; i++) {
            outFile << nums[i];
            if (i < n - 1) outFile << ", ";
        }
        outFile << "]\n";
        outFile << "Target: " << target << "\n";
        outFile << "Output: " << result << "\n\n";
    }
    
    inFile.close();
    outFile.close();
    
    return 0;
}

/*
Approach Explanation:

1. The problem requires finding an element in a rotated sorted array with O(log n) time complexity.

2. We use a modified binary search algorithm:
   - If the middle element is the target, we return its index.
   - Otherwise, we determine which half of the array is sorted.
   - If the left half is sorted (arr[low] <= arr[mid]), we check if the target is in this sorted range.
   - If the right half is sorted, we check if the target is in this sorted range.
   - We narrow our search to the appropriate half and continue.

3. Key insight: In a rotated sorted array, at least one half (left or right from mid) 
   must be sorted, which allows us to determine which half to search.

4. Time Complexity: O(log n) as we divide the search space in half with each iteration.
   Space Complexity: O(1) as we only use a constant amount of extra space.
*/
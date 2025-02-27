#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>  // For std::swap

class Solution {
public:
    /**
     * Finds the next lexicographically greater permutation of the array.
     * If no greater permutation exists, rearranges to the smallest permutation.
     * 
     * @param nums Vector of integers to find next permutation of
     */
    void nextPermutation(std::vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        
        // Step 1: Find the first element from right that is smaller than its next element
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        
        // If no such element found, it's the last permutation
        // Reverse the array to get the first permutation
        if (ind == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest element greater than nums[ind] to its right
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                // Step 3: Swap the found elements
                std::swap(nums[i], nums[ind]);
                break;
            }
        }
        
        // Step 4: Reverse the subarray after ind to get the smallest arrangement
        std::reverse(nums.begin()+1+ind, nums.end());
    }
};

int main() {
    std::ifstream inFile("/D:/Main/input.txt");
    std::ofstream outFile("/D:/Main/output.txt");
    
    int n;
    inFile >> n;
    
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        inFile >> nums[i];
    }
    
    // Output original array
    outFile << "Original array: ";
    for (int num : nums) {
        outFile << num << " ";
    }
    outFile << std::endl;
    
    // Find and output next permutation
    Solution solution;
    solution.nextPermutation(nums);
    
    outFile << "Next permutation: ";
    for (int num : nums) {
        outFile << num << " ";
    }
    outFile << std::endl;
    
    inFile.close();
    outFile.close();
    
    std::cout << "Next permutation has been computed and saved to output.txt" << std::endl;
    
    return 0;
}
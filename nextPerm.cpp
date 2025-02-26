#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+1+ind, nums.end());
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
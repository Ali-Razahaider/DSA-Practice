#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

class Solution {
public:
    /**
     * Finds the length of the longest consecutive elements sequence.
     * 
     * @param nums Vector of integers
     * @return Length of longest consecutive sequence
     */
    int naivelongestConsecutive(std::vector<int>& nums) {
        // Create a map to store unique elements and their indices
        std::map<int, int> mp;
        
        // Handle empty or single element array cases
        if (nums.size() <= 1)
            return nums.size();
    
        // Insert all elements into the map (automatically sorted)
        for (int i = 0; i < nums.size(); i++) {
            mp.insert({nums[i], i});
        }
        
        int cnt = 1;  // Current sequence length
        int lar = 1;  // Largest sequence length found
        
        // Iterate through the sorted map to find consecutive sequences
        for (auto i = std::next(mp.begin()); i != mp.end(); i++) {
            // If current element is consecutive to previous element
            if (i->first - 1 == std::prev(i)->first) {
                cnt++; // Increment current sequence length
            } else {
                // Sequence broken, update largest sequence if needed
                lar = std::max(lar, cnt);
                cnt = 1; // Reset current sequence length
            }
        }
        
        // Return the maximum of current and largest sequence length
        return std::max(lar, cnt);
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
    
    // Find and output longest consecutive sequence length
    Solution solution;
    int result = solution.naivelongestConsecutive(nums);
    
    outFile << "Longest consecutive sequence length: " << result << std::endl;
    
    inFile.close();
    outFile.close();
    
    std::cout << "Longest consecutive sequence has been computed and saved to output.txt" << std::endl;
    
    return 0;
}
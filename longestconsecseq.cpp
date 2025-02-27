#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <fstream>

class Solution {
public:
    /**
     * Optimized approach using unordered_set with O(n) time complexity.
     * Only starts counting sequences from their starting points.
     * 
     * @param nums Vector of integers
     * @return Length of longest consecutive sequence
     */
    int longestConsecutive(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int lar = 1;
        std::unordered_set<int> st;
        
        // Insert all elements into the set
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        // Only check sequences from their starting points
        for (auto i : st) {
            // If this is a starting point of a sequence (no left neighbor)
            if (st.find(i - 1) == st.end()) {
                int cnt = 1;
                int x = i;

                // Count consecutive elements
                while (st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }
                lar = std::max(cnt, lar);
            }
        }
        return lar;
    }

    /**
     * Naive approach using sorted map with O(n log n) time complexity.
     * Uses a map to sort elements and then counts consecutive sequences.
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
    std::ofstream outFile("/D:/Main/output.txt", std::ios_base::app); // Append to existing output file
    
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
    
    // Find and output longest consecutive sequence length using both methods
    Solution solution;
    int naiveResult = solution.naivelongestConsecutive(nums);
    int optimizedResult = solution.longestConsecutive(nums);
    
    outFile << "Longest consecutive sequence length (naive): " << naiveResult << std::endl;
    outFile << "Longest consecutive sequence length (optimized): " << optimizedResult << std::endl;
    
    inFile.close();
    outFile.close();
    
    std::cout << "Longest consecutive sequence has been computed and saved to output.txt" << std::endl;
    
    return 0;
}
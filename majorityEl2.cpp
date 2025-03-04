#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to find all elements that appear more than ⌊ n/3 ⌋ times in the array
    // Time Complexity: O(n), Space Complexity: O(n)
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> res; // Map to store element counts
        vector<int> rr; // Vector to store result
        int n = nums.size();
        double th = n / 3; // Threshold: n/3

        // Count occurrences of each element
        for (int i = 0; i < nums.size(); i++) {
            res[nums[i]]++;
        }

        // Check which elements exceed the threshold
        for (auto i : res) {
            if (double(i.second) > th)
                rr.push_back(i.first);
        }
        return rr;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Test cases
    vector<vector<int>> testCases = {
        {3, 2, 3},            // Expected: [3]
        {1},                  // Expected: [1]
        {1, 2},               // Expected: [1, 2]
        {2, 2, 1, 1, 1, 2, 2} // Expected: [1, 2]
    };
    
    // Process each test case
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        
        // Print input array
        cout << "Input: [";
        for (int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i][j];
            if (j < testCases[i].size() - 1) cout << ", ";
        }
        cout << "], ";
        
        // Get and print result
        vector<int> result = sol.majorityElement(testCases[i]);
        cout << "Output: [";
        for (int j = 0; j < result.size(); j++) {
            cout << result[j];
            if (j < result.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    // Custom input
    int n;
    cout << "\nEnter the size of your custom array: ";
    cin >> n;
    
    vector<int> customArray(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> customArray[i];
    }
    
    vector<int> customResult = sol.majorityElement(customArray);
    cout << "Elements appearing more than n/3 times: [";
    for (int j = 0; j < customResult.size(); j++) {
        cout << customResult[j];
        if (j < customResult.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
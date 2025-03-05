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

    // The second approach uses Boyer-Moore Voting Algorithm
    // Time Complexity: O(n), Space Complexity: O(1)
    vector<int> majorityElement2(vector<int>& nums) {
        vector<int> maj;
        int cnt = 0;
        int cnt1 = 0;
        int cand = -1;
        int cand2 = -1;
        vector<int> majority;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == cand)
                cnt++;
            else if (nums[i] == cand2)
                cnt1++;
            else if (cnt1 == 0) {
                cand2 = nums[i];
                cnt1 = 1;
            } else if (cnt == 0) {
                cand = nums[i];
                cnt = 1;
            } else {
                cnt--;
                cnt1--;
            }
        }
        cnt = cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == cand)
                cnt++;
            else if (nums[i] == cand2)
                cnt1++;
        }
        if (cnt > n / 3)
            maj.push_back(cand);

        if (cnt1 > n / 3)
            maj.push_back(cand2);
        return maj;
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
    
    // Process each test case with both methods
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        
        // Print input array
        cout << "Input: [";
        for (int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i][j];
            if (j < testCases[i].size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        // Get and print result for method 1
        vector<int> result1 = sol.majorityElement(testCases[i]);
        cout << "  Method 1 Output: [";
        for (int j = 0; j < result1.size(); j++) {
            cout << result1[j];
            if (j < result1.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        // Get and print result for method 2
        vector<int> result2 = sol.majorityElement2(testCases[i]);
        cout << "  Method 2 Output: [";
        for (int j = 0; j < result2.size(); j++) {
            cout << result2[j];
            if (j < result2.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        // Compare results
        bool resultsMatch = (result1.size() == result2.size());
        if (resultsMatch) {
            unordered_map<int, int> elementCount;
            for (int num : result1) elementCount[num]++;
            for (int num : result2) elementCount[num]--;
            for (auto& pair : elementCount) {
                if (pair.second != 0) {
                    resultsMatch = false;
                    break;
                }
            }
        }
        cout << "  Results match: " << (resultsMatch ? "Yes" : "No") << endl << endl;
    }
    
    // Custom input
    int n;
    cout << "Enter the size of your custom array: ";
    cin >> n;
    
    vector<int> customArray(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> customArray[i];
    }
    
    // Test both methods with custom input
    vector<int> customResult1 = sol.majorityElement(customArray);
    cout << "Method 1 - Elements appearing more than n/3 times: [";
    for (int j = 0; j < customResult1.size(); j++) {
        cout << customResult1[j];
        if (j < customResult1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    vector<int> customResult2 = sol.majorityElement2(customArray);
    cout << "Method 2 - Elements appearing more than n/3 times: [";
    for (int j = 0; j < customResult2.size(); j++) {
        cout << customResult2[j];
        if (j < customResult2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    // Compare execution time (optional)
    cout << "\nNote: Method 1 uses a hashmap approach (O(n) time, O(n) space)" << endl;
    cout << "      Method 2 uses Boyer-Moore Voting Algorithm (O(n) time, O(1) space)" << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

/*
 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
 * If target is not found in the array, return [-1, -1].
 * You must write an algorithm with O(log n) runtime complexity.
 */

class Solution {
public:
    // Method to find the range of a target value in a sorted array
    vector<int> searchRange(vector<int>& arr, int x) {
        int start = -1, end = -1;
    
        int n = arr.size();
        int low = 0;
        int high = n - 1;
    
        while (low <= high) {
            int mid = (low + high) / 2;
    
            if (arr[mid] > x) {
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                if(start == -1) start = mid;
                else end = mid;
                low = mid + 1;
                // Commented code removed for clarity
            }
        }
            
        return {start, end};
    }

    // Find the first occurrence of target using binary search
    int firstOccur(vector<int>& arr, int x) {
        int start = -1;
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > x) {
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                start = mid;
                high = mid - 1;  // Look in left half for earlier occurrence
            }
        }
        return start;
    }
    
    // Find the last occurrence of target using binary search
    int lastOccur(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int end = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
    
            if (arr[mid] > x) {
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                end = mid;
                low = mid + 1;  // Look in right half for later occurrence
            }
        }
        return end;
    }

    // Optimized method that directly calls firstOccur and lastOccur
    vector<int> searchRanger(vector<int>& arr, int x) {
        int start = firstOccur(arr, x);
        int end = lastOccur(arr, x);
    
        return {start, end};
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Test cases
    vector<vector<int>> testArrays = {
        {5, 7, 7, 8, 8, 10},
        {5, 7, 7, 8, 8, 10},
        {1},
        {},
        {1, 1, 1, 1, 1, 1},
        {1, 2, 3, 3, 3, 3, 4, 5, 6}
    };
    
    vector<int> targets = {8, 6, 1, 0, 1, 3};
    
    cout << "Finding ranges of target values in sorted arrays:\n";
    cout << "-------------------------------------------------\n";
    
    for (int i = 0; i < testArrays.size(); i++) {
        cout << "Test Case " << (i + 1) << ":\n";
        cout << "Array: [";
        for (int j = 0; j < testArrays[i].size(); j++) {
            cout << testArrays[i][j];
            if (j < testArrays[i].size() - 1) cout << ", ";
        }
        cout << "]\n";
        
        cout << "Target: " << targets[i] << "\n";
        
        // Using the optimized searchRanger method
        vector<int> result = sol.searchRanger(testArrays[i], targets[i]);
        
        cout << "Range: [" << result[0] << ", " << result[1] << "]\n\n";
    }
    
    return 0;
}


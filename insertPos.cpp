#include <iostream>
#include <vector>
using namespace std;
/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
    public:
        /**
         * Search Insert Position
         * Given a sorted array and a target value, return the index where the target
         * should be inserted if it's not found in the array.
         * 
         * Time Complexity: O(log n) - Binary search approach
         * Space Complexity: O(1) - Constant extra space
         * 
         * @param arr Sorted array of integers
         * @param x Target value to find or insert
         * @return Index where x is found or should be inserted
         */
        int searchInsert(vector<int>& arr, int x) {
            int ind = -1;
            int n = arr.size();
    
            int low = 0, high = n - 1;
    
            while (low <= high) {
                int mid = (low + high) / 2;
    
                if (arr[mid] == x) {
                    // Target found, return current position
                    ind = mid;
                    break;
                } else if (arr[mid] > x) {
                    // Target should be in left half
                    high = mid - 1;
    
                } else if (arr[mid] < x) {
                    // Target should be in right half
                    low = mid + 1;
                } 
            }
            // If target not found, insertion position is at 'low'
            if(ind == -1) ind = low;
            return ind;
        }
};

// Driver code
int main() {
    Solution sol;
    
    // Test cases
    vector<int> test1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Input Array: [1, 3, 5, 6], Target: " << target1 << endl;
    cout << "Output: " << sol.searchInsert(test1, target1) << endl; // Expected: 2
    
    vector<int> test2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Input Array: [1, 3, 5, 6], Target: " << target2 << endl;
    cout << "Output: " << sol.searchInsert(test2, target2) << endl; // Expected: 1
    
    vector<int> test3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Input Array: [1, 3, 5, 6], Target: " << target3 << endl;
    cout << "Output: " << sol.searchInsert(test3, target3) << endl; // Expected: 4
    
    vector<int> test4 = {1, 3, 5, 6};
    int target4 = 0;
    cout << "Input Array: [1, 3, 5, 6], Target: " << target4 << endl;
    cout << "Output: " << sol.searchInsert(test4, target4) << endl; // Expected: 0
    
    return 0;
}
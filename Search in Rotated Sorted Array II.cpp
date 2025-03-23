/*There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool search(vector<int>& arr, int x) {
            bool flag = false;
    
            int n = arr.size();
            int low = 0;
            int high = n - 1;
    
            while (low <= high) {
                int mid = (low + high) / 2;
    
                if (arr[mid] == x) {
                    flag = true;
                    break;
                } else if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                    // Handle duplicates by narrowing the search window
                    low++;
                    high--;
                    continue;
                } else if (arr[low] <= arr[mid]) {
                    // Left half is sorted
                    if (arr[low] <= x && arr[mid] > x) {
                        high = mid - 1;
                    } else
                        low = mid + 1;
                } else if (arr[mid] < x && x <= arr[high]) {
                    // Right half is sorted and target is in right half
                    low = mid + 1;
                } else
                    high = mid - 1;
            }
            return flag;
        }
};

// Driver code
int main() {
    Solution sol;
    
    // Test case 1: Target exists in array
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Test case 1: ";
    if (sol.search(nums1, target1)) {
        cout << target1 << " found in the array" << endl;
    } else {
        cout << target1 << " not found in the array" << endl;
    }
    
    // Test case 2: Target doesn't exist in array
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Test case 2: ";
    if (sol.search(nums2, target2)) {
        cout << target2 << " found in the array" << endl;
    } else {
        cout << target2 << " not found in the array" << endl;
    }
    
    // Test case 3: Array with duplicates
    vector<int> nums3 = {2, 5, 6, 0, 0, 1, 2};
    int target3 = 0;
    cout << "Test case 3: ";
    if (sol.search(nums3, target3)) {
        cout << target3 << " found in the array" << endl;
    } else {
        cout << target3 << " not found in the array" << endl;
    }
    
    return 0;
}
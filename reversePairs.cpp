/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Main function that starts the merge sort process
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
    
    // Recursive function to perform merge sort and count reverse pairs
    int mergeSort(vector<int>& arr, int low, int high) {
        // Base case: If we have 0 or 1 element, no pairs to count
        if (low >= high) 
            return 0;
            
        int cnt = 0;
        int mid = (low + high) / 2;
        
        // Count pairs in left and right halves recursively
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        
        // Count pairs across left and right halves
        cnt += count(arr, low, mid, high);
        
        // Merge the two sorted halves
        merge(arr, low, mid, high);
        return cnt;
    }
    
    // Function to merge two sorted subarrays
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        
        // Merge elements in sorted order
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }
        
        // Add remaining elements from left subarray
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }
        
        // Add remaining elements from right subarray
        while (right <= high) {
            temp.push_back(arr[right++]);
        }
        
        // Copy sorted elements back to the original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    
    // Function to count reverse pairs between left and right subarrays
    int count(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        
        // For each element in left subarray, find elements in right subarray
        // that satisfy the condition: arr[i] > 2 * arr[j]
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) {
                right++;
            }
            // Add the count of valid pairs
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 3, 2, 3, 1};
    cout << "Example 1: [1,3,2,3,1]" << endl;
    cout << "Reverse pairs: " << sol.reversePairs(nums1) << endl;  // Expected output: 2
    
    // Example 2
    vector<int> nums2 = {2, 4, 3, 5, 1};
    cout << "Example 2: [2,4,3,5,1]" << endl;
    cout << "Reverse pairs: " << sol.reversePairs(nums2) << endl;  // Expected output: 3
    
    // Example 3
    vector<int> nums3 = {5, 4, 3, 2, 1};
    cout << "Example 3: [5,4,3,2,1]" << endl;
    cout << "Reverse pairs: " << sol.reversePairs(nums3) << endl;  // Expected output: 4
    
    // Custom test cases
    cout << "\nEnter the size of array: ";
    int n;
    cin >> n;
    
    vector<int> customArray(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> customArray[i];
    }
    
    cout << "Number of reverse pairs: " << sol.reversePairs(customArray) << endl;
    
    return 0;
}
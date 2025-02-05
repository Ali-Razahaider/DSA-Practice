/*Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;  // Input the number of elements

    vector<int> nums(n);
    cout << "Enter the elements of the vector: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];  // Input the elements of the vector
    }

    Solution sol;
    bool result = sol.check(nums);  // Check if the array is sorted and rotated

    if(result) {
        cout << "The array is sorted and rotated." << endl;
    } else {
        cout << "The array is not sorted and rotated." << endl;
    }

    return 0;
}

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;  // Count the number of drops in the array
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1] && drops < 2) {
                drops++;  // Increment drops if current element is greater than next
            }
        }
        if(drops > 1) return false;  // More than one drop means not sorted and rotated
        else if(drops == 0) return true;  // No drops means already sorted
        else {
            return (nums[0] >= nums[n-1]);  // Check if the array is rotated
        }
    }
};
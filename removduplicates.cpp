#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int k = 0;
            int i = 0;
            while(i < nums.size()-1){
                int j = i;
                while(nums[i] == nums[j+1] && j+1 < nums.size()){
                    j++;
                }
                swap(nums[i+1], nums[j+1]);
                i = j+1;
                k++;
            }
            return k;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int k = sol.removeDuplicates(nums);
    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
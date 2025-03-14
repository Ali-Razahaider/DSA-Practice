/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            vector<int> newvec(nums.size());
            int n = nums.size();
            for (int i = 0; i < nums.size(); i++) {
                newvec[(i + k) % n] = nums[i];
            }
            for (int i = 0; i < n; i++) {
                nums[i] = newvec[i];
            }
        }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    sol.rotate(nums, k);
    cout << "Array after rotating by " << k << " steps: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
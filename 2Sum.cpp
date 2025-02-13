#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> prefixSum;
            for (int i = 0; i < nums.size(); i++) {
                int rem = target - nums[i];
                auto x = prefixSum.find(rem);
                if (x != prefixSum.end()) {
                    return {i, x->second};
                }
                prefixSum[nums[i]] = i;
            }
            return {};
        }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices of the two numbers that add up to " << target << ": ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}
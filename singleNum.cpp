#include <iostream>
#include <vector>

using namespace std;

/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int x = 0;
            for(int i = 0; i < nums.size(); i++){
                x ^= nums[i];
            }
            return x;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    int single = sol.singleNumber(nums);
    cout << "Single number: " << single << endl;
    return 0;
}
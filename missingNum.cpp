#include <iostream>
#include <vector>

using namespace std;

/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            vector<int> num(n + 1, -1);
            int numm = 0;
            for (int i = 0; i < n; i++) {
                num[nums[i]]++;
            }
    
            for (int i = 0; i < n + 1; i++) {
                if (num[i] == -1) {
                    numm = i;
                    break;
                }
            }
            return numm;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1};
    int missing = sol.missingNumber(nums);
    cout << "Missing number: " << missing << endl;
    return 0;
}
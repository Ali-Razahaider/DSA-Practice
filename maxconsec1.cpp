#include <iostream>
#include <vector>

using namespace std;

/*Given a binary array nums, return the maximum number of consecutive 1's in the array.*/

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int max = 0;
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i]) {
                    count++;
                } else {
                    count = 0;
                }
                max = std::max(count, max);
            }
            return max;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int maxConsecutiveOnes = sol.findMaxConsecutiveOnes(nums);
    cout << "Maximum number of consecutive 1's: " << maxConsecutiveOnes << endl;
    return 0;
}
/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int count1 = 0;
            int count2 = 0;
            int count3 = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0)
                    count1++;
                if (nums[i] == 1)
                    count2++;
                if (nums[i] == 2)
                    count3++;
            }
    
            for (int i = 0; i < count1; i++) {
                nums[i] = 0;
            }
    
            for (int i = count1; i < count1 + count2; i++) {
                nums[i] = 1;
            }
    
            for (int i = count1 + count2; i < nums.size(); i++) {
                nums[i] = 2;
            }
        }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    solution.sortColors(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
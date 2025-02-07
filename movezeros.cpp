#include <iostream>
#include <vector>

using namespace std;

/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n = nums.size();
            vector<int> narr;
            int k = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    k++;
                }
                if (nums[i] != 0) {
                    narr.push_back(nums[i]);
                }
            }
            for(int i = 0 ; i < k; i++){
                narr.push_back(0);
            }
            for(int i = 0 ; i < n; i++){
                nums[i] = narr[i];
            }
        }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    cout << "Array after moving zeros: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
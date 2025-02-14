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
        // Method 1: Two-pass solution using counting sort
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

        // Method 2: Optimal approach using Dutch National Flag algorithm
        void sortColorsOptimal(vector<int>& nums) {
            int s = 0;
            int n = nums.size();
            int j = n - 1;
            int mid = 0;
    
            while (mid <= j) {
                if (nums[mid] == 0) {
                    swap(nums[mid], nums[s]);
                    mid++;
                    s++;
                } else if (nums[mid] == 1) {
                    mid++;
                } else if (nums[mid] == 2) {
                    swap(nums[mid], nums[j]);
                    j--;
                }
            }
        }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    vector<int> nums(n);
   
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Test Method 1: Two-pass solution using counting sort
    solution.sortColors(nums);
    cout << "After Counting Sort Method: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Reset the array for the next test
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Test Method 2: Optimal approach using Dutch National Flag algorithm
    solution.sortColorsOptimal(nums);
    cout << "After Dutch National Flag Method: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
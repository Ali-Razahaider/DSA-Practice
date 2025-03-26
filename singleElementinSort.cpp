/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int singleNonDuplicate(vector<int>& arr) {
    
            int n = arr.size();
            if (n == 1)
                return arr[0];
            int low = 0;
            int high = n - 1;
            int ans = -1;
            while (low <= high) {
                if (low + 1 <= high - 1 && arr[low] == arr[low + 1] &&
                    arr[high] == arr[high - 1]) {
                    low += 2;
                    high -= 2;
                } else if (arr[low] != arr[low + 1]) {
                    ans = arr[low];
                    break;
                } else if (arr[high] != arr[high - 1]) {
                    ans = arr[high];
                    break;
                }
            }
            return ans;
        }
};

int main() {
    Solution solution;

    // Test case 1: Array with one single non-duplicate element
    vector<int> arr1 = {1, 1, 2, 2, 3, 4, 4};
    cout << "Test case 1: The single non-duplicate element is: " << solution.singleNonDuplicate(arr1) << endl;

    // Test case 2: Array with single element
    vector<int> arr2 = {7};
    cout << "Test case 2: The single non-duplicate element is: " << solution.singleNonDuplicate(arr2) << endl;

    // Test case 3: Array with single non-duplicate element at the end
    vector<int> arr3 = {1, 1, 2, 2, 3};
    cout << "Test case 3: The single non-duplicate element is: " << solution.singleNonDuplicate(arr3) << endl;

    return 0;
}
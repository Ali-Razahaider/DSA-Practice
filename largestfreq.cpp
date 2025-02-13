/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            double n = nums.size() / 2;
            int size = nums.size();
            unordered_map<int, int> map;
            for (int i = 0; i < nums.size(); i++) {
                map[nums[i]]++;
            }
            int lar = 0;
            for (int j = 0; j < size; j++) {
                auto x = map.find(nums[j]);
                if ((x != map.end()) && (x->second) > n) {
                    lar = nums[j];
                }
            }
            return lar;
        }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "The majority element is: " << solution.majorityElement(nums) << endl;
    return 0;
}
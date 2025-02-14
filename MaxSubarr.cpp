#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.*/

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            if (nums.size() == 1)
                return nums[0];
            int sum = 0;
            int maxq = nums[0];
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if (sum > maxq) {
                    maxq = sum;
                }  
                if (sum < 0) {
                    sum = 0;
                }
            }
            return maxq;
        }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int n;
    inputFile >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        inputFile >> nums[i];
    }
    Solution sol;
    int result = sol.maxSubArray(nums);
    outputFile << result << endl;
    inputFile.close();
    outputFile.close();
    return 0;
}
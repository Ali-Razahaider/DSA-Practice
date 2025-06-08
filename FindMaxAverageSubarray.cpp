/*
Question:
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. Return this value.

Pattern Used: Sliding Window
*/

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Returns the maximum average of any contiguous subarray of length k.
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = INT_MIN;
        double windowStart = 0;
        int start = 0;
        int windowSum = 0;
        for (int windowStart = 0; windowStart < nums.size(); windowStart++) {
            windowSum += nums[windowStart];

            if (windowStart >= k - 1) {
                avg = max(avg, windowSum / (double)k);
                windowSum -= nums[start];
                start++;
            }
        }
        return avg;
    }
};

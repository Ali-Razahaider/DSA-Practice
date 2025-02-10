/*
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<int, int> prefixSum;
        int n = arr.size();
        int sum = 0;
        int maxlen = 0;
        prefixSum[0] = -1;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            long long rem = sum - k;
            if(prefixSum.find(rem) != prefixSum.end()) {
                int len = i - prefixSum[rem];
                maxlen = max(maxlen, len);
            }
            if(prefixSum.find(sum) == prefixSum.end()) {
                prefixSum[sum] = i;
            }
        }
        return maxlen;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 7, 5};
    int k = 12;
    int result = solution.longestSubarray(arr, k);
    cout << "Length of the longest subarray with sum " << k << ": " << result << endl;
    return 0;
}
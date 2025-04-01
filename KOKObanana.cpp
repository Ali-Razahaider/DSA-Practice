/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.


Input: piles = [3,6,7,11], h = 8
Output: 4
*/

class Solution {
    public:
        int minEatingSpeed(vector<int>& arr, int h) {
            int n = arr.size();
            int maxel = *max_element(arr.begin(), arr.end());
            // returns the iterator to the max
            // element deref it to the value
            int low = 1;
            int ans = 0;
    
            while (low <= maxel) {
                int mid = low + (maxel - low) / 2;
    
                long long hr = 0;
                for (int val : arr) {
                    hr += (val + mid - 1) / mid;
                }
                if (hr <= h) {
                    ans = mid;
                    maxel = mid - 1;
    
                } else {
                    low = mid + 1;
                }
            }
            return ans;
        }
    };
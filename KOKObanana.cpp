/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.


Input: piles = [3,6,7,11], h = 8
Output: 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        // Step 1: Find the maximum number of bananas in any pile
        // This will be our upper bound for binary search
        int n = arr.size();
        int maxel = *max_element(arr.begin(), arr.end());
        
        // Step 2: Initialize binary search boundaries
        // The minimum eating speed is 1 banana per hour
        // The maximum eating speed needed is the largest pile (worst case)
        int low = 1;
        int ans = 0;

        // Step 3: Perform binary search to find minimum eating speed
        while (low <= maxel) {
            // Calculate mid-point as potential eating speed (k)
            int mid = low + (maxel - low) / 2;
            
            // Step 4: Calculate hours needed at current speed (mid)
            long long hr = 0;
            for (int val : arr) {
                // Formula: ceil(pile_size / speed) = (pile_size + speed - 1) / speed
                // This gives us the hours needed to eat this pile at speed 'mid'
                hr += (val + mid - 1) / mid;
            }
            
            // Step 5: Check if current speed is sufficient
            if (hr <= h) {
                // If we can finish eating in time, this could be our answer
                // But we want the minimum, so we continue searching in lower half
                ans = mid;
                maxel = mid - 1;
            } else {
                // If we can't finish in time, we need to increase our eating speed
                low = mid + 1;
            }
        }
        // Return the minimum valid eating speed
        return ans;
    }
};

// Driver code to test the solution
int main() {
    Solution solution;
    
    // Test case 1: Example from problem description
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Example 1: Minimum eating speed = " << solution.minEatingSpeed(piles1, h1) << endl;
    // Expected output: 4
    
    // Test case 2: Another example
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Example 2: Minimum eating speed = " << solution.minEatingSpeed(piles2, h2) << endl;
    // Expected output: 30
    
    // Test case 3: More piles than hours (must eat multiple piles per hour)
    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    cout << "Example 3: Minimum eating speed = " << solution.minEatingSpeed(piles3, h3) << endl;
    // Expected output: 23
    
    return 0;
}
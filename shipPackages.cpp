class Solution {
    public:
        int calchigh(vector<int>& arr, int n) {
            int sum = 0;
            for (auto i : arr) {
                sum += i;
            }
            return sum;
        }
        int shipWithinDays(vector<int>& arr, int days) {
            int n = arr.size();
            int ans = 0;
            int low = *max_element(arr.begin(), arr.end());
            int high = calchigh(arr, n); // maximum capacity for the ship
            while (low <= high) {
                int mid = (low + high) / 2;
                int daycount = 1;
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    if (sum + arr[i] <= mid) {
                        sum += arr[i];
                    } else {
                        sum = arr[i];
                        daycount++;
                    }
                }
    
                if (daycount <= days) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return ans;
        }
    };
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& arr) {
            int n = arr.size();
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    swap(arr[i][j], arr[j][i]);
                }
            }
    
            for (int i = 0; i < n; i++) {
                reverse(arr[i].begin(), arr[i].end());
            }
        }
};

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution().rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "\n";
    }

}

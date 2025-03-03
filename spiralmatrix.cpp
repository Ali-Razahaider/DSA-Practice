#include <iostream>
#include <vector>

using namespace std;

/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> res;
            int n = matrix.size();
            int m = matrix[0].size();
            int left = 0;
            int right = m - 1;
            int bottom = n - 1;
            int top = 0;
    
            while (top <= bottom && left <= right) {
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[top][i]);
                }
                top++;
                for (int i = top; i <= bottom; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--;
                if (top <= bottom) {
                    for (int i = right; i >= left; i--) {
                        res.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                }
                if (left <= right) {
                    for (int i = bottom; i >= top; i--) {
                        res.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
            return res;
        }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
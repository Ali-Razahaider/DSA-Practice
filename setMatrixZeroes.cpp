#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
    
            vector<int> row(n, 0);
            vector<int> col(m, 0);
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == 0) {
                        row[i] = 1;
                        col[j] = 1;
                    }
                }
            }
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (row[i] || col[j]) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
};

// Driver code
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    sol.setZeroes(matrix);

    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
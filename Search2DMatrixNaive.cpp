#include <vector>
using namespace std;

// Naive approach to search for a target in a 2D matrix.
// The function attempts to use a binary search-like logic but is not optimal for all cases.
class Solution {
public:
    // Returns true if target is found in matrix, else false.
    bool naiveApproach(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int rowL = 0, colL = 0;
        int rowR = rows - 1, colR = cols - 1;
        bool ans = false;

        // Special case: single element matrix
        if (rows == 1 && cols == 1) {
            return matrix[0][0] == target;
        }

        // Attempt to search using a modified binary search
        while (rowL <= rowR && colL <= colR) {
            int rowmid = (rowR + rowL) >> 1;
            int colmid = (colL + colR) >> 1;

            // Check if the middle element is the target
            if (matrix[rowmid][colmid] == target) {
                ans = true;
                break;
            }

            // If middle element is greater than target, adjust search space
            if (matrix[rowmid][colmid] > target) {
                if (matrix[rowmid][0] > target) {
                    rowR = rowmid - 1;
                } else {
                    colR = colmid - 1;
                }
            }
            // If middle element is less than target, adjust search space
            else if (matrix[rowmid][colmid] < target) {
                if (matrix[rowmid][cols - 1] < target) {
                    rowL = rowmid + 1;
                } else {
                    colL = colmid + 1;
                }
            }
        }
        return ans;
    }

    // Optimized approach: Treat the 2D matrix as a 1D sorted array and apply binary search.
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        // Check for empty matrix
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int high = (rows * cols) - 1;
        bool ans = false;

        while (low <= high) {
            int mid = (low + high) >> 1;
            int r = mid / cols; // Row index in 2D matrix
            int c = mid % cols; // Column index in 2D matrix
            if (matrix[r][c] == target) {
                ans = true;
                break;
            }
            if (matrix[r][c] > target) {
                high = mid - 1;
            } else if (matrix[r][c] < target) {
                low = mid + 1;
            }
        }
        return ans;
    }
};

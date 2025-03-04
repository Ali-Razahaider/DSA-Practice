#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/**
 * Solution class to generate Pascal's Triangle
 * Pascal's Triangle is a triangular array where each number is the sum of the two numbers above it
 */
class Solution {
public:
    /**
     * Generate Pascal's Triangle up to numRows
     * @param numRows Number of rows to generate
     * @return 2D vector containing Pascal's Triangle
     */
    vector<vector<int>> generate(int numRows) {
        // Initialize result vector
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        
        // First row is always [1]
        res.push_back({1});
        
        // Generate subsequent rows
        for (int i = 1; i < numRows; i++) {
            // Each row starts and ends with 1
            vector<int> row(i + 1, 1);
            
            // Calculate middle elements using the previous row
            for (int j = 1; j < i; j++) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            
            // Add the completed row to result
            res.push_back(row);
        }
        return res;
    }
};

int main() {
    // Open input file
    ifstream inputFile("/D:/Main/input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file" << endl;
        return 1;
    }
    
    // Read number of rows
    int numRows;
    inputFile >> numRows;
    inputFile.close();
    
    // Generate Pascal's Triangle
    Solution solution;
    vector<vector<int>> pascalTriangle = solution.generate(numRows);
    
    // Open output file
    ofstream outputFile("/D:/Main/output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening output file" << endl;
        return 1;
    }
    
    // Write title to output file
    outputFile << "Pascal's Triangle" << endl;
    
    // Write triangle to output file
    for (const auto& row : pascalTriangle) {
        for (int num : row) {
            outputFile << num << " ";
        }
        outputFile << endl;
    }
    
    outputFile.close();
    
    // Display on console as well
    cout << "Pascal's Triangle with " << numRows << " rows generated successfully." << endl;
    for (const auto& row : pascalTriangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
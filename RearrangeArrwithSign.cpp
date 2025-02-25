/*
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:
    // Optimal solution using O(1) extra space
    vector<int> optimalRearrange(vector<int>& nums) {
        int pos = 0;
        int neg = 1;
        int n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                ans[neg] = nums[i];
                neg += 2;
            } else {
                ans[pos] = nums[i];
                pos += 2;
            }
        }
        return ans;
    }
    
    // Brute force solution using additional space
    vector<int> bruteRearrange(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }
            else if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
        }
        
        int posin = 0;
        int negin = 0;
        vector<int> result = nums; // Create a copy to preserve original array
        
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                result[i] = pos[posin++];
            } else {
                result[i] = neg[negin++];
            }
        }
        return result;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Read input from file
    ifstream inputFile("/d:/Main/input.txt");
    
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file" << endl;
        return 1;
    }
    
    int n;
    inputFile >> n; // Read the size of the array
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        inputFile >> nums[i]; // Read array elements
    }
    
    inputFile.close();
    
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    // Test optimal solution
    vector<int> optimalResult = sol.optimalRearrange(nums);
    cout << "Optimal solution result: ";
    for (int num : optimalResult) {
        cout << num << " ";
    }
    cout << endl;
    
    // Test brute force solution
    vector<int> bruteResult = sol.bruteRearrange(nums);
    cout << "Brute force solution result: ";
    for (int num : bruteResult) {
        cout << num << " ";
    }
    cout << endl;
    
    // Write results to output file
    ofstream outputFile("/d:/Main/output.txt");
    if (outputFile.is_open()) {
        outputFile << "Original array: ";
        for (int num : nums) {
            outputFile << num << " ";
        }
        outputFile << endl;
        
        outputFile << "Optimal solution result: ";
        for (int num : optimalResult) {
            outputFile << num << " ";
        }
        outputFile << endl;
        
        outputFile << "Brute force solution result: ";
        for (int num : bruteResult) {
            outputFile << num << " ";
        }
        outputFile << endl;
        
        outputFile.close();
        cout << "Results written to output.txt" << endl;
    } else {
        cerr << "Error: Unable to open output file" << endl;
    }
    
    return 0;
}
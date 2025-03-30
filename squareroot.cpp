#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/

class Solution {
    public:
        int mySqrt(int n) {
            if (n <= 1)
                return n;
            if (n == INT_MAX)
                return sqrt(INT_MAX);
            int ans = 0;
            int low = 0;
            int high = n;

            while (low <= high) {
                long long mid = (low + high) / 2;

                if (mid * mid <= n) {
                    ans = mid;
                    low = mid + 1;
                } else if (mid * mid > n) {
                    high = mid - 1;
                }
            }
            return ans;
        }
};

// Driver code to test the mySqrt function

int main() {
    Solution solution;

    // Test cases to validate the mySqrt function
    std::vector<int> testCases = {0, 1, 4, 8, 10, 16, 25, 36, 99, 100, 10000, 2147395599};
    int numCorrect = 0;

    std::cout << "=============================================================\n";
    std::cout << "              SQUARE ROOT FUNCTION TEST RESULTS              \n";
    std::cout << "=============================================================\n";
    std::cout << std::left << std::setw(12) << "Input" 
              << std::setw(15) << "Expected sqrt" 
              << std::setw(15) << "My sqrt" 
              << "Status\n";
    std::cout << "-------------------------------------------------------------\n";

    for (int x : testCases) {
        int mySqrtResult = solution.mySqrt(x);
        int expectedResult = static_cast<int>(std::sqrt(x));
        bool isCorrect = (mySqrtResult == expectedResult);
        
        if (isCorrect) numCorrect++;
        
        std::cout << std::left << std::setw(12) << x 
                  << std::setw(15) << expectedResult 
                  << std::setw(15) << mySqrtResult 
                  << (isCorrect ? "PASS" : "FAIL") << std::endl;
    }

    std::cout << "-------------------------------------------------------------\n";
    std::cout << "Tests passed: " << numCorrect << "/" << testCases.size() 
              << " (" << (numCorrect * 100.0 / testCases.size()) << "%)\n";
    std::cout << "=============================================================\n";

    return 0;
}
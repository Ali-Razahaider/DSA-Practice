#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for(int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt", ios::app);
    
    if (!inputFile.is_open()) {
        cout << "Error opening input file" << endl;
        return 1;
    }
    
    int n;
    inputFile >> n;
    vector<int> prices(n);
    
    for(int i = 0; i < n; i++) {
        inputFile >> prices[i];
    }
    
    Solution sol;
    int result = sol.maxProfit(prices);
    outputFile << "Best Time to Buy and Sell Stock Profit: " << result << endl;
    
    inputFile.close();
    outputFile.close();
    return 0;
}
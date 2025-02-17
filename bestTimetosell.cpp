#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int minS = INT_MAX;
            int maxS = INT_MIN;
            int buyind = 0;
            int sellind = 0;
            for (int i = 0; i < prices.size(); i++) {
                if (prices[i] < minS ) {
                    minS = prices[i];
                    buyind = i;
                }
            }
    
            for (int j = buyind; j < prices.size(); j++) {
                if (prices[j] > maxS) {
                    maxS = prices[j];
                    sellind = j;
                }
            }
    
            return (maxS - minS) > 0 ? (maxS - minS) : 0;
        }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt", ios::app);
    int n;
    inputFile >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        inputFile >> prices[i];
    }
    Solution sol;
    int result = sol.maxProfit(prices);
    outputFile << "Maximum Profit: " << result << endl;
    return 0;
}
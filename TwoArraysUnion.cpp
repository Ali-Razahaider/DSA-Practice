/*
Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
  public: 
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of element
        set<int>res;
        vector<int>num;
        for(int i = 0 ; i < a.size()||i<b.size();i++){
            if(i<a.size()){
                res.insert(a[i]);
            }
            if(i<b.size()){
                res.insert(b[i]);
            }
        }
        
        for(int i:res){
            num.push_back(i);
        }
        
        return num;
    
        
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 2, 4, 5, 6};
    vector<int> b = {2, 3, 5, 7};
    vector<int> result = sol.findUnion(a, b);
    cout << "Union of two arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
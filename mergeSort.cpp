/* 
Given an array arr[], its starting position l and its ending position r.
Sort the array using the merge sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if (l >= r) return;
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, r, mid);
        
    }
    
    void merge(vector<int>&Oarr,int l,int r,int mid){
        vector<int>arr;
        
        int left = l;
        int right = mid+1;
        
        while(left<=mid && right <=r){
            if(Oarr[left]<=Oarr[right]){
                arr.push_back(Oarr[left++]);
                
                
            }else {
                arr.push_back(Oarr[right]);
                right++;
            }
        }
        
        while(left<=mid){
           arr.push_back(Oarr[left]);
            left++;
        }
        
        while(right<=r){
            arr.push_back(Oarr[right]);
            
            right++;
        }
        
        for(int i = l; i <= r;i++){
            Oarr[i] = arr[i-l];
        }
        
        
        
    }
    
    
};

//{ Driver Code Starts.

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    obj.mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int>ans;
        
        unordered_map<int,int>map;
        
        for(int i=0 ; i < arr.size();i++){
            map[arr[i]]++;
        }
        int n =-1;
        int n2=-1;
        for(int i = 1 ;i<=arr.size();i++){
            if(map[i] == 0)n = i;
            else if(map[i]==2)n2 = i;
        }
        ans.push_back(n2);
        ans.push_back(n);
        return ans;
    }
    vector<int> findTwoElementoptimal(vector<int>& arr) {
        // code here
        int missing = -1;
        int rep = -1;
        for(int i = 0 ; i < arr.size();i++){
            int val = abs(arr[i]);
            if(arr[val-1]>0){
                arr[val-1] = -arr[val-1];
            }else rep = val;
        }
        
        for(int i = 0 ; i < arr.size();i++){
            if(arr[i]>0){
                missing = i+1;
            }
        }
        return{rep,missing};
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
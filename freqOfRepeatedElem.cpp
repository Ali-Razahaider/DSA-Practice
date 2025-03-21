/*
Problem: Given a sorted array arr[] and a target number x, find the frequency (number of occurrences)
of x in arr[].

Approach:
Since the array is sorted, we can use binary search to find the first and last occurrence of x.
The frequency will be: (last occurrence - first occurrence + 1)

Time Complexity: O(log n) - We perform two binary searches
Space Complexity: O(1) - Only using constant extra space
*/

#include <iostream>
#include <vector>
using namespace std;

int countFreq(vector<int>& arr, int x) {
    int start = -1;  // Will store the first occurrence of x
    int end = -1;    // Will store the last occurrence of x
    int n = arr.size();
    int low = 0;
    int high = n-1;
    
    // First binary search to find the first occurrence of x
    while(low <= high) {
        int mid = (low + high)/2;
        
        if(arr[mid] == x) {
            start = mid;          // Found a potential first occurrence
            high = mid - 1;       // Continue searching in left half
        } else if(arr[mid] > x) {
            high = mid - 1;       // Target is in left half
        } else {
            low = mid + 1;        // Target is in right half
        }
    }
    
    // If x is not found in array
    if (start == -1) return 0;
    
    // Second binary search to find the last occurrence of x
    low = 0;
    high = n-1;
    while(low <= high) {
        int mid = (low + high)/2;
        
        if(arr[mid] == x) {
            end = mid;            // Found a potential last occurrence
            low = mid + 1;        // Continue searching in right half
        } else if(arr[mid] > x) {
            high = mid - 1;       // Target is in left half
        } else {
            low = mid + 1;        // Target is in right half
        }
    }
    
    // Return the count of occurrences
    return end - start + 1;
}

// Driver code to test the implementation
int main() {
    // Test Case 1: Normal case with multiple occurrences
    vector<int> arr1 = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int x1 = 2;
    cout << "Test Case 1: Frequency of " << x1 << " is " << countFreq(arr1, x1) << endl;
    // Expected output: 4
    
    // Test Case 2: Element appears only once
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int x2 = 3;
    cout << "Test Case 2: Frequency of " << x2 << " is " << countFreq(arr2, x2) << endl;
    // Expected output: 1
    
    // Test Case 3: Element not present in array
    vector<int> arr3 = {1, 2, 3, 4, 5};
    int x3 = 6;
    cout << "Test Case 3: Frequency of " << x3 << " is " << countFreq(arr3, x3) << endl;
    // Expected output: 0
    
    // Test Case 4: All elements are same
    vector<int> arr4 = {2, 2, 2, 2, 2};
    int x4 = 2;
    cout << "Test Case 4: Frequency of " << x4 << " is " << countFreq(arr4, x4) << endl;
    // Expected output: 5
    
    // Test Case 5: Empty array
    vector<int> arr5;
    int x5 = 1;
    cout << "Test Case 5: Frequency of " << x5 << " is " << countFreq(arr5, x5) << endl;
    // Expected output: 0
    
    return 0;
}
}
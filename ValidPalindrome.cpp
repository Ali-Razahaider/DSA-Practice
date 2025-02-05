/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool palin(int i, int j, string &s) {
        if (i >= j)
            return true;
        if (!isalnum(s[i]))
            return palin(i + 1, j, s);
        else if (!isalnum(s[j]))
            return palin(i, j - 1, s);
        if (tolower(s[i]) == tolower(s[j]))
            return palin(i + 1, j - 1, s);
        else
            return false;
    }

    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        return palin(i, j, s);
    }
};

int main() {
    Solution solution;
    string s;
    getline(cin, s);
    if (solution.isPalindrome(s)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}

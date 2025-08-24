/**
    * Given a string s, return the longest palindromic substring in s.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkPal(string &s, int l, int h) {
        while(l < h) {
            if(s[l] != s[h]) return false;
            l++;
            h--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 1, start = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {   // ✅ fixed condition
                if(checkPal(s, i, j) && (j - i + 1) > maxLen) { // ✅ fixed function call
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl; // Output could be "bab" or "aba"
    cout << sol.longestPalindrome("cbbd") << endl; // Output "bb"
    return 0;
}


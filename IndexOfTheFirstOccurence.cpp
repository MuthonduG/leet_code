#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        // Get size of both strings
        int n = haystack.size();
        int m = needle.size();

        // Check needle length 
        if (m == 0) return 0; 
        if (m > n) return -1; 

        // Loop n - m times and return the initial index where substring begins
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i;
            }
        }
        return -1; 
    }
};

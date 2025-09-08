#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;
        long result = 0;
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;
            
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            
            i++;
        }
        
        return result * sign;
    }
};

int main() {
    Solution sol;
    string test1 = "42";
    string test2 = "   -42";
    string test3 = "4193 with words";
    string test4 = "words and 987";
    string test5 = "-91283472332";
    
    cout << "\"" << test1 << "\" -> " << sol.myAtoi(test1) << endl;
    cout << "\"" << test2 << "\" -> " << sol.myAtoi(test2) << endl;
    cout << "\"" << test3 << "\" -> " << sol.myAtoi(test3) << endl;
    cout << "\"" << test4 << "\" -> " << sol.myAtoi(test4) << endl;
    cout << "\"" << test5 << "\" -> " << sol.myAtoi(test5) << endl;
    
    return 0;
}
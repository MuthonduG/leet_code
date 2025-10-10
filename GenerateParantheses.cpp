#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& result, string combination, int open, int close, int max) {
        if (combination.length() == max * 2) {
            result.push_back(combination);
            return;
        }

        if (open < max)
            backtrack(result, combination + "(", open + 1, close, max);
        
        if (close < open)
            backtrack(result, combination + ")", open, close + 1, max);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0 || n > 8) return {};
        backtrack(result, "", 0, 0, n);
        return result;
    }
};


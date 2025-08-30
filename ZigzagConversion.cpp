#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
    * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
    * (you may want to display this pattern in a fixed font for better legibility)
    * Example 1:
        * Input: s = "PAYPALISHIRING", numRows = 3
        * Output: "PAHNAPLSIIGYIR"
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> arr(numRows);
        bool down = false;
        int row = 0;

        for (int i = 0; i < s.size(); i++) {
            arr[row].push_back(s[i]);

            if (row == 0 || row == numRows - 1)
                down = !down;

            row += (down ? 1 : -1);
        }

        string result;
        for (int i = 0; i < numRows; i++) {
            result += arr[i];
        }

        return result;
    }
};

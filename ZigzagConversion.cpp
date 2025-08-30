#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

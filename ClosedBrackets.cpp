#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> newStack;

        if (s.empty()) return false; 
        
        for (char character : s) {
            if (character == '(' || character == '{' || character == '[') {
                newStack.push(character);
            } else {
                if (newStack.empty()) return false; 

                char top = newStack.top();
                newStack.pop();

                if ((character == ')' && top != '(') ||
                    (character == '}' && top != '{') ||
                    (character == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return newStack.empty();
    }
};

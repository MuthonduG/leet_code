#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // initialize variables
        long long quotient = 0;

        // check if divisor or dividend 
        if(divisor == 0 || dividend == 0) return INT_MAX;

        // handle possible overflow
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        // check if result is negtive 
        bool result = (dividend < 0) ^ (divisor < 0);
        
        // change the to long to avoid overflow during abs()
        long long long_divdend = abs((long long) dividend);
        long long long_divisor = abs((long long) divisor);


        // subtract divisor multiples by bit shifting
        while(long_divdend >= long_divisor) {
            long long temp = long_divisor, count = 1;

            while(long_divdend >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }

            long_divdend -= temp;
            quotient += count;
        }

        if(result) quotient *= -1;

        return (int)quotient;
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int write = 1;

        for(int read = 1; read < (int)nums.size(); ++read) {
            if(nums[read] != nums[read-1]) {
                nums[write++] = nums[read];
            }
        }

        return write;
    }
};
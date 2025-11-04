#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        if (n == 0) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            int diff = nums[i + 1] - nums[i];

            for (int k = 1; k < diff; k++) {
                result.push_back(nums[i] + k);
            }
        }

        return result;
    }
};


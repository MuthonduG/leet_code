#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> 
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2]; 
        sort(nums.begin(), nums.end()); 
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) {
                    return sum; 
                }

                if (abs(sum - target) < abs(result - target)) {
                    result = sum;
                }

                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;  
    }
};

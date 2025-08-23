/**
    * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
    * The overall run time complexity should be O(log (m+n)).
*/
// 4 = 0, 1, 2, 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // merge arrays
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        int n = nums1.size();
        if (n == 0) return 0;

        if (n % 2 == 0) {
            return (nums1[n/2 - 1] + nums1[n/2]) / 2.0;
        } else {
            return nums1[n/2];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0
    return 0;
}

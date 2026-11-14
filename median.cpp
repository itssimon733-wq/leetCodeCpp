#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        size_t m = nums1.size();
        size_t n = nums2.size();
        int lo{0}; int hi = m;
        int half =  (m + n + 1)/ 2;

        while(lo <= hi) {
            int i = (lo + hi) / 2;
            int j = half - i;

            int aLeft  = (i == 0) ? INT_MIN : nums1[i - 1];
            int aRight = (i == m) ? INT_MAX : nums1[i];
            int bLeft  = (j == 0) ? INT_MIN : nums2[j - 1];
            int bRight = (j == n) ? INT_MAX : nums2[j];

            if (aLeft <= bRight && bLeft <= aRight) {
                if ((m + n) % 2) return std::max(aLeft, bLeft);
                return (std::max(aLeft, bLeft) + std::min(aRight, bRight)) / 2.0;
            } else if (aLeft > bRight) {
                hi = i - 1;
            } else {
                lo = i + 1;
            }
        }
        return 0.0;
        
    }
};
int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {3, 4};
    Solution sln;
    std::cout << "Median: "<< sln.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}
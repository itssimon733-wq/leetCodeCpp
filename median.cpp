#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);/* this is to make sure nums1 is always the smaller vector 
                                                                                    so if the condition is met the parameters (nems2,num1) are passed in as nums1 and nums2
                                                                                    respectively since it is a recursion.
                                                                                    */

        size_t m = nums1.size();//size of nums1 --3
        size_t n = nums2.size();//size of nums2 --4
        int lo{0}; //lowest possible partition
        int hi = m; //highest possible partition in nums1 
        int half =  (m + n + 1)/ 2; //the half way point of the two combined arrays 3+4+1=8 8/2 = 4

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
    std::vector<int> nums2 = {4, 5, 6, 7};
    Solution sln;
    std::cout << "Median: "<< sln.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}
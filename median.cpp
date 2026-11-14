#include <iostream>
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        size_t m = nums1.size();
        size_t n = nums2.size();
        int lo{0}; int hi = m;
        int half =  (m + n + 1)/ 2;
    }
};
int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {5, 8, 7};
    Solution sln;
    std::cout << "Median: "<< sln.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}
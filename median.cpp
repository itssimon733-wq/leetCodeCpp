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

        size_t m = nums1.size();        //size of nums1 --3
        size_t n = nums2.size();        //size of nums2 --4
        
        int lo{0};                      /*lowest possible partition :
                                                pass1 lo = 0
                                                pass2 lo = 2
                                        */

        int hi = m;                     //highest possible partition in nums1 --3
        int half =  (m + n + 1)/ 2;     //the half way point of the two combined arrays 3+4+1=8 8/2 = 4

        while(lo <= hi) {
            int i = (lo + hi) / 2;      /*this determines where our imaginary partition starts in nums1. 
                                                    pass1 i = 1 - our first cut will be after the 1st element(1)
                                        */

            int j = half - i;           /*this determines where our imaginary partition starts in nums2. 
                                                    pass1 j = 3 - our cut will be after the 3rd element(6)
                                        */


                                        /*This means that our left partion will contain:
                                                        pass1 = {1,4,5,6}    
                                        And the right partition will contain:
                                                        pass1 = {2,3,7}
                                        But to have a correct partition:
                                                1. The left partition must be >= to the right 
                                                2. The largest left <=  smallest right 
                                        But we have pas1 - 6 > 2 so we need to find the correct partition
                                        */

            int aLeft  = (i == 0) ? INT_MIN : nums1[i - 1];     //(i == 0) false: aLeft = 1  : last element of nums1 left partition
            int aRight = (i == m) ? INT_MAX : nums1[i];         //(1 == m) false: aRight = 2 : first element of num2 right partition
            int bLeft  = (j == 0) ? INT_MIN : nums2[j - 1];     //(j == 0) false: bLeft = 6  : last element of mums2 left partition
            int bRight = (j == n) ? INT_MAX : nums2[j];         //(j == n) false: bRight = 7 : last element of nums2 right partition

            if (aLeft <= bRight && bLeft <= aRight) { //first condition: true second: false :partition = inavalid
                if ((m + n) % 2) return std::max(aLeft, bLeft);
                return (std::max(aLeft, bLeft) + std::min(aRight, bRight)) / 2.0;
            } else if (aLeft > bRight) {//false
                hi = i - 1;
            } else {
                lo = i + 1;/*After :
                                pass1 lo = 2
                           */
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
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
                                                pass3 lo = 3
                                        */

        int hi = m;                     /*highest possible partition in nums1 :
                                                pass1 hi = 3
                                                pass2 hi = 3
                                                pass3 hi = 3
                                        */
        int half =  (m + n + 1)/ 2;     /*the half way point of the two combined arrays :
                                                pass1 half = 4
                                                pass2 half = 4
                                                pass3 half = 4
                                        */

        while(lo <= hi) {
            int i = (lo + hi) / 2;      /*this determines where our imaginary partition starts in nums1. 
                                                pass1 i = 1 - cut is after 1st element in nums1 = 1
                                                pass2 i = 2 - cut is after 2nd element in nums1 = 2
                                                pass3 i = 3 - cut is after 3rd element in nums1 = 3
                                        */

            int j = half - i;           /*this determines where our imaginary partition starts in nums2. 
                                                pass1 j = 3 - cut is after 3rd element in nums2 = 6
                                                pass1 j = 2 - cut is after 2nd element in nums2 = 5
                                                pass1 j = 1 - cut is after 1st element in nums2 = 4
                                        */


                                        /*This means that our left partion will contain:
                                                        pass1 = {1,4,5,6}   
                                                        pass2 = {1,2,4,5} 
                                                        pass3 = {1,2,3,4}
                                        And the right partition will contain:
                                                        pass1 = {2,3,7}
                                                        pass2 = {3,6,7}
                                                        pass3 = {5,6,7}
                                        But to have a correct partition:
                                                1. The left partition must be >= to the right 
                                                2. The largest left <=  smallest right 
                                        But we have :
                                                        pass1 - (6 <= 2): false :need to find the correct partition
                                                        pass2 - (5 <= 3): false :need to find the correct partition
                                                        pass2 - (4 <= 5): true :found the correct partition
                                                        
                                        */

            int aLeft  = (i == 0) ? INT_MIN : nums1[i - 1];     /*
                                                                    pass1: (i == 0) false: aLeft = 1  : last element of nums1 left partition
                                                                    pass2: (i == 0) false: aLeft = 2  : last element of nums1 left partitoin
                                                                    pass3: (i == 0) false: aLeft = 3  : last element of nums1 left partitoin
                                                                */
            int aRight = (i == m) ? INT_MAX : nums1[i];         /*
                                                                    pass1: (i == m) false: aRight = 2 : first element of num2 right partition
                                                                    pass2: (i == m) false: aRight = 3 : first element of num2 right partition
                                                                    pass3: (i == m) true: aRight = INT_MAX 
                                                                */
            int bLeft  = (j == 0) ? INT_MIN : nums2[j - 1];     /*
                                                                    pass1: (j == 0) false: bLeft = 6  : last element of mums2 left partition
                                                                    pass2: (j == 0) false: bLeft = 5  : last element of mums2 left partition
                                                                    pass3: (j == 0) false: bLeft = 4  : last element of mums2 left partition
                                                                */
            int bRight = (j == n) ? INT_MAX : nums2[j];         /*
                                                                    pass1: (j == n) false: bRight = 7 : first element of nums2 right partition
                                                                    pass2: (j == n) false: bRight = 6 : first element of nums2 right partition
                                                                    pass3: (j == n) false: bRight = 5 : first element of nums2 right partition
                                                                */

            if (aLeft <= bRight && bLeft <= aRight) {           /*
                                                                    pass1: first condition: true, second: false :partition = inavalid
                                                                    pass2: first condition: true, second: false :partition = inavalid
                                                                    pass2: first condition: true, second: true :partition = avalid
                                                                */
                if ((m + n) % 2) {
                    return std::max(aLeft, bLeft);//4
                }

                return (std::max(aLeft, bLeft) + std::min(aRight, bRight)) / 2.0;//not executed

            } else if (aLeft > bRight) {                        /*
                                                                    pass1: false
                                                                    pass2: false
                                                                    pass3: not reached
                                                                */
                hi = i - 1;
            } else {
                lo = i + 1;/*After :
                                pass1 lo = 2
                                pass2 lo = 3
                                pass3: not reached
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
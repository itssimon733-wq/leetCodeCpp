#include <iostream>
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> merged;
        //These two lines below declare two integers i and j that act as pointers to values in the vectors
        int i{0};
        int j{0};

        size_t n1 = nums1.size();
        size_t n2 = nums2.size();

        //The while loop below reads the values in the vectors passed in and sorts them in an ascending order
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                merged.push_back(nums1[i]);//this line adds the value to the merged vector if the condition is met
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n1){
            merged.push_back(nums1[i]);
            i++;
        }
        while(j < n2){
            merged.push_back(nums2[j]);
            j++;
        }

        size_t n = merged.size();
        if(n % 2 == 1){
            return merged[n/2];
        } else {
            return (merged[n/2 -1] + merged[n/2])/2.0;
        }
        
    }
};
int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {5, 8, 7};
    Solution sln;
    std::cout << "Median: "<< sln.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}
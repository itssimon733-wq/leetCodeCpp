#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        for(int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];
            if(numMap.find(complement) != numMap.end()){
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};
 
int main() {
    std::vector<int> nums = {2,7,11,15};
    Solution solution;
    std::vector<int> result = solution.twoSum(nums,9);
    for(int idx : result)std::cout<<idx<<" ";
    std::cout<<'\n';
    return 0;

}
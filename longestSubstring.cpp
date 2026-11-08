#include <iostream>
#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int lastSeen[128];
        for(int i = 0; i < 128; ++i){
            lastSeen[i] = -1;
        }
        int left{0};
        int maxLength{0};
        for(int right{0} ; right < s.length(); right++){
            char current = s[right];
            if(lastSeen[current] >= left){
                left = lastSeen[current] + 1;
            }
            int currentLength = right - left + 1;
            maxLength = std::max(maxLength, currentLength);
            lastSeen[current] = right;
        }
        return maxLength;
    }
};
int main(){
    Solution sln;
    std::string text = "abcdabbc";
    std::cout <<sln.lengthOfLongestSubstring(text)<<'\n';
}
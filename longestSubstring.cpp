#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        //++++++++++++++++++++Implemented using an array++++++++++++++++++++
        /*int lastSeen[128];
        for(int i = 0; i < 128; ++i){
            lastSeen[i] = -1;
        }*/

        //++++++++++++++++++++++Implemented using Hash map++++++++++++++++++++
        std::unordered_map<char, int> lastSeen;
        int left{0};
        int maxLength{0};
        for(int right{0} ; right < s.length(); right++){
            char current = s[right];
            auto it = lastSeen.find(current);
            //Below is an implementation using arrays
            /*if(lastSeen[current] >= left){
                left = lastSeen[current] + 1;
            }*/

            //Below is implementation using hash maps
            if(it != lastSeen.end() && it->second >= left){
                left = it->second + 1;
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
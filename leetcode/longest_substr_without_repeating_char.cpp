#include <unordered_map>
#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> char_map;
        int max_length = 0;
        int start = 0;
        int i = 0;
        int length = s.length();
        while (i < length) {
            if (char_map[s[i]] > start) {
                start = char_map[s[i]]; 
            }
            char_map[s[i]] = i + 1;
            max_length = max_length > (i - start + 1) ? max_length : (i - start+1);
            // max_length = std::max(max_length, i - start + 1);
            i++;
        }


        return max_length;

    }
};
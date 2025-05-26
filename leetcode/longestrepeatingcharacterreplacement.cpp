#include<vector>
#include<string>
class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int start = 0;
        int end = 0;
        std::vector<int> letters(26, 0);
        int max_len = 0;
        int max_char_count = 0;
        while (end < s.length()) {
            letters[s[end] - 'A']++;
            max_char_count = std::max(max_char_count, letters[s[end] - 'A']);
            if (end - start + 1 - max_char_count > k) {
                letters[s[start] - 'A']--;
                start++;
            }
            max_len = std::max(max_len, end - start + 1);
            end++;
        }
        return max_len;
    }
};
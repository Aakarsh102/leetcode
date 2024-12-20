#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        const int len = s.length();
        int start = 0;
        int max_len = 1;
        if (len < 2) {
            return s;
        }
        bool matrix[len][len];
        std::fill(&matrix[0][0], &matrix[0][0] + len*len, false);

        for (int i = 0; i < len; i++) {
            matrix[i][i] = true;
            if (i < len - 1 && s[i] == s[i+1]) {
                matrix[i][i+1] = true;
                start = i;
                max_len = 2;
            }
        }

        for (int i = 3; i <= len; i++) {
            for (int j = 0; j <= len - i; j++) {
                int end_index = j + i - 1;
                if (matrix[j + 1][end_index - 1] == true && s[j] == s[end_index]) {
                    matrix[j][end_index] = true;
                    max_len = i;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);


    }
};
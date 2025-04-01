class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int o = s3.length();
        if (n + m != o) {
            return false;
        }
        std::vector<std::vector<bool>>dp(s1.length() + 1,std::vector<bool>(s2.length() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < m + 1; i++) {
            if (s2[i-1] == s3[i-1]) {
                dp[0][i] = true;
                continue;
            }
            break;
        }
        for (int i = 1; i < n + 1; i++) {
            if (s1[i-1] == s3[i-1]) {
                dp[i][0] = true;
                continue;
            }
            break;
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (dp[i-1][j] == true) {
                    dp[i][j] = dp[i][j] || s1[i-1] == s3[i+j-1];
                }
                if (dp[i][j-1] == true) {
                    dp[i][j] = dp[i][j] || s2[j-1] == s3[i+j-1];
                }
            }
        }
        return dp[n][m];

    }
};
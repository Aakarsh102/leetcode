#include <vector>
class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // if (matrix[0][0] == '1') {
        //     dp[1][1] = 1;
        // } else {
        //     dp[1][1] = 0;
        // }
        int max = 0;
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i-1][j-1]);
                    max = std::max(max, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return max * max;
    }
};
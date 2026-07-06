#include <vector>
class Solution {
public:
std::vector<std::pair<int, int>> delta = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
    double knightProbability(int n, int k, int row, int column) {
        std::vector<std::vector<std::vector<double>>> dp(k + 1, std::vector<std::vector<double>>(n, std::vector<double>(n, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[0][i][j] = 1;
            }
        }
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                for (int h = 0; h < n; h++) {
                    calc_prob(i, j, h, dp);
                    if (i == k && j == row && h == column) {
                        return dp[k][row][column];
                    }
                }
            }
        }
        return 1;
        
    }

    void calc_prob(int k, int row, int col, std::vector<std::vector<std::vector<double>>>& dp) {
        
        int n = dp[0].size();
        double prob = 0;
        for (int i = 0; i < 8; i++) {
            std::pair<int, int> cur = delta[i];
            int r = row + cur.first;
            int c = col + cur.second;
            if (!(r > n - 1 || r < 0 || c > n - 1 || c < 0)) { 
                prob += 0.125 * dp[k - 1][r][c];
            }
        }
        dp[k][row][col] = prob;
    }
};
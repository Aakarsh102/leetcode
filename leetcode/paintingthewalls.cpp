#include <vector>
class Solution {
public:
    int paintWalls(std::vector<int>& cost, std::vector<int>& time) {
        int n = cost.size();
        std::vector<int> dp(n + 1, 500000000);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int t = time[i];
            int c = cost[i];
            for (int j = n; j >= 1; j--) {
                
                int p = std::max(0, j - time[i] - 1);
                dp[j] = std::min(dp[j], dp[p] + c);
            }
        }
        return dp[n];
    }
};
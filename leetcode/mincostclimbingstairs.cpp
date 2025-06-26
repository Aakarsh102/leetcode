#include <vector>
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = std::min(cost[0] + cost[1], cost[1]);

        int i = 2;
        while (i < cost.size()) {
            dp[i] = std::min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
            i++;
        }
        return std::min(dp[i - 1], dp[i - 2]);
        
    }
};
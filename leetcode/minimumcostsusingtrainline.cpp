#include <vector>
class Solution {
public:
    std::vector<long long> minimumCosts(std::vector<int>& regular, std::vector<int>& express, int expressCost) {
        std::vector<long long> ret = {};
        int n = express.size();
        if (n == 1) {
            return {std::min(regular[0], express[0])};
        }
        std::vector<std::vector<long long>> dp(n, std::vector<long long>(2, 0));
        dp[0][0] = regular[0];
        dp[0][1] = expressCost + express[0];
        ret.push_back(std::min(dp[0][0], dp[0][1]));
        for (int i = 1; i < n; i++) {
            dp[i][0] = std::min(dp[i - 1][0], dp[i - 1][1]) + regular[i];
            dp[i][1] = std::min(dp[i-1][1], dp[i-1][0] + expressCost) + express[i];
            ret.push_back(std::min(dp[i][0], dp[i][1]));
        }
        return ret;
    }
};
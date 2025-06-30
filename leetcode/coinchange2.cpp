#include <vector>
class Solution {
    public:
        int change(int amount, std::vector<int>& coins) {
            if (amount == 0) {
                return 1;
            }
            std::sort(coins.begin(), coins.end());
            std::vector<unsigned long long> dp(amount + 1, 0);
            dp[0] = 1;
            for (int i : coins) {
                for (int j = 0; j <= amount; j++) {
                    if (j - i >= 0) {
                        dp[j] = dp[j] + dp[j - i];
                    }
                }
            }
            return dp[amount];
        }
    };
    // 1,2. t = 3
    // 1,1,1,1
    // 1,1,2,2
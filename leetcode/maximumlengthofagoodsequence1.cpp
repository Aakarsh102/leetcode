#include <vector>
#include <algorithm>
class Solution {
public:
    int maximumLength(std::vector<int>& nums, int k) {
        // if (k == 0) {
        //     return 2;
        // }
        int n = nums.size();
        std::vector<std::vector<int>> dp(k+1, std::vector<int>(n, 1));
        // for (int i = 0; i < n; i++) {
        //     if (dp[i][0] == j) {

        //     }
        // }
        for (int i = 0; i < k+1; i++) {
            for (int j = 0; j < n; j++) {
                for (int p = 0; p < j; p++) {
                    if (nums[p] != nums[j]) {
                        if (i == 0) {
                            continue;
                        }
                        dp[i][j] = std::max(dp[i][j], dp[i-1][p] + 1);
                    } else {
                        dp[i][j] = std::max(dp[i][p] + 1, dp[i][j]);
                    }
                }
            }
        }
        return *std::max_element(dp[k].begin(), dp[k].end());
    }
};
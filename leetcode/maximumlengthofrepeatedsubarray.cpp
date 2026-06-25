#include <vector>
class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
        int max_val = 0;
        for (int i = 1; i < n1 + 1; i++) {
            for (int j = 1; j < n2 + 1; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    // dp[i][j] = std::max(std::max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1] + 1);
                    dp[i][j] = dp[i-1][j-1] + 1;
                    max_val = std::max(max_val, dp[i][j]);
                } else {
                    //dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                    dp[i][j] = 0;
                    //max_val = std::max(max_val, dp[i][j]);
                }
                
            }
        }
        return max_val;
    }
};
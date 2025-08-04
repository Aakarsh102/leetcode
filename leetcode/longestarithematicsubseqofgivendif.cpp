#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    int longestSubsequence(std::vector<int>& arr, int difference) {
        int n = arr.size();
        std::vector<int> dp(n, 1);
        std::unordered_map<int, int> mapper;
        int max_val = 1;
        int index = 0;
        for (int i = 0; i < n; i++) {
            index = mapper[arr[i] - difference];
            if (index != 0) {
                dp[i] = dp[index - 1] + 1;
            }
            max_val = std::max(max_val, dp[i]);
            index = mapper[arr[i]];
            if (index == 0) {
                mapper[arr[i]] = i + 1;
            }
            else if (dp[index - 1] < dp[i]) {
                mapper[arr[i]] = i + 1;
            }
        }
        return max_val;
    }
};
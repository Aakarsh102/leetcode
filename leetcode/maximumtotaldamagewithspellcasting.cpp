#include <unordered_map>
#include <vector>
#include <unordered_set>
class Solution {
public:
    long long maximumTotalDamage(std::vector<int>& power) {
        int n = power.size();
        std::unordered_map<long long, long long> gain;
        std::vector<long long > dp(n, 0);
        for (int i = 0; i < n; i++) {
            gain[power[i]] += power[i];
        }
        std::unordered_set<int> power2;
        for (int i : power) {
            power2.insert(i);
        }
        power.clear();
        for (int i : power2) {
            power.push_back(i);
        }
        std::sort(power.begin(), power.end());
        n = power.size();
        dp[0] = gain[power[0]];
        for (int i = 1; i < n; i++) {
            if (in_range(power[i - 1], power[i])) {
                dp[i] = dp[i - 1] + gain[power[i]];
            }
            else if (i >= 2 && in_range(power[i - 2], power[i])) {
                dp[i] = std::max(dp[i - 1], dp[i - 2] + gain[power[i]]);
            }
            else {
                int k = i - 2;
                for (k = i - 2; k >= 0; k--) {
                    if (in_range(power[k], power[i])) {
                        break;
                    }

                }
                if (k < 0) {
                    dp[i] = std::max(dp[i - 1], gain[power[i]]);
                } else {
                    dp[i] = std::max(dp[i - 1], dp[k] + gain[power[i]]);
                }
                
            }
        }
        return dp[n - 1];
    }
    bool in_range(long long a, long long b) {
        if (a - b > 2 || b - a > 2) {
            return true;
        }
        return false;
    }
};
#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<std::vector<int>> dp(3, std::vector<int>(n, 0));
        int low = 0;
        int high = 0;
        int profit = 0;
        std::vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            if (prices[low] >= prices[i]) {
                low = i;
            } else if (prices[high] <= prices[i] || prices[high] - prices[low] > profit) {
                high = i;
                profit = prices[high] - prices[low];
            }
            prefix[i] = profit;
        }
        std::vector<int> suffix(n, 0);
        high = prices[n - 1];
        profit = 0;

        for (int i = n - 1; i >= 0; --i) {
            high = std::max(high, prices[i]);
            profit = std::max(profit, high - prices[i]);
            suffix[i] = profit;
        }
        int max_val = 0;
        for (int i = 0; i < n; i++) {
            max_val = prefix[i] + suffix[i] > max_val ? prefix[i] + suffix[i] : max_val;
        }
        return max_val;
    }
};
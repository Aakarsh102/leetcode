#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxprofit = 0;
        int i = 0;
        while (i < prices.size() - 1) {
            if (prices[i] < prices[i+1]) {
                maxprofit += prices[i + 1] - prices[i];
            }
            i++;
        }
        return maxprofit;
    }
};
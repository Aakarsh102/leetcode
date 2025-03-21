#include <vector>
class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0, maxReach = 0, end = 0;

        for (int i = 0; i < n - 1; i++) {
            maxReach = std::max(maxReach, i + nums[i]);

            if (i == end) {
                jumps++;
                end = maxReach;

                if (end >= n - 1) break;
            }
        }

        return jumps;
    }
};
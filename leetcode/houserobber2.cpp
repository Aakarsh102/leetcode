#include <vector>
class Solution {
    public:
        int rob(std::vector<int>& nums) {
            int n = nums.size();
            if (n == 1) {
                return nums[0];
            }
            if (n == 2) {
                return std::max(nums[0], nums[1]);
            }
            std::vector<int> dp1(n - 1, 0);
            std::vector<int> dp2(n - 1, 0);
            dp1[0] = nums[0];
            dp1[1] = std::max(nums[1], nums[0]);
            dp2[0] = nums[1];
            dp2[1] = std::max(nums[2], nums[1]);
            int i = 2;
            while (i < n) {
                if (i > 2) {
                    dp2[i - 1] = std::max(dp2[i - 2], dp2[i - 3] + nums[i]);
                }
                if (i < n - 1) {
                    dp1[i] = std::max(dp1[i - 1], dp1[i - 2] + nums[i]);
                }
                i++;
            }
            return std::max(std::max(dp1[n - 2], dp1[n - 3]), std::max(dp2[n - 2], dp2[n - 3]));
        }
    };
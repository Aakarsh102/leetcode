#include <vector>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int sum = nums.size() - 1;
        int start = 0;
        if (nums[start] >= sum) {
            return true;
        }
        int cur = start;
        while (cur < sum) {
            if (nums[cur] < nums[start] - cur + start) {
                cur++;
                continue;
            }
            if (cur - start == nums[start]) {
                if (nums[cur] == 0) {
                    return false;
                }
            }
            start = cur;
            if (nums[cur] + start >= sum) {
                return true;
            }
            cur++;
        }
        return false;
    }
};
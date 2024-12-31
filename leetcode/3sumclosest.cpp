#include <vector>
#include <algorithm>
class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int i = 0;
        int left;
        int right;
        int sum;
        int closest = 20000;
        std::sort(nums.begin(), nums.end());
        while (i < nums.size()) {
            // if (closest < 0) {break;}
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            sum = target - nums[i];
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                int total = sum - nums[left] - nums[right];
                if (total == 0) {
                    return target;
                }
                if (std::abs(total) < std::abs(closest)) {
                    closest = total;
                }
                if (total < 0) {
                    while (left < right && nums[right] == nums[right - 1]) {right--;}
                    right--;
                }
                else {
                    while (left < right && nums[left] == nums[left + 1]) {left++;}
                    left++;
                }
            }
            i++;
        }
        return target - closest;
    }
};
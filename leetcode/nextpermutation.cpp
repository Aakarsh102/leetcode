#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) {
                int j = nums.size() - 1;
                while (j > 0) {
                    if (nums[j] > nums[i]) {
                        std::swap(nums[i], nums[j]);
                        std::sort(nums.begin() + i + 1, nums.end());
                        return;
                    }
                    j--;
                }
                return;
            }
            i--;
        }
        std::sort(nums.begin(), nums.end());
        
    }
};
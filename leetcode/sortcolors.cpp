#include <vector>
#include <algorithm>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        recurse(nums, 0, nums.size() - 1);
        return;
        
    }

    void recurse(std::vector<int>& nums, int start, int end) {
        int window = end - start;
        // if ( window == 1) {
        //     if (nums[0] > nums[1]) {
        //         std::swap(nums[0], nums[1]);
        //     }
        //     return;
        // }
        // if (window == 0) {
        //     return;
        // }
        if (start >= end) {
            return;
        }
        int mid = (start + end)/2;
        recurse(nums, start, mid);
        recurse(nums, mid + 1, end);
        std::inplace_merge(nums.begin() + start, nums.begin() + mid + 1, nums.begin() + end + 1);

    }
};
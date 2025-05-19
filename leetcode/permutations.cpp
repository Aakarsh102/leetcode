#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> store;
        filler(nums, 0, store);
        return store;
    }
    void filler(std::vector<int>& nums, int begin, std::vector<std::vector<int>>& store) {
        if (begin == nums.size()) {
            store.push_back(nums);
            return;
        }
        int temp = nums[begin];
        for (int i = begin; i < nums.size(); i++) {
            std::swap(nums[begin], nums[i]);
            //store.push_back(nums);
            filler(nums, begin + 1,store);
            std::swap(nums[begin], nums[i]);
        }
        return;
    }
};
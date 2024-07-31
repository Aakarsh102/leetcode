#include <iostream>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int search_val = nums[i];
            if (m[search_val] != 0) {
                return std::vector<int> {i, m[search_val] - 1};
            }
            m[target - search_val] = i + 1;
        }
        return std::vector<int> {};

        
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> ret_val = s.twoSum(nums, target);
    for (int i = 0; i < ret_val.size(); i++) {
        std::cout << ret_val[i] << " ";
    }
    return 0;
}
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> output;
    int size;
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        size = nums.size();
        do_backtracking(nums, 0, {});
        return output;
    }
    void do_backtracking(std::vector<int>& nums, int index, std::vector<int> vec) {
        output.push_back(vec);
        for (int i = index; i < size; i++) {
            vec.push_back(nums[i]);
            do_backtracking(nums, i + 1, vec);
            vec.pop_back();
        }
    }


};
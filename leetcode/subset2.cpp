#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> vec;
        backtracker(nums, 0, vec);
        return res;
    }
    void backtracker(std::vector<int>& nums, int index, std::vector<int>& vec) {
        if (index == nums.size()) {
            res.push_back(vec);
            return;
        }
        // if (index > 0 && nums[index] == nums[index - 1]) {} else {
        //     res.push_back(vec);
        // }
        res.push_back(vec);
        for (int i = index; i < nums.size(); i++) {
            // if (i > 0 && nums[i] == nums[i - 1]) {} else {
            //     // backtracker(nums, index + 1, vec);
            //     res.push_back(vec);
            // }
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            vec.push_back(nums[i]);
            backtracker(nums, i + 1, vec);
            vec.pop_back();
        }

    }
};
#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> vec;
        do_backtracking(candidates, target, 0, vec, 0);
        return res;
    }
    void do_backtracking(std::vector<int>& candidates, int target, int sum, std::vector<int>& vec, int index) {
        if (sum == target) {
            res.push_back(vec);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i - 1] == candidates[i]) {
                continue;
            }
            if (sum + candidates[i] <= target) {
                vec.push_back(candidates[i]);
                do_backtracking(candidates, target, sum + candidates[i], vec, i + 1);
                vec.pop_back();
            } else {
                return;
            }
        }

    }

};
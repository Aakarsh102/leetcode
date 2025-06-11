#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> vec = {};
        do_back(candidates, target, vec, 0, 0);
        return res;
    }

    void do_back(std::vector<int>& candidates, int target, std::vector<int>& vec, int sum, int index) {
        if (sum == target) {
            res.push_back(vec);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            int k = candidates[i];
            if (sum + k <= target) {
                vec.push_back(k);
                do_back(candidates, target, vec, sum + k, i);
                vec.pop_back();
            }
            if (sum + k > target) {
                return;
            }
        }
    }
};
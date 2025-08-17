#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        if (n == 1 || n == 2) {
            return {};
        }
        std::vector<int> used;
        std::vector<std::vector<int>> sol;
        recurse(k, n, 0, 1, used, sol);
        return sol;
    }
    void recurse(int k, int n, int sum, int index, std::vector<int>& used, std::vector<std::vector<int>>& sol) {
        if (sum == n) {
            if (used.size() == k) {
                sol.push_back(used);            
            }
            return;
        }
        while (index < 10) {
            used.push_back(index);
            recurse(k, n, sum + index, index + 1, used, sol);
            used.pop_back();
            index++;
        }

    }
};
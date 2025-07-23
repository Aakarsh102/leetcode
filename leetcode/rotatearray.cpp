#include <vector>
class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) {
            return;
        }
        std::vector<int> t;
        for (int i = 0; i < k; i++) {
            t.push_back(nums.back());
            nums.pop_back();
        }
        std::vector<int> store;
        while (!t.empty()) {
            store.push_back(t.back());
            t.pop_back();
        }
        for (int i = 0; i < nums.size(); i++) {
            store.push_back(nums[i]);
        }
        nums.clear();
        for (int i : store) {
            nums.push_back(i);
        }

    }
};
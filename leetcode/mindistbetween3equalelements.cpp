#include <vector>
#include <unordered_map>

class Solution {
public:
    int minimumDistance(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return -1;
        }
        std::unordered_map<int, std::vector<int>> store;
        for (int i = 0; i < nums.size(); i++) {
            if (store.find(nums[i]) != store.end()) {
                store[nums[i]].push_back(i);
            } else {
                store[nums[i]] = {i};
            }
        }
        int min_dist = 4 * nums.size();
        std::vector<int> v;

        for (const auto& i : store) {
            v = i.second;
            int j = 0;
            while (j < (int)v.size() - 2) {
                min_dist = std::min(2 * (v[j + 2] - v[j]), min_dist);
                j++;
            }
        }
        return min_dist == 4 * nums.size() ? -1 : min_dist;
    }
};
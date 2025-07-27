#include <vector>
#include <unordered_map>
class Solution {
public:

    int deleteAndEarn(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        std::vector<int> store(10001, 0);
        std::unordered_map<int, int> mapper;
        for (int i : nums) {
            store[i] += i;
        }
        int max_val=0;
        for (int i = 2; i < 10001; i++) {
            store[i] = std::max(store[i] + store[i - 2], store[i - 1]);
        }
        return store[10000];
    }

};
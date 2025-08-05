#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        // std::sort(nums.begin(), nums.end());
        std::unordered_map<int, int> indices;
        std::unordered_map<int, int> counts; 
        std::unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (k - nums[i] <= 0) {
                seen.insert(nums[i]);
                continue;
            }
            indices[k - nums[i]] = i + 1;
            counts[nums[i]]++;
        }
        
        int n = 0;
        int count = 0;
        int index = 0;
        int store = 0;
        for (int i = 0; i < nums.size(); i++) {
            n = nums[i];
            if (seen.find(n) != seen.end()) {
                continue;
            }
            index = indices[n] - 1;
            if (index != -1) {
                if (n == nums[index]) {
                    store = counts[n]/2;
                    count += store;
                    // counts[n] -= store;
                } else{
                    store = std::min(counts[n], counts[nums[index]]);
                    count += store;
                    // counts[n] -= store;
                    // counts[nums[index]] -= store;
                }
                seen.insert(nums[index]);
            }
            seen.insert(n);
        }
        return count;
    }
};
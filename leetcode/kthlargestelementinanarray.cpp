#include <algorithm>
#include <vector>
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end());
        int store;
        while (k > 0) {
            std::pop_heap(nums.begin(), nums.end());
            k--;
            store = nums.back();
            nums.pop_back();
        }
        
        return store;
    }
};
#include <vector>
class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int count = 0;
        int ret = 0;
        int val = 0;
        while (start < n) {
            if (start > 0 && nums[start - 1] == 0) {
                count--;
            }
            while (end < n && count <= k) {
                if (nums[end] == 0) {
                    if (count == k) {
                        break;
                    }
                    count++;
                }
                end++;
                val = end - start > val ? end - start : val; 
            }
            start++;
        }
        return val;
    }
};
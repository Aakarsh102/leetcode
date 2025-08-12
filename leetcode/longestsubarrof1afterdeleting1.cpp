#include <vector>
#include <algorithm>
class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int count = 0;
        int max_len = 0;
        int end = 0;
        int start = 0;
        while (end < nums.size()) {
            if (nums[end] != 1 && count == 0) {
                count++;
            }
            else if (nums[end] != 1 && count == 1) {
                while (start < end) {
                    start++;
                    if (nums[start - 1] == 0) {
                        // start++;
                        break;
                    }
                    
                }
            }
            // std::cout << end - start << std::endl;
            max_len = std::max(end - start, max_len);
            end++;
        }
        return max_len;
    }
};
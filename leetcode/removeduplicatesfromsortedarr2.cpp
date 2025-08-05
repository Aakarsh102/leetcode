#include <vector>
#include <algorithm>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        bool rem = false;
        int i = 1;
        int count = 0;
        int prev = nums[0];
        while ( i < nums.size()) {
            if (nums[i] == prev) {
                if (rem) {
                    prev = nums[i];
                    nums[i] = 10001;
                    count++;
                } else {
                    prev = nums[i];
                    rem = true;
                }
            } else {
                prev = nums[i];
                rem = false;
            }
            i++;
        }
        std::sort(nums.begin(), nums.end());
        return nums.size() - count;
    }
};
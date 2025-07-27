#include <vector>
#include <limits>
class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int first = INT_MAX;
        int second = INT_MAX;
        int i = 0;
        while (i < nums.size()) {
            if (first >= nums[i]) {
                first = nums[i];
            } else if (second >= nums[i]) {
                second = nums[i];
            } else {
                return true;
            }
            i++;
        }
        return false;   
    }
};

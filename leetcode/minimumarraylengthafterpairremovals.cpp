#include <vector>
class Solution {
public:
    int minLengthAfterRemovals(std::vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = (n)/2;
        int pairs = 0;
        while (i < n/2 && j < n) {
            if (nums[i] < nums[j]) {
                pairs++;
                i++;
                j++;
            } else{
                j++;
            }
        } 
        return n - 2 * pairs;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int max = nums[0];
        int i = 1;
        while (i < nums.size()) {
            int new_sum = nums[i - 1]+nums[i]>nums[i] ? nums[i - 1]+nums[i]:nums[i];
            nums[i] = new_sum;
            // if (sum > nums[i - 1]) {
            //     if(sum > nums[i]) {
            //         nums[i] = sum;
            //     }
            //     if 
            // }
            if (new_sum > max) {
                max = new_sum;
            }
            i++;
        }
        return max;

    }
    // int max_inter(vector<int>& nums, int left, int right, int mid) {
    //     int max = INT_MIN;
    //     int cur_max_left = 0;
    //     int i = mid - 1;
    //     while (i >= 0) {
    //         cur_min += nums[i];
    //         if (cur_max > max) {
    //             max = cur_max;
    //         }
    //         i--;
    //     }
    //     max = INT_MIN;
    //     int cur_max_right = 0;
    //     i = mid;
    //     while (i <= right) {
    //         cur_max += nums[i];
    //         if (cur_max_right > max) {
    //             max = cur_max_right;
    //         }
    //         i++;
    //     }
    //     return cur_max_left + cur_max_right;
    // }
};
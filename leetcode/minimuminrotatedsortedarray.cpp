class Solution {
public:
    int findMin(vector<int>& nums) {
    if (nums[nums.size() - 1] >= nums[0]) {
        return nums[0];
    }
    int start = 0;
    int end = nums.size() - 1;

    while (start < end) {
        int mid = (start+end)/2;
        if (nums[mid] < nums[end]) {
            end = mid;
        } else if (nums[mid] > nums[end]) {
            start = mid + 1;
        } else {
            return nums[mid];
        }
    }
    return nums[start];
    }
};
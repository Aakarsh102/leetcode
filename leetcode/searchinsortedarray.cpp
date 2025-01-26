#include <vector>
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        
        int pivot = start;
        start = 0, end = nums.size() - 1;

        if (target >= nums[pivot] && target <= nums[end]) {
            start = pivot;
        } else {
            end = pivot - 1;
        }

        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1; 
    }


    
};
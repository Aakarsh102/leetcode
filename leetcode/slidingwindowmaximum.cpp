#include <vector> 
#include <queue>
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::priority_queue<std::pair<int, int>> heap;
        std::vector<int> result;
        for (int i = 0; i < k; i++) {
            heap.push({nums[i], i});
        }
        //int start = 0;
        int end = k;
        result.push_back(heap.top().first);
        while (end < nums.size()) { 
            heap.push({nums[end], end});
            std::pair<int, int> p = heap.top();
            while (p.second < end - k + 1) {
                heap.pop();
                p = heap.top();
            }

            result.push_back(p . first);
            //start++;
            end++;
            
        }
        return result;
    }
};
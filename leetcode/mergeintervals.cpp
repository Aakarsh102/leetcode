#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b) {
            return a[0] < b[0];
        });
        int end = -1;
        //int end = intervals[0][1];
        std::vector<int> prev = {};
        std::vector<std::vector<int>> res;
        //bool flag = false;
        for (std::vector<int>& interval : intervals) {
            
            if (interval[0] <= end) {
                prev[1] = std::max(interval[1], prev[1]);
                end = prev[1];
            } else {
                //flag = true;
                if (!prev.empty()) {
                    res.push_back(prev);
                }
                prev = interval;
                end = prev[1];
            }
            // flag = false;
        }
        res.push_back(prev);
        return res;
    }
};
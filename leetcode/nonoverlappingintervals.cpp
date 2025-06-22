#include <vector>
class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        std::vector<int> dp(intervals.size(), 0);
        std::sort(intervals.begin(), intervals.end(), 
        [] (const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        }
        );
        int last_end = INT_MIN;
        int count = 0;
        for (std::vector<int>& i : intervals) {
            if (i[0] >= last_end) {
                last_end = i[1];
            } else {
                count++;

            }
        }
        return count;
        
    }
};
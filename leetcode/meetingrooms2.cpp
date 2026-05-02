#include <vector>
#include <algorithm>
class Solution {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        std::vector<int> start_times;
        std::vector<int> end_times;
        for (int i = 0; i < intervals.size(); i++) {
            start_times.push_back(intervals[i][0]);
            end_times.push_back(intervals[i][1]);
        }
        std::sort(start_times.begin(), start_times.end());
        std::sort(end_times.begin(), end_times.end());
        int count = 0;
        int max_count = 0;
        int i = 0;
        int j = 0;
        while (i < intervals.size()) { 
            if (start_times[i] < end_times[j]) {
                count++;
                i++;
                max_count = std::max(count, max_count);
            } else {
                count--;
                j++;
            }
        }
        return max_count;
    }
};
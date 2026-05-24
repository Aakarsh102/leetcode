#include <vector>
class Solution {
public:
    std::vector<int> countPoints(std::vector<std::vector<int>>& points, std::vector<std::vector<int>>& queries) {
        std::vector<int> answer(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (inside(points[j], queries[i])) {
                    answer[i]++;
                }
            }
        }
        return answer;
    }
    bool inside(std::vector<int>& point, std::vector<int>& circle) {
        int del_x = point[0] - circle[0];
        int del_y = point[1] - circle[1];
        if ((int)pow(del_x, 2) + (int)pow(del_y, 2) > circle[2] * circle[2]) {
            return false;
        }
        return true;
    }
};
#include <vector>
class Solution {
public:
    std::vector<int> findBuildings(std::vector<int>& heights) {
        std::vector<int> stack;
        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[i] >= heights[stack.back()]) {
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return stack;
    }
};
#include <vector>
class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        bool found = true;
        int count = 0;
        for (int i = 0; i < n; i++) {
            found = true;
            for (int j = 0; j < n; j++) {
                found = true;
                for (int k = 0; k < n; k++) {
                    if (grid[i][k] != grid[k][j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    count++;
                }
            }
        }
        return count;
    }
};
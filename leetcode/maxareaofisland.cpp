#include <vector>
#include <algorithm>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto count_remove = [&](int i, int j) {
            int size = 0;
            std::vector<std::pair<int, int>> stack;
            stack.push_back({i, j});
            std::pair<int, int> cur;
            while(!stack.empty()) {
                cur = stack.back();
                stack.pop_back();
                if (grid[cur.first][cur.second] == 0) {
                    continue;
                }
                size++;
                grid[cur.first][cur.second] = 0;
                if (cur.first > 0) {
                    if (grid[cur.first - 1][cur.second] == 1) {
                        stack.push_back({cur.first - 1, cur.second});
                    }
                }
                if (cur.second > 0) {
                    if (grid[cur.first ][cur.second - 1] == 1) {
                        stack.push_back({cur.first, cur.second - 1});
                    }
                }
                if (cur.first < m - 1) {
                    if (grid[cur.first + 1][cur.second] == 1) {
                        stack.push_back({cur.first + 1, cur.second});
                    }
                }
                if (cur.second < n - 1) {
                    if (grid[cur.first][cur.second + 1] == 1) {
                        stack.push_back({cur.first, cur.second + 1});
                    }
                }
            }
            return size;
        };
        int ma = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ma = std::max(count_remove(i, j), ma);
                }
            }
        }
        return ma;
    }
};
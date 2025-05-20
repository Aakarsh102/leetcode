#include <vector>
#include <algorithm>
class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        auto k = [&](int i, int j) {
            std::vector<std::pair<int,int>> stack;
            std::pair p = {i, j};
            stack.push_back(p);
            
            while (stack.size() != 0) {
                p = stack.back();
                stack.pop_back();
                grid[p.first][p.second] = '0';
                if (p.first > 0) {
                    if (grid[p.first - 1][p.second] == '1') {
                        stack.push_back({p.first - 1, p.second});
                        //grid[p.first - 1][p.second] = '0';
                    }
                }
                if (p.second > 0) {
                    if (grid[p.first][p.second - 1] == '1') {
                        stack.push_back({p.first, p.second - 1});
                        //grid[p.first][p.second - 1] = '0';
                    }
                }
                if (p.second < m - 1) {
                    if (grid[p.first][p.second + 1] == '1') {
                        stack.push_back({p.first, p.second + 1});
                        //grid[p.first][p.second + 1] = '0';
                    }
                }
                if (p.first < n - 1) {
                    if (grid[p.first + 1][p.second] == '1') {
                        stack.push_back({p.first + 1, p.second});
                        //grid[p.first + 1][p.second] = '0';
                    }
                }
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    k(i,j);
                }
            }
        }
        return count;

    }
    
};
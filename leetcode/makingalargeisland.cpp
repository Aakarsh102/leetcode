#include <vector>
#include <unordered_map>
#include <queue> 
class Solution {
public:
    int largestIsland(std::vector<std::vector<int>>& grid) {
        int count = 2;
        std::unordered_map<int, int> sizes;
        sizes[0] = 0;
        sizes[2] = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    sizes[count] = fillisland(grid, count, i, j);
                    count++;
                }
            }
        }
        int m = sizes[2];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    m = std::max(m, check(grid, sizes, i, j));
                }
            }
        }
        return m;
    }
    int fillisland(std::vector<std::vector<int>>& grid, int count, int i, int j) {
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        std::pair<int, int> p;
        int size = 1;
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        grid[i][j] = count;
        while (!q.empty()) {
            p = q.front();
            q.pop();

            for (std::pair<int, int>& i : dirs) {
                int ni, nj;
                ni = p.first + i.first;
                nj = p.second + i.second;
                if (isvalid(m, n, ni, nj) && grid[ni][nj] == 1) {
                    size++;
                    grid[ni][nj] = count;
                    q.push({ni, nj});
                }
            }
        }
        return size;
    }

    bool isvalid(int I, int J, int i, int j) {
        if (i >= 0 && i < I && j >= 0 && j < J) {
            return true;
        }
        return false;
    }

    int check(std::vector<std::vector<int>>& grid, std::unordered_map<int, int>& s, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        int cur = 1;
        std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::vector<int> vis = {0, 0, 0, 0};
        int count = 0;
        for (std::pair<int, int>& k : dirs) {
            if (isvalid(m, n, i + k.first, j + k.second)) {
                int c = grid[i + k.first][j + k.second];
                if (vis[0] == c || vis[1] == c || vis[2] == c || vis[3] == c) {
                    continue;
                }
                vis[count] = c;
                count++;
                cur += s[c];

            }
        }
        return cur;
    }
};
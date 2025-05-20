#include<vector>
class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> store;
        int count = 0;
        auto k = [&](int i, int j) {
            int a = 0;
            int ret = 0;
            if (i < m - 1){
                if (grid[i + 1][j] == 1) {
                    grid[i+1][j] = 2;
                    store.push_back({i+1, j});
                    //ret = k(i+1, j);
                    //a = ret > a ? ret : a;
                }
            }
                if (j < n - 1) {
                    if (grid[i][j + 1] == 1) {
                        grid[i][j + 1] = 2;
                        store.push_back({i, j + 1});
                        //ret = k(i, j + 1);
                        //a = ret > a ? ret : a;
                    }

                }
                if (i > 0) {
                    if (grid[i - 1][j] == 1) {
                        grid[i - 1][j] = 2;
                        store.push_back({i - 1, j});
                        //ret = k(i - 1, j);
                        //a = ret > a ? ret : a;
                    }
                }
                if (j > 0) {
                    if (grid[i][j - 1] == 1) {
                        grid[i][j - 1] = 2;
                        store.push_back({i, j - 1});
                        //ret = k(i, j - 1);
                        //a = ret > a ? ret : a;
                    }
                }
            
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    store.push_back({i, j});  // Call your function here
                }

            }
        }
        int count2 = 0;
        while (true) {
            if (store.size() == count2) {
                for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1) {
                        return -1;
                    }
                    if (grid[i][j] == 2) {
                        count2 = -100;
                    }

                }
                }
                if (count2 != -100) {
                    return 0;
                }
                return count - 1;
            }
            count++;
            count2 = store.size();
            for (int i = 0; i < count2; i++) {
                k(store[i][0],store[i][1]);
            }
        }
        
        
        
    }
};
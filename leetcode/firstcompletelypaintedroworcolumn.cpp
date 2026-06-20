#include <vector>

class Solution {
public:
    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        std::vector<int> rows(m, 0);
        std::vector<int> cols(n, 0);
        std::vector<std::pair<int, int>> um(m*n+1, {0,0});
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                um[mat[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            std::pair<int, int> p = um[arr[i]];
            int k = p.first;
            int l = p.second;
            rows[k] += 1;
            cols[l] += 1;
            if (rows[k] == n || cols[l] == m) {
                return i;
            }
        }
        return -1;
    }
};
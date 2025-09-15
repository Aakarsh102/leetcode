#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        if (n == 1) {
            return {{1}};
        }
        std::vector<int> cur;
        std::vector<std::vector<int>> store;
        recurse(n, k, 1, cur, store);
        return store;
    }
    void recurse(int n, int k, int i, std::vector<int>& cur, std::vector<std::vector<int>>& store) {
        if (n - i + 1 < k) {
            return;
        } else if (k == 0) {
            store.push_back(cur);
            return ;
        }
        // recurse(n, k, i + 1, cur, store);
        int j = i;
        while (j <= n) {
            cur.push_back(j);
            recurse(n, k - 1, j + 1, cur, store);
            cur.pop_back();
            j++;
        }

    }
};
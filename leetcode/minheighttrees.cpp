#include <vector>
#include <queue>


class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        if (n == 1) return {0};

        std::vector<std::vector<int>> adj(n);
        std::vector<int> deg(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        std::queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1)
                q.push(i);
        }

        int remaining = n;

        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;

            while (sz--) {
                int leaf = q.front();
                q.pop();

                for (int nei : adj[leaf]) {
                    if (--deg[nei] == 1)
                        q.push(nei);
                }
            }
        }

        std::vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
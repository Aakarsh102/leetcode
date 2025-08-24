#include <vector>
class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<std::vector<int>>> adj_list(n);


        for (std::vector<int>& i : connections) {
            adj_list[i[0]].push_back({i[1], 1});
            adj_list[i[1]].push_back({i[0], 0});
        }
        int changes = 0;
        dfs(adj_list, 0, -1, changes);
        return changes;
    }
    void dfs(std::vector<std::vector<std::vector<int>>>& adj, int node, int parent, int& changes) {
        for (std::vector<int>& i : adj[node]) {
            if (i[0] == parent) {
                continue;
            }
            changes += i[1];
            dfs(adj, i[0], node, changes);
        }

    }
};
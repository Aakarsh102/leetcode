#include <unordered_set>
#include <vector>
#include <queue> 
class Solution {
public:
    int minimumSemesters(int n, std::vector<std::vector<int>>& relations) {
        std::vector<int> in_edges(n + 1, 0);
        std::vector<std::vector<int>> adj_list(n + 1, std::vector<int>() );
        for (std::vector<int>& cur : relations) {
            in_edges[cur[1]]++;
            adj_list[cur[0]].push_back(cur[1]);
        }
        
        std::queue<std::pair<int, int>> q;
        std::unordered_set<int> visited;
        for (int i = 1; i < n + 1; i++) {
            if (in_edges[i] == 0) {
                q.push({i, 1});
                visited.insert(i);
            }
        }
        std::pair<int, int> cur;
        int max_layer = 1;
        while (!q.empty() && visited.size() != n) {
            cur = q.front();
            q.pop();
            for (int i : adj_list[cur.first]) {
                if (visited.find(i) != visited.end()) {
                    in_edges[i]--;
                    if (in_edges[i] == 0) {
                        q.push({i, cur.second + 1});
                        visited.insert(i);
                        max_layer = std::max(max_layer, cur.second + 1);
                    }
                }
            }
        }
        if (visited.size() != n) {
            return -1;
        }
        return max_layer;
    }
};
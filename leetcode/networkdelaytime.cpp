#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        std::unordered_map<int, std::vector<std::vector<int>>> adj_list;
        for (std::vector<int> i : times) {
            adj_list[i[0]].push_back({i[1], i[2]});
        }
        std::vector<int> time(n + 1, 1e9);
        time[k] = 0;
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            std::vector<int> vec = pq.top();
            pq.pop();
            if (vec[0] > time[vec[1]]) {
                continue;
            }
            for (std::vector<int>& i : adj_list[vec[1]]) {
                int candidate = vec[0] + i[1];
                if (candidate < time[i[0]]) {
                    time[i[0]] = candidate;
                    pq.push({candidate, i[0]});
                }
            }

        }
        int ans = 0;
        for (int v = 1; v <= n; ++v) {
            if (time[v] == 1000000000) return -1;
            ans = std::max(ans, time[v]);
        }
        return ans;

    }
};
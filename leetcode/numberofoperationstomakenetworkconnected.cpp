#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int makeConnected(int n, std::vector<std::vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        std::vector<int> disjoint_sets(n, 0);
        std::iota(disjoint_sets.begin(), disjoint_sets.end(), 0);
        int groups = n;
        int extras = 0;
        for (int i = 0; i < connections.size(); i++) {
            int ret = uniona(connections[i][0], connections[i][1], disjoint_sets);
            if (ret == -1) {
                extras ++;
            } else {
                groups--;
            }
        }
        return groups - 1;
    }

    int uniona(int a, int b, std::vector<int>& connections) {
        int pa = find(a, connections);
        int pb = find(b, connections);
        if (pb == pa) {
            return -1;
        }
        connections[pa] = pb;
        return 0;
    }
    int find(int a, std::vector<int>& parent) {
        if (parent[a] != a)
            parent[a] = find(parent[a], parent);
        return parent[a];
    }
};
#include <vector> 
#include <string> 
#include <unordered_map>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::unordered_set<int>> graph(n);
    std::vector<int> time(n, 0);
    std::vector<int> indeg(n, 0);
    int a;
    int b;
    int c;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        std::cin >> b;
        time[i] = a;
        for (int j = 0; j < b; j++) {
            std::cin >> c;
            graph[i].insert(c - 1);
            indeg[c - 1]++;
        }
    }
    std::priority_queue<std::pair<int, int>>  pq;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            pq.push({-time[i], i});
        }
    }
    std::pair<int,int> cur;
    std::vector<int> topo;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        topo.push_back(cur.second);
        for (int i : graph[cur.second]) {
            indeg[i]--;
            if (indeg[i] == 0) {
                pq.push({-time[i], i});
            }
        }
    }
    int longest = 0;
    for (int i = n - 1; i >= 0; i--) {
        longest = std::max(longest, time[topo[i]] + (n - 1 - i));
    }
    std::cout << longest;
}
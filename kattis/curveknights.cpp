// 
// Problem: Curvey Knights
// Author: Aakarsh Rai (rai53)
// It is ok to show my solution to others
//

#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <iostream>
#include <queue>

// Algorithm: I use kahns algorithm to do a topological sort. 
// Every time a process a node, I add the (quantity of node required * (quantity of ingredient)) to the quantity of the ingredient.
// Since this will store the number of that ingredient required. Now this will have its own dependencies.
// the dependences will go down the graph and keep adding up.
int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    // Quantity of each item. They get very large so I use unsigned long long to be safe. 
    std::vector<unsigned long long> quantities(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> quantities[i];
    }
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    std::vector<int> indeg(n, 0);
    std::queue<int> q;

    // This create a reverse graph adjacencly list. 
    // Since we want to first process nodes that aren't ingredients for other nodes.
    int a, b, c;
    for (int i = 0; i < m; i++) {
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        graph[b].push_back({a, c});
        indeg[a]++;
    }
    // initializing the indegree counts 
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    int cur = 0;
    std::pair<int, int> cur_pair;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (std::pair<int, int>& p: graph[cur]) {
            // this is the most important part. 
            // Here I add the quantity of p.first needed to makes all of the cur item to the 
            // quantities for p.first. 
            quantities[p.first] += quantities[cur] * p.second;
            indeg[p.first]--;
            if (indeg[p.first] == 0) {
                q.push(p.first);
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        std::cout << quantities[i] << " ";
    }
    std::cout << quantities[n - 1] << std::endl;

}
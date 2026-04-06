#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <iostream>
#include <queue>
#include <climits>
int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, INT_MIN));
    int a, b, c;
    for (int i = 0; i < m; i++) {
        
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        graph[a][b] = c;
        graph[a][a] = 0;
        graph[b][b] = 0;
    }
    //std::cout << "here1" << std::endl;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (graph[i][k] != INT_MIN) {
                for (int j = 1; j <= n; j++) {
                    if (graph[k][j] != INT_MIN) {
                        graph[i][j] = std::max(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
            
        }
    }
    int cases;
    std::cin >> cases;
    //std::cout << "here" << std::endl;
    int maximum_p = INT_MIN;
    for (int i = 0; i < cases; i++) {
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        for (int j = 0; j < c; j++) {
            std::cin >> m;
            if (graph[a][m] != INT_MIN && graph[m][b] != INT_MIN) {
                maximum_p = std::max(maximum_p, graph[a][m] + graph[m][b]);
            }
        }
        if (maximum_p == INT_MIN) {
            std::cout << "NO PATH" << std::endl;
        } else {
            std::cout << maximum_p << std::endl;
        } 
        maximum_p = INT_MIN;
    }
}
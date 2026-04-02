#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <iostream>

int dobfs(std::vector<std::vector<int>>& graph, int color, std::vector<std::vector<bool>>& blob) {
    std::vector<std::vector<bool>> visited(graph.size(), std::vector<bool>(graph.size()));
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    int count = 0;
    std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        std::pair<int, int> cur = q.front();
        q.pop();
        count++;
        for (std::pair<int, int> dir : directions) {
            int newx = cur.first + dir.first;
            int newy = cur.second + dir.second;
            if (newx >= 0 && newx < graph.size() && newy >= 0 && newy < graph.size() && visited[newx][newy] == false && (graph[newx][newy] == color || blob[newx][newy] == true)) {
                visited[newx][newy] = true;
                q.push({newx, newy});
            }
        }    
    }
    return count;
}

int fill(std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& blob, int color) {
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    blob[0][0] = true;
    std::vector<std::vector<bool>> visited(graph.size(), std::vector<bool>(graph.size()));
    std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int count = 0;
    while (!q.empty()) {
        std::pair<int, int> cur = q.front();
        q.pop();
        count++;
        for (std::pair<int, int> dir : directions) {
            int newx = cur.first + dir.first;
            int newy = cur.second + dir.second;
            if (newx >= 0 && newx < graph.size() && newy >= 0 && newy < graph.size() && visited[newx][newy] == false && (graph[newx][newy] == color || blob[newx][newy] == true)) {
                blob[newx][newy] = true;
                visited[newx][newy] = true;
                q.push({newx, newy});
            }
        }
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<std::vector<bool>> blob(n, std::vector<bool>(n));
        std::vector<std::vector<int>> graph(n, std::vector<int>(n));
        std::string line;
        for (int j = 0; j < n; j++) {
            std::cin >> line;
            for (int k = 0; k < n; k++) {
                graph[j][k] = line[k] - '0';
            }
        }
        std::vector<int> colors(7, 0);
        
        int m = 0;
        int col = 0;
        int k = 0;
        int total = fill(graph, blob, graph[0][0]);
        // colors[graph[0][0]]++;
        int count = 0;
        while (total < n * n) {
            for (int j = 1; j <= 6; j++) {
                k = dobfs(graph, j, blob);
                if (k > m) {
                    m = k;
                    col = j;
                }
            }
            colors[col]++;
            total = m;
            count ++;
            fill(graph, blob, col);
        }
        std::cout << count << std::endl;
        for (int j = 1; j <= 6; j++) {
            std::cout << colors[j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
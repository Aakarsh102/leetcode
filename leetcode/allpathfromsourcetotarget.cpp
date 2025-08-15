#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        std::vector<int> stack;
        stack.push_back(0);
        std::vector<std::vector<int>> output;
        do_find(graph, 0, stack, output);
        return output;

        
    }
    void do_find(std::vector<std::vector<int>>& graph, int node, std::vector<int>&path, std::vector<std::vector<int>>& output ) {
        if (node == graph.size() - 1) {
            output.push_back(path);
            return;
        }
        for (int i : graph[node]) {
            path.push_back(i);
            do_find(graph, i, path, output);
            path.pop_back();
        }
    }
};
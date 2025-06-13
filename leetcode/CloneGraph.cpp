#include <unordered_map>
#include <queue>
#include <vector>
// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        std::unordered_map<int, Node*> map;
        std::queue<Node *> q;
        q.push(node);
        Node * new_cur = nullptr;
        while(!q.empty()) {
            Node * cur = q.front();
            q.pop();
            if (map.find(cur -> val) != map.end()) {
                break;
            }
            
            new_cur = new Node(cur -> val);
            for (Node * i : cur -> neighbors) {
                if (map.find(i -> val) == map.end()) {
                    q.push(i);
                } else {
                    (new_cur -> neighbors).push_back(map[i -> val]);
                    (map[i -> val] -> neighbors).push_back(new_cur);
                }
            }
            map[new_cur -> val] = new_cur;
        }
        return map[node -> val];
    }
};
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void markParents(TreeNode* root,
                     std::unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root) return;
        if (root->left) {
            parent[root->left] = root;
            markParents(root->left, parent);
        }
        if (root->right) {
            parent[root->right] = root;
            markParents(root->right, parent);
        }
    }

    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        std::unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        std::unordered_set<TreeNode*> visited;
        std::queue<std::pair<TreeNode*,int>> q;
        
    
        q.push({target, 0});
        visited.insert(target);

        std::vector<int> ans;
        auto tryPush = [&](TreeNode* nei, int dist) {
                if (nei && !visited.count(nei)) {
                    visited.insert(nei);
                    q.push({nei, dist + 1});
                }
            };


        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist == K) {
                ans.push_back(node->val);
                continue;
            }
            tryPush(node->left, dist);
            tryPush(node->right, dist);
            if (parent.count(node)) {
                tryPush(parent[node], dist);
            }
        }

        return ans;
    }
};
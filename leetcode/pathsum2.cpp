/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> ret;
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<int> store;
        recurse(root, 0, targetSum, store);
        
        return ret;
    }
    void recurse (TreeNode* root, int sum, int targetSum, std::vector<int>& store) {
        if (root == nullptr) {
            return;
        }
        sum += root -> val;
        store.push_back(root -> val);
        if (root -> left == nullptr && root -> right == nullptr) {
            if (sum == targetSum) {
                ret.push_back(store);
            }
        }
        recurse(root -> left, sum, targetSum, store);
        recurse(root -> right, sum, targetSum, store);
        store.pop_back();
    }
};
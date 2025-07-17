/*
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
    std::vector<int> ret;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            
            return false;
        }
        targetSum -= root -> val;
        if (root -> right == nullptr && root -> left == nullptr) {
            if (targetSum == 0) {
                return true;
            }
        }
        return hasPathSum(root -> left, targetSum) || hasPathSum(root -> right, targetSum);
    }


};
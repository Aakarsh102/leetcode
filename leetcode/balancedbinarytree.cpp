#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int n = height(root);
        if (n == -1) {
            return false;
        }
        return true;
    }
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = height(root -> left);
        int right = height(root -> right);
        if (left == -1 || right == -1) {
            return -1;
        }
        if (std::max(left,right) - std::min(left,right) > 1) {
            return -1;
        }
        return std::max(left, right) + 1;
    }
};
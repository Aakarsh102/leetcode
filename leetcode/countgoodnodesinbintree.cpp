// Definition of a binary tree node.
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
    int goodNodes(TreeNode* root) {
        int count = 0;
        rec(root, root -> val, count);
        return count;
    }
    void rec(TreeNode* root, int val, int& count) {
            if (root -> val >= val) {
                count++;
                val = root -> val;
            }
            if (root -> left != nullptr) {
                rec(root -> left, val, count);
            }
            if (root -> right != nullptr) {
                rec(root -> right, val, count);
            }
        };
};
#include <climits>

//Definition for a binary tree node.
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
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    bool validate(TreeNode* root, long big, long small) {
        if (root == nullptr) {
            return true;
        }
        if (!(root -> val > big && root -> val < small)) {
            return false;
        }

        return validate(root -> right,root -> val,small) && validate(root -> left,big,  root -> val);
        
        
        
    }
};
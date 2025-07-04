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
        void flatten(TreeNode* root) {
            if (root == nullptr) {
                return;
            }
            flatten(root -> right);
            flatten(root -> left);
           
            TreeNode* store = root -> right;
            root -> right = root -> left;
            TreeNode* k = root;
            root -> left = nullptr;
            while (k -> right != nullptr) {
                k = k -> right;
            }
    
            k -> right = store;
                    
        }
    
    };
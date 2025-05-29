#include <cstddef>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        // auto check = [&]() {
            
        // };
        int ret;
        while (cur != nullptr) { 
            if (cur -> val < q -> val && cur -> val < p -> val) {
                //ret = 1;
                cur = cur -> right;
            } else if (cur -> val > q -> val && cur -> val > p -> val) {
                //ret = -1;
                cur = cur -> left;
            }
            else {
                //ret = 0;
                return cur;
            }
            // if (ret == -1) {
            //     cur = cur -> left;
            // } else if (ret == 1) {
            //     cur = cur -> right;
            // } else {
            //     return cur;
            // }
        }
        return nullptr;
    }
};
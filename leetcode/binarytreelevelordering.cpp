
//Definition for a binary tree node.
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<TreeNode* > one;
        std::vector<TreeNode* > two;
        std::vector<std::vector<int>> res;
        one.push_back(root);
        std::vector<int> k;
        k.push_back(root -> val);
        res.push_back(k);
        while (!one.empty()) {
            k.clear();
            for (TreeNode * i : one) {
                if (i -> left != nullptr) {
                    two.push_back(i -> left);
                }
                if (i -> right != nullptr) {
                    two.push_back(i -> right);
                }
            }
            if (!two.empty()) {
                for (TreeNode* i : two) {
                    k.push_back(i -> val);
                }
                res.push_back(k);
            }
            
            std::swap(one, two);
            two.clear();
        }
        return res;
    }
};
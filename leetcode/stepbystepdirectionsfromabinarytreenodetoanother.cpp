
#include <string>
#include <vector>
/**
 * Definition for a binary tree node.*/
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
    std::string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *foun;
        int a = found(root, startValue, destValue, foun);
        std::string to;
        std::string from;

        if (a == 0) {
            findPath(foun, destValue, to);
            
            return to;
        } else if (a == 1) {
            findPath(foun, startValue, from);
            std::vector<char> k(from.size(), 'U');
            std::string s(k.begin(), k.end());
            return s;
        } else {
            findPath(foun, startValue, from);
            findPath(foun, destValue, to);
            std::vector<char> k(from.size(), 'U');
            std::string s(k.begin(), k.end());
            return s + to;
        }

    }
    int found(TreeNode* root, int a, int b, TreeNode*& foun) {
        if (root == nullptr) {
            return -1;
        }
    
        if (root -> val == a ) {
            foun = root;
            return 0;
        } 
        if (root -> val == b) {
            foun = root;
            return 1;
        }
        int r = found(root -> right, a, b, foun);
        if (r == 3) {
            return 3;
        }
        int l = found(root -> left, a, b, foun);
        if (l == 3) {
            return 3;
        }
        if (r >= 0 && l >= 0) {
            foun = root;
            return 3;
        }
        return std::max(r, l);
    }
    bool findPath(TreeNode* root, int target, std::string& path) {
        if (!root) return false;

        if (root->val == target) return true;

        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();

        return false;
    }
};
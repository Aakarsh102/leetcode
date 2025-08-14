/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* cur = root;
        TreeNode* prev = root;
        while (cur && cur -> val != key) {
            if (key < cur -> val) {
                prev = cur;
                cur = cur -> left;
            } else if (key > cur -> val) {
                prev = cur;
                cur = cur -> right;
            } else {
                break;
            }
        }
        if (cur == nullptr) {
            return root;
        }
        TreeNode* thing;
        if (cur == prev) {
            if (cur -> left == nullptr && cur -> right == nullptr) {
                return nullptr;
            }
            thing = findPrefix(cur);
            if (thing) {
                cur -> val = thing -> val;
            } else {
                return cur -> left;
            }
            return cur;
        }
        thing = findPrefix(cur);
        if (thing == nullptr) {
            if (prev -> right == cur) {
                prev -> right = cur -> left;
            } else {
                prev -> left = cur -> left;
            }
            return root;
        } else {
            cur -> val = thing -> val;
        }
        return root;

    }
    TreeNode* findPrefix(TreeNode* root) {
        if (root -> right == nullptr) {
            return nullptr;
        }
        TreeNode *prev = root;
        TreeNode* cur = root -> right;
        while (cur -> left != nullptr) {
            prev = cur;
            cur = cur -> left;
        }
        if (prev == root) {
            prev -> right = cur -> right;
        } else {
            prev -> left = cur -> right;
        }
        return cur;
    }
};
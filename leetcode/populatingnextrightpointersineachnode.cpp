#include <stdlib.h>
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        recurse(root);
        return root;
    }
    void doit(Node* root) {
        if (root -> right == nullptr) {
            return;
        }
        Node* r = root -> right;
        Node* l = root -> left;
        l -> next = r;
        while (r -> right != nullptr) {
            r = r -> left;
            l = l -> right;
            l -> next = r;
        }
    }
    void recurse(Node* root) {
        if (root == nullptr) {
            return;
        }
        doit(root);
        recurse(root -> left);
        recurse(root -> right);
    }
};
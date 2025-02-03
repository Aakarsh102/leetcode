/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head -> next == nullptr) {
            TreeNode *new_r = new TreeNode(head -> val);
            return new_r;
        }
        if ((head -> next) -> next == nullptr) {
            TreeNode *new_r = new TreeNode(head -> val);
            new_r -> right = new TreeNode((head -> next) -> val);
            return new_r;
        }
        ListNode *median = find_median(head);
        TreeNode *root = new TreeNode(median -> val);
        
        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(median -> next);

        return root;      
    }

    ListNode *find_median(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *p = head;
        while (p2 -> next != nullptr && p2 -> next -> next != nullptr) {
            p = p1;
            p1 = p1 -> next;
            p2 = (p2 -> next) -> next;
        }
        p -> next = nullptr;
        return p1;
    }
    
};
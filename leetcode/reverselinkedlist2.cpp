
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (left == right) {
                return head;
            }
            ListNode* left_ptr = nullptr;
            ListNode* right_ptr = nullptr;
            ListNode* second = nullptr;
            int i = 1;
            ListNode * cur = head;
            while (cur != nullptr) {
                if (i == left - 1) {
                    left_ptr = cur;
                }
                if (i == right + 1) {
                    right_ptr = cur;
                    break;
                }
                if (i == right) {
                    second = cur;
                }
                i++;
                cur = cur -> next;
            }

            
            second -> next = nullptr;
            if (left_ptr) {
                cur = left_ptr -> next;
                left_ptr -> next = nullptr;
            }
            else {
                cur = head;
            } 
            second = cur -> next;
            ListNode *new_head = cur; 
            ListNode *prev = nullptr;
            while (second != nullptr) {
                cur -> next = prev;
                prev = cur;
                cur = second;
                second = second -> next; 
            }
            cur -> next = prev;
            new_head -> next = right_ptr;
            if (left_ptr) {
                left_ptr -> next = cur;
            }
            if (left == 1) {
                head = cur;
            }
            return head;
        }
    };
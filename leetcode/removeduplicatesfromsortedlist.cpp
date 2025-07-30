//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
                if (!head) {
            return head;
        }
        ListNode* cur = head;
        ListNode* to = head -> next; 
        while (cur -> next != nullptr) {
            while (to && (cur -> val == to -> val)) {
                to = to -> next;
            }
            cur -> next = to;
            if (cur -> next == nullptr) {
                return head;
            }
            cur = cur -> next;
            to = cur -> next ;
        }
        return head;
        
    }
};

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr || k == 1) {
            return head;
        }
        ListNode dummy = ListNode(-1, head);
        ListNode *before = &dummy;

        function<void(ListNode *, ListNode *)> reverse = [&](ListNode * start, ListNode *end) {
            ListNode *cur = start;
            ListNode *nex = start -> next;
            start -> next = end -> next;
            
            ListNode *temp;
            while (cur != end) {
                temp = nex -> next;
                nex -> next = cur;
                cur = nex;
                nex = temp;
            }
        };


        ListNode *start = head;
        ListNode *end = head;
        int i = 1;
        while (start != nullptr) {
            while (i < k) {
                end = end -> next;
                if (end == nullptr) {
                    return dummy.next;
                }                
                i++;
            }

            i = 1;
            before -> next = end;
            reverse(start, end);
            before = start;
            start = start -> next;
            end = start;
        }
        return dummy.next;
        // remember that before -> next should be en


        
    }
};

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head -> next == nullptr) {
            return head; 
        }
        int len = 1;
        ListNode *cur = head;
        while (cur -> next != nullptr) {
            cur = cur -> next;
            len++;
        }
        int rot = k % len;
        if (rot == 0 ) {
            return head;
        }
        cur -> next = head;
        int i = 1;
        cur = head;
        while (len - i > rot) {
            cur = cur -> next;
            i++;
        }
        ListNode *ne = cur -> next;
        cur -> next = nullptr;
        head = ne;
        return head;

    }
};
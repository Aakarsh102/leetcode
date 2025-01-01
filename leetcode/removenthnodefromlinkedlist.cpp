
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head -> next == nullptr) {
            return nullptr;
        }
        ListNode *cur = head;
        while (cur != nullptr) {
            n--;
            cur = cur -> next;
        }
        if (n == 0) {
            head = head -> next;
            return head;
        }
        cur = head;
        while (n < -1) {
            cur = cur -> next;
            n++;
        }
        cur -> next = cur -> next -> next;
        return head;
    }
};
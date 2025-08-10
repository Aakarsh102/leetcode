struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head -> next == nullptr) {
            return nullptr;
        }
        ListNode* mid = head;
        ListNode* bef = head;
        ListNode* before = head;
        while (bef != nullptr && bef -> next != nullptr) {
            before = mid;
            mid = mid -> next;
            bef = bef -> next -> next;
        }
        before -> next = mid -> next;
        return head;
    }
};
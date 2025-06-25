
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *cur = head;
        while (cur != nullptr) {
            if (cur -> val == -1000000) {
                return true;
            }
            cur -> val = -1000000;
            cur = cur -> next;
        }
        return false;
    }
};
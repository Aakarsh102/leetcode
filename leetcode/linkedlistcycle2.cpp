/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        int start = 1000000;
        while (head -> next != nullptr) {
            if (head -> val > 100000) {
                head -> val -= start;
                return head;
            }
            head -> val += start;
            head = head -> next; 
        }
        return nullptr;
    }
};
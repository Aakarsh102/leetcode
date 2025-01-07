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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        if (head -> next -> next == nullptr) {
            head -> next -> next = head;
            head = head -> next;
            head -> next -> next = nullptr;
            return head;
        }


        ListNode *cur = head -> next -> next;
        ListNode *prev = head;

        head -> next -> next = head;
        head = head -> next;
        head -> next -> next = cur;

        prev = head -> next;
        cur = prev -> next -> next;
        while (cur != nullptr) {
            prev -> next -> next = cur -> next;
            cur -> next = prev -> next;
            prev -> next = cur;
            prev = cur -> next;
            if (prev -> next != nullptr) {
                cur = prev -> next -> next;
            } else {
                break;
            }

        }
        return head;
    }
};
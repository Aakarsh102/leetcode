
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode* head_even = head -> next;
        ListNode* cur = head_even;
        ListNode* cur2 = head;
        ListNode* tempeven = head -> next;
        ListNode* tempodd = head;
        while (true) {
            tempodd = cur -> next;
            if (tempodd) {
                cur -> next = tempodd -> next;
            }
            // cur -> next = tempodd -> next;
            cur2 -> next = tempodd;
            if (cur -> next == nullptr || cur2 -> next == nullptr) {
                break;
            }
            cur = cur -> next;
            cur2 = cur2 -> next; 
        } 
        // std::cout << head -> val;
        // std::cout << head -> next -> val;
        // std::cout << head -> next -> next ->val;
        // std::cout << cur2 ->val;
        if (cur2 -> next) {
            cur2 -> next -> next = head_even;
        } else {
            cur2 -> next = head_even;
        }
        return head;
    }
};
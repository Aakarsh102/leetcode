
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
        if(head == nullptr || head -> next == nullptr) {
            return nullptr;
        }
        ListNode *prev = nullptr;
        ListNode *np = head -> next;

        while (np != nullptr) {
            head -> next = prev;
            prev = head;
            head = np;
            np = np -> next;
        }
        head -> next = prev;
        
        np = head;
        prev = nullptr;
        while (n > 1) {
            prev = np;
            np = np -> next;
            n--;
        }
        if (prev != nullptr) {
            prev -> next = np -> next;
        } else {
            head = head -> next;
        }
        return head;


    }
};
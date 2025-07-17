
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head -> next == nullptr) {
            return head;
        }
        ListNode *median = findmedian(head);
        ListNode *next = median -> next;
        median -> next = nullptr;
        ListNode *one = sortList(head);
        ListNode *two = sortList(next);
        return merge(one, two);

    }

    ListNode * findmedian(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        while (p2 -> next != nullptr && (p2 -> next) -> next != nullptr) {
            p1 = p1 -> next;
            p2 = (p2 -> next) -> next;
        }

        return p1;
    }

    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *head;
        ListNode *cur;
        if (a -> val <= b -> val) {
            head = a;
            a = a -> next;
        } else {
            head = b;
            b = b-> next;
        }
        cur = head;
        while (a != nullptr && b != nullptr) {
            if (a -> val <= b -> val) {
                cur -> next = a;
                a = a -> next;
            } else {
                cur -> next = b;
                b = b -> next;
            }
            cur = cur->next;
        }
        if (a == nullptr) {
            cur -> next = b;
            return head;
        } else {
            cur -> next = a;
            return head;
        }
    }
};
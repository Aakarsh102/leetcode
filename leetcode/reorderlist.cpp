struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return;
        }
        //ListNode *median = nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;

            slow = slow -> next;
        }

        fast = nullptr;
        ListNode * head_2 = slow;
        ListNode * store;
        while (slow != nullptr) {
            store = slow -> next;
            slow -> next = fast;
            fast = slow;
            slow = store;
            // head_2 = fast;
        }
        // if (fast == nullptr) {
            
        // }
        head_2 -> next = nullptr;
        
        slow = head;
        while (true) {
            if (slow -> next == head_2) {
                slow -> next = nullptr;
                break;
            }
            slow = slow -> next;

        }
        slow = head;
        // fast = head_2;
        ListNode * store_2;
        while (true) {
            store = slow -> next;
            store_2 = fast -> next;
            slow -> next = fast;
            if (store == nullptr) {
                return;
            }
            fast -> next = store;
            slow = store;
            fast = store_2;

        }
        return;
        
    }
};
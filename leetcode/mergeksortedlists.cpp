#include <vector>

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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        while(lists.size() != 1) {
            std::vector<ListNode *> store;
            for (int i = 0; i < lists.size(); i = i + 2) {
                if (i + 1 < lists.size()) {
                    ListNode* k = mer(lists[i], lists[i+1]);
                    store.push_back(k);
                } else {
                    store.push_back(lists[i]);
                }
            }
            std::swap(lists, store);
        }
        return lists[0];
        
    }
    ListNode* mer(ListNode*& list1, ListNode*& list2) {
        if (list1 == nullptr) {
            return list2;
        } 
        if (list2 == nullptr) {
            return list1;
        }
        ListNode * head;
        if (list1 -> val > list2 -> val) {
            head = list2;
            list2 = list2 -> next;
        }
        else {
            head = list1;
            list1 = list1 -> next;
        }
        ListNode * cur = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1 -> val > list2 -> val) {
                cur -> next = list2;
                list2 = list2 -> next;
                cur = cur -> next;
            }
            else {
                cur -> next = list1;
                list1 = list1 -> next;
                cur = cur -> next;
            }
        }
        if ( list1 == nullptr) {
            cur -> next = list2;
        }
        else if (list2 == nullptr) {
            cur -> next = list1;
        }
        return head;
    }
};
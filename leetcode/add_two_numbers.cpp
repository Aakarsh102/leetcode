#include <iostream>
#include <vector>
 #include <cmath>
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 


#include <cmath>
//  Definition for singly-linked list.
//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i = 0;
        int carry = 0;
        int temp = 0;
        ListNode *new_node = nullptr;
        ListNode *sum = nullptr;
        ListNode *head = nullptr;
        ListNode *n1 = l1;
        ListNode *n2 = l2;
        while (n1 != nullptr && n2 != nullptr) {
            temp = n1->val + n2->val + (carry != temp);
            carry = temp % 10;
            new_node = new ListNode(carry, nullptr);
            (sum == nullptr) ? sum = new_node : sum->next = new_node;
            sum = new_node;
            if (head == nullptr) {
                head = sum;
            }
            //sum += carry * pow(10, i)
            n1 = n1->next;
            n2 = n2->next;
            i++;
        }
        if (n1 == nullptr) {
            while (n2 != nullptr) {
                temp = n2->val + (carry != temp);
                carry = temp % 10;
                new_node = new ListNode(carry, nullptr);
                (sum == nullptr) ? sum = new_node : sum->next = new_node;
                sum = new_node;
                n2 = n2->next;
                i++;
            }
            if (carry != temp) {
                sum -> next = new ListNode(1, nullptr);
            }
            return head;
        }
        while (n1 != nullptr) {
                temp = n1->val + (carry != temp);
                carry = temp % 10;
                new_node = new ListNode(carry, nullptr);
                (sum == nullptr) ? sum = new_node : sum->next = new_node;
                sum = new_node;
                n1 = n1->next;
                i++;
            }
            if (carry != temp) {
                sum -> next = new ListNode(1, nullptr);
            }
            return head;
        
    }
    
};

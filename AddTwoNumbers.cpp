#include <iostream>
#include <cmath>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *result = new ListNode();
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        int sum = 0;
        int count = 0;
        bool flag1 = true;
        bool flag2 = true;
        if (head1 == nullptr && head2 == nullptr) {
            return;
        }
        if (head1 == nullptr) {
            flag1 = false;
        }
        if (head2 == nullptr) {
            flag2 = false;
        }
        int val = 0;
        int carry = 0;
        while (true) {
            val = 0;
            if (flag2) {
                val += head2 -> val;
            }
            if (flag1){
                val += head1 -> val;
            }
            val = val + carry;
            carry = 0;
            carry = (int) (val/10);
            val = (val%10) * (int) (pow(10, count));
            sum += val;
            if (flag1) {
                head1 = head1 -> next;
                if (head1 == nullptr) {
                    flag1 = false;
                }
            }
            if (flag2) {
                head2 = head2 -> next;
                if (head2 == nullptr) {
                    flag2 = false;
                }
            }
            if (!flag1 && !flag2 && carry == 0) {
                break;
            }
            std::cout << "hello" << "\n";
            count++;
        }
        std::cout << sum << "\n";

        
    }
};

int main () {
    Solution s;
    ListNode *l1 = new ListNode(9);
    l1 -> next = new ListNode(9);
    l1 -> next -> next = new ListNode(9);
    ListNode *l2 = new ListNode(9);
    l2 -> next = new ListNode(9);
    
    s.addTwoNumbers(l1, l2);
    return 0;
}
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> store;
        Node* cur = head;
        while (cur != nullptr) {
            store[cur] = new Node(cur -> val);
            cur = cur -> next;
        }
        Node* new_head = store[head];
        new_head -> random = store[head -> random];
        Node* cur_new = new_head;
        cur = head;
        while (cur -> next != nullptr) {
            cur_new -> next = store[cur -> next];
            cur_new -> next -> random = store[cur -> next -> random != nullptr ? cur -> next -> random : nullptr];

            //cur_new -> next -> random = cur -> next -> random;
            //cur_new -> next -> val = cur -> next -> val;
            cur_new = cur_new -> next;
            cur = cur -> next;
        }

        return new_head;

    }
};
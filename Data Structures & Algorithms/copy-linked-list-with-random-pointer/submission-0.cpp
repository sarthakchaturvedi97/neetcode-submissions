/*
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        return NULL;

        Node* current = head;
        while(current)
        {
            Node* nxt = current->next;
            current->next = new Node(current->val);
            current = current->next;
            current->next = nxt;
            current = current->next;
        }

        current = head;
        while(current)
        {
            Node* nxt = current->next;
            nxt->random = current->random?current->random->next:current->random;
            current = current->next->next;
        }

        current = head;
        Node* result = new Node(INT_MIN);
        Node* answer = result;
        while(current)
        {
            Node* nxt = current->next;
            result->next = nxt;
            current->next = nxt->next;
            result = result->next;
            current = current->next;
        }
        result->next = NULL;
        return answer->next;
    }
};
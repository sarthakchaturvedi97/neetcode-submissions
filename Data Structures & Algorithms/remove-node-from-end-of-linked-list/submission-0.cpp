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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !n)
        return head;

        ListNode* temp = head, *current = head, *prev = NULL;
        while(n--)
        temp = temp->next;

        while(temp)
        {
            prev = current;
            current = current->next;
            temp = temp->next;
        }
        if(prev)
        prev->next = current->next;
        else
        head = head->next;
        return head;
    }
};

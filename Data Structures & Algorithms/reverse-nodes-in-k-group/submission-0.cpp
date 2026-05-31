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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1)
        return head;

        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *curr = dummy, *prev = dummy;
        int count = 0;
        while(curr->next)
        {
            ++count;
            curr = curr->next;
        }

        while(count>=k)
        {
            curr = prev->next;
            ListNode* n = curr->next;
            for(int i=1;i<k;i++)
            {
                curr->next = n->next;
                n->next = prev->next;
                prev->next = n;
                n = curr->next;
            }
            count-=k;
            prev = curr;
        }
        return dummy->next;
    }
};
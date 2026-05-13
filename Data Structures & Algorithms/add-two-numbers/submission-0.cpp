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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* temp = new ListNode(INT_MIN);
        ListNode* result = temp;
        while(l1 || l2)
        {
            sum = (l1?l1->val:0)+(l2?l2->val:0)+carry;
            temp->next = new ListNode(sum%10);
            carry = sum/10;
            if(l1)
            l1 = l1->next;
            if(l2)
            l2 = l2->next;
            temp = temp->next;
        }

        if(carry)
        {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }
        temp->next = NULL;
        return result->next;
    }
};
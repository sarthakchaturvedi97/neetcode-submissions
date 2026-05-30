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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
        return;

        int count = 0;
        stack<ListNode*> st;
        ListNode* curr = head;
        while(curr)
        {
            ++count;
            st.push(curr);
            curr = curr->next;
        }

        curr = head;
        for(int i=0;i<count/2;i++)
        {
            ListNode *ans = st.top();
            st.pop();
            ans->next = curr->next;
            curr->next = ans;
            curr = curr->next->next;
        }
        curr->next = NULL;
    }
};
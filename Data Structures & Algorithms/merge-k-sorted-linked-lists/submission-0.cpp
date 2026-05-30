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
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(!a)
        return b;

        if(!b)
        return a;

        if(a->val<b->val)
        {
            a->next = merge(a->next,b);
            return a;
        }
        else
        {
            b->next = merge(a,b->next);
            return b;
        }

    }
    ListNode* mergeSort(vector<ListNode*>& lists, int st, int end)
    {
        if(st == end)
        return lists[st];

        if(st<end)
        {
            int mid = st + (end-st)/2;
            ListNode* a = mergeSort(lists,st,mid);
            ListNode* b = mergeSort(lists,mid+1,end);
            return merge(a,b);
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(lists,0,lists.size()-1);
    }
};
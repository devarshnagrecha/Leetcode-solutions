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
    
    ListNode* merge2Lists(ListNode* a, ListNode* b)
    {
        if (!a)
            return b;
        if (!b)
            return a;
        
        ListNode * temp = (a->val > b->val) ? b:a;
        temp -> next = (a->val > b->val) ? merge2Lists(b->next,a) : merge2Lists(a->next,b);
        return temp;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.size()==0)
            return NULL;
        
        ListNode * head = lists[0];
        for (int i=1; i<lists.size(); i++)
        {
            head = merge2Lists(head, lists[i]);
        }
        return head;
    }
};
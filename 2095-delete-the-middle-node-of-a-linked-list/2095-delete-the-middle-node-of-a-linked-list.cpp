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
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode * slow = head, * fast = head;
        
        while (fast && fast->next && fast->next->next && fast->next->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if (slow->next==NULL)
            return NULL;
        slow->next = slow->next->next;
        
        return head;
    }
};
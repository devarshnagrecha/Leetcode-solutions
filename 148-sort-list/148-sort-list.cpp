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
    ListNode* sortList(ListNode* head) 
    {
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* temp = head, *ptr = head;
        vector <int> arr;
        
        while (temp!=NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        sort (arr.begin(), arr.end());
        
        for (int i=0; i<arr.size(); i++)
        {
            ptr->val = arr[i];
            ptr=ptr->next;
        }
        
        return head;
    }
};
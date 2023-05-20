//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse (Node * head)
    {
        Node * prev = NULL, * curr = head;
        while(curr)
        {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        if (!head)
            return head;
            
        Node * newHead = reverse(head);
        Node * temp = newHead;
        
        int carry = 1;
        
        while(carry && temp)
        {
            int q,r;
            r = (temp->data + carry)%10;
            q = (temp->data + carry)/10;
            
            temp->data = r;
            carry = q;
            
            if (temp->next==NULL && carry)
                break;
            temp = temp->next;
        }
        
        if (carry)
        {
            Node * ptr = new Node(carry);
            temp->next = ptr;
        }
        
        Node * ret = reverse(newHead);
        return ret;
        
        // Your Code here
        // return head of list after adding one
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
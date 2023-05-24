//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    int priority(char c)
    {
        if (c=='^')
            return 3;
        if (c=='/' || c=='*')
            return 2;
        if (c=='+' || c=='-')
            return 1;
    }
    
    string infixToPostfix(string s) 
    {
        string ans = "";
        
        stack <char> st;
        int n = s.size();
        
        for (int i=0; i<n; i++)
        {
            if ((s[i]<='z' && s[i]>='a') || (s[i]>='A' && s[i]<='Z') || (s[i]<='9' && s[i]>='0'))
                ans += s[i];
                
            else if (s[i]=='(')
                st.push(s[i]);
            
            else if (s[i]==')')
            {
                while(st.top()!='(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            
            else
            {
                while( !st.empty() && st.top()!='(' && (priority(s[i]) <= priority(st.top())) )
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            
        }
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        return ans;
        // Your code here
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) 
    {
        stack <string> st;
        
        for (auto it:exp)
        {
            if ((it>='a' && it<='z')||(it>='A' && it<='Z'))
            {
                string x = "";
                x+=it;
                st.push(x);
            }
            
            else
            {
                string a = st.top();
                st.pop();
                
                string b = st.top();
                st.pop();
                
                string x = "";
                x+=it;
                st.push("(" + b + x + a + ")");
            }
        }
        
        string ans = st.top();
        return ans;
        // Write your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends
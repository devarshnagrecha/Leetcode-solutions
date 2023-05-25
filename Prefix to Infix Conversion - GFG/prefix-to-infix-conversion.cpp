//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) 
    {
        stack <string> st;
        
        for (int i=pre_exp.size()-1; i>=0; i--)
        {
            char it = pre_exp[i];
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
                st.push("(" + a + x + b + ")");
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            string ans = "";
            int n=s.size();
            for (int i=n-1; i>=0;)
            {
                if (s[i]=='+' || s[i]=='/' || s[i]=='*' || s[i]=='-')
                {
                    ans+=s[i];
                    i--;
                }
                
                else
                {
                    string temp;
                    while(s[i]<='9' && s[i]>='0')
                    {
                        temp+=s[i];
                        i--;
                    }
                    reverse(temp.begin(),temp.end());
                    ans+=temp;
                }
                
            }
            
            return ans;
            //code here.
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
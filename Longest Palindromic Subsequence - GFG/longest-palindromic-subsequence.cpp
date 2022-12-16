//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) 
    {
        string t = s;
        reverse(t.begin(), t.end());
        
        int n=s.size(),dp[n+1][n+1];
        
        for (int i=0; i<=n; i++)
        {
            for (int j=0; j<=n; j++)
            {
                if (i==0 || j==0)
                    dp[i][j]=0;
                
                else if (s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
        //code here
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
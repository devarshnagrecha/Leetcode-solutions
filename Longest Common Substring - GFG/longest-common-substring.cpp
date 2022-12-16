// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int x, int y)
    {
        int dp[x+1][y+1], ans = 0;
        
        for (int i=0; i<=x; i++)
        {
            for (int j=0; j<=y; j++)
            {
                if (i==0||j==0)
                {
                    dp[i][j]=0;
                }
                
                else if (s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans = max (ans,dp[i][j]);
                }
                
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        
        return ans;
        // your code here
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) 
    {
        vector< vector<int>> dp(n, vector<int>(m,0));
        dp[0][0]=1;
        int mod = 1e9+7;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j])
                {
                    if (i+1<n && grid[i+1][j])
                        dp[i+1][j] = (dp[i+1][j]%mod + dp[i][j]%mod)%mod;
                    if (j+1<m && grid[i][j+1])
                        dp[i][j+1] = (dp[i][j+1]%mod + dp[i][j]%mod)%mod;
                }
                
            }
        }
        
        // for (int i=0; i<n; i++)
        // {
        //     for (int j=0; j<m; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
            
        //     cout << endl;
        // }
        return dp[n-1][m-1];
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends
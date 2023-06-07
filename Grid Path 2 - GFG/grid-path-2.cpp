//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int totalWays(int a, int b, vector<vector<int>>& grid) 
    {
        int mod = 1e9+7;
        vector<vector<int>> dp(a, vector<int>(b,0));
        for (int i=0; i<a; i++)
        {
            if (!grid[i][0])
            dp[i][0]=1;
        }
        for (int j=0; j<b; j++)
        {
            if (!grid[0][j])
            dp[0][j]=1;
        }
        
        for (int i=1; i<a; i++)
        {
            for (int j=1; j<b; j++)
            {
                if (!grid[i][j])
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%mod;
                else
                dp[i][j]=0;
            }
        }
        return dp[a-1][b-1]%mod;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
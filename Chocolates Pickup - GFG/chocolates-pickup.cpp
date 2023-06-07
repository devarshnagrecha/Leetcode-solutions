//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        if (i<0 || j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size() || i>=grid.size())
            return 0;
        
        if (dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
            
        if (i==grid.size()-1)
        {
            if (j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        int del[3] = {-1,0,1};
        int maxi = 0;
        for (int k=0; k<3; k++)
        {
            for (int j=0; j<3; j++)
            {
                if (j1==j2)
                {
                    maxi = max(maxi, grid[i][j1]+solve(i+1,j1+del[k],j2+del[j],grid,dp));
                }
                else
                {
                    maxi = max(maxi, grid[i][j1]+grid[i][j2]+solve(i+1,j1+del[k],j2+del[j],grid,dp));
                }
            }
        }
        return dp[i][j1][j2]=maxi;
        
    }
    int solve(int n, int m, vector<vector<int>>& grid) 
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m,-1)));
        return solve(0,0,m-1,grid,dp);
        // code here
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
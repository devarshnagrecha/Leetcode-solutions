//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isValid (int i, int j, vector<vector<int>> &grid, int n, int m)
    {
        if (i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
            return false;
        grid[i][j]=0;
        return true;
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) 
    {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        queue <pair<int,int>> q;
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if (grid[i][j]==1)
                    {
                        q.push({i,j});
                        grid[i][j]=0;
                    }
                    
                }
            }
        }
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int i = it.first;
            int j = it.second;
            
            if (isValid(i+1,j,grid,n,m))
                q.push({i+1,j});
            if (isValid(i,j+1,grid,n,m))
                q.push({i,j+1});
            if (isValid(i-1,j,grid,n,m))
                q.push({i-1,j});
            if (isValid(i,j-1,grid,n,m))
                q.push({i,j-1});
        }
        
        for (int i=1; i<n; i++)
        {
            for (int j=1; j<m; j++)
            {
                if (grid[i][j]==1)
                {
                    ans++;
                }
                
            }
        }
        
        return ans;
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
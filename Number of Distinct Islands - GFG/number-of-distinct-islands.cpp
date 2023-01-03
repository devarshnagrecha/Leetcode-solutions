//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs (int i, int j, vector <vector <bool>> &vis, vector<vector<int>>& grid, vector<pair<int,int>> &v, int row0, int col0)
    {
        int n = grid.size(), m = grid[0].size();
        
        if (i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || vis[i][j])
            return;
        
        vis[i][j]=true;
        v.push_back({i-row0,j-col0});
        
        dfs(i+1,j,vis,grid,v,row0,col0);
        dfs(i,j+1,vis,grid,v,row0,col0);
        dfs(i,j-1,vis,grid,v,row0,col0);
        dfs(i-1,j,vis,grid,v,row0,col0);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        
        set <vector <pair <int,int>> > ans;
        vector <vector <bool>> vis(n,vector<bool>(m,false));
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>> v;
                    dfs (i,j,vis,grid,v,i,j);
                    ans.insert(v);
                }
            }
        }
        
        return ans.size();
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
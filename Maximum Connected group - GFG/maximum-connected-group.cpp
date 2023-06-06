//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DSU {
public:

    vector<int>par,rank,size;
    DSU(int n)
    {
        par.resize(n);
        rank.resize(n,0);
        size.resize(n,1);
        for (int i=0; i<n; i++)
        {
            par[i]=i;
        }
    }
    
    int findParent(int x)
    {
        if (x==par[x])
            return x;
        return par[x]=findParent(par[x]);
    }
    
    void unionByRank(int u, int v)
    {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if (parV==parU)
            return;
            
        if (rank[parU]>rank[parV])
        {
            par[parV] = parU;
        }
        
        else if (rank[parV]>rank[parU])
        {
            par[parU] = parV;
        }
        
        else
        {
            rank[parV]++;
            par[parU] = parV;
        }
    }
    
    void unionBySize(int u, int v)
    {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if (parV==parU)
            return;
            
        if (size[parU]>size[parV])
        {
            par[parV] = parU;
            size[parU]+=size[parV];
        }
        
        else 
        {
            par[parU] = parV;
            size[parV]+=size[parU];
        }
    }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m= grid[0].size();
        DSU dsu(n*m);

        vector<int>dx = {0,0,1,-1};
        vector<int>dy = {-1,1,0,0};

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j]==0)
                    continue;
                int x = i;
                int y = j;
                int node = x*m+y;

                for (int k=0; k<4; k++)
                {
                    int newx = x+dx[k];
                    int newy = y+dy[k];

                    if (newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==1)
                    {
                        int newnode = (newx*m+newy);
                        dsu.unionBySize(node, newnode);
                    } 
                }
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j]==0)
                {
                    int count = 0;
                    set<int>components;
                    for (int k=0; k<4; k++)
                    {
                        int newx = i+dx[k];
                        int newy = j+dy[k];

                        if (newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==1)
                        {
                            int newnode = (newx*m+newy);
                            components.insert(dsu.findParent(newnode));
                        } 
                    }

                    for (auto it:components)
                    {
                        count += dsu.size[it];
                    }
                    ans = max(ans,count+1);
                }
            }
        }
        return ans==0?n*m:ans;
        // code here
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends
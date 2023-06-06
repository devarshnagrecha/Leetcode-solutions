//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DSU {
    
    vector<int>par,rank,size;
public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) 
    {
        DSU dsu(n*m);
        vector<int>ans;
        int comp = 0;
        
        vector<int>dx = {0,0,1,-1};
        vector<int>dy = {1,-1,0,0};
        
        vector<vector<int>> mat(n,vector<int>(m,0));
        
        for (auto it:operators)
        {
            int x = it[0];
            int y = it[1];
            
            if (mat[x][y]==1)
            {
                ans.push_back(comp);
                continue;
            }
            mat[x][y]=1;
            int node = x*m+y;
            int curr = comp + 1;
            
            for (int i=0; i<4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                int newnode = newx*m+newy;
                
                if (newx>=0 && newy>=0 && newx<n && newy<m && mat[newx][newy])
                {
                    if (dsu.findParent(newnode)!=dsu.findParent(node))
                    {
                        curr--;
                        dsu.unionBySize(newnode,node);
                    }
                }
            }
            comp = curr;
            ans.push_back(comp);
        }
        
        return ans;
        // code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
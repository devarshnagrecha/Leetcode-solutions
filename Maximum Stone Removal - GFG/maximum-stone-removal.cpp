//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int n) 
    {
        int maxRow = 0, maxCol = 0;
        for (auto it:stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        DSU dsu(maxRow+maxCol+2);
        unordered_map<int,int>mp;
        
        for (auto it:stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1;
            dsu.unionByRank(nodeRow, nodeCol);
            mp[nodeCol]=1;
            mp[nodeRow]=1;
        }
        
        int ans = 0;
        for (auto it:mp)
        {
            if (dsu.findParent(it.first)==it.first)
            {
                ans++;
            }
                
        }
        return n-ans;
        // Code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends
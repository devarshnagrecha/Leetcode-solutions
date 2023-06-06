//{ Driver Code Starts
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
    int Solve(int n, vector<vector<int>>& edge) 
    {
        DSU dsu(n);
        
        int extraEdges=0;
        for (int i=0; i<edge.size(); i++)
        {
            if (dsu.findParent(edge[i][0])==dsu.findParent(edge[i][1]))
                extraEdges++;
            dsu.unionBySize(edge[i][0],edge[i][1]);
        }
        
        int comp = 0;
        for (int i=0; i<n; i++)
        {
            if (dsu.findParent(i)==i)
                comp++;
        }
        if (extraEdges>=comp-1)
            return comp-1;
        return -1;
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
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
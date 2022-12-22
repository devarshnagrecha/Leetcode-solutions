// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs (int u, vector<int> adj[], vector<bool> &vis, vector<bool> &callStack)
    {
        vis[u]=true;
        callStack[u]=true;
        
        for (auto it:adj[u])
        {
            if (vis[it]==false)
            {
                if (dfs(it,adj,vis,callStack)==true)
                    return true;
            }
            
            else if (callStack[it]==true)
            {
                return true;
            }
        }
        
        callStack[u]=false;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) 
    {
        vector<bool> vis(v,false),callStack(v,false);
        
        
        for (int i=0; i<v; i++)
        {
            if (vis[i]==false)
            {
                if (dfs(i,adj,vis,callStack) == true)
                    return true;
            }
        }
        
        return false;
        // code here
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
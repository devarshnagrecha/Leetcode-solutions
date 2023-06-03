//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool dfs(vector<bool>&curr, vector<bool>&vis, int i, vector<int>adj[])
    {
        vis[i]=true;
        curr[i]=true;
        
        for (auto child:adj[i])
        {
            if (!vis[child])
            {
                if (dfs(curr,vis,child,adj))
                    return true;
                    
            }
            
            else if (curr[child])
                return true;
        }
        
        curr[i]=false;
        return false;
        
    }
    
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) 
    {
        vector<bool>vis(v,false);
        vector<int>fin;
        vector<bool>curr(v,false);
        for (int i=0; i<v; i++)
        {
            if (!vis[i])
            {
                dfs(curr,vis,i,adj);
            }
        }
        
        for (int i=0; i<v; i++)
        {
            if (!curr[i])
                fin.push_back(i);
        }
        return fin;
        // code here
    }
};


//{ Driver Code Starts.

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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
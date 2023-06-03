//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
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
    bool isCyclic(int v, vector<int> adj[]) 
    {
        vector<int>vis(v,0),indegree(v,0),ans;
	    
	    queue<int>q;
	    for (int i=0; i<v; i++)
	    {
	        for (auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    for (int i=0; i<v; i++)
	    {
	        if (indegree[i]==0)
	            q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int x = q.front();
	        q.pop();
	        
	        ans.push_back(x);
	        
	        for (auto it:adj[x])
	        {
	            indegree[it]--;
	            if (indegree[it]==0)
	                q.push(it);
	        }
	    }
	    
	    return ans.size()!=v;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs (int u, vector<vector<int>> adj, int v, vector<bool>&visited)
    {
        visited[u]=true;
        
        for (int i=0; i<adj[u].size(); i++)
        {
            if (adj[u][i]==1 && visited[i]==false)
            {
                dfs(i,adj,v,visited);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int v) 
    {
        int r = adj.size(), c=adj[0].size();
        int count = 0;
        
        vector<bool>visited(v,false);
        
        for (int i=0; i<v; i++)
        {
            if (!visited[i])
            {
                dfs(i,adj,v,visited);
                count++;
            }
        }
        
        return count;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
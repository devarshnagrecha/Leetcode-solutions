//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void dfs (int u, vector<bool>&vis, stack <int> &st,vector <pair<int,int>> adj[])
    {
        vis[u]=true;
        
        for (auto it:adj[u])
        {
            if (!vis[it.first])
            {
                dfs(it.first,vis,st,adj);
            }
        }
        
        st.push(u);
    }
    
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges)
    {
        vector <pair<int,int>> adj[n];
         
        for (auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
         
        vector<bool> vis(n,false);
        stack <int> st;
         
        for (int i=0; i<n; i++)
        {
            if (!vis[i])
            {
                dfs (i,vis,st,adj);
            }
        }
        
        vector <int> dis(n,1e9);
        dis[0]=0;
        
        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            
            for (auto it:adj[u])
            {
                if (dis[it.first]>dis[u]+it.second)
                {
                    dis[it.first]=dis[u]+it.second;
                }
            }
        }
        
        for (auto &it:dis)
            if (it==1e9)
                it=-1;
        return dis;
        
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
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src)
    {
        vector <int> dis(n,1e9);
        vector <int> adj[n];
        
        for (auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        dis[src]=0;
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for (auto ct:adj[node])
            {
                if (dis[ct]>dis[node]+1)
                {
                    dis[ct]=dis[node]+1;
                    q.push(ct);
                }
            }
            
        }
        
        for (auto &it:dis)
            if(it==1e9)
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
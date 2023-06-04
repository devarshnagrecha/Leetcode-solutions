//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges)
    {
        vector<pair<int,int>>adj[n];
        for (int i=0; i<m; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<int>dis(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({0,0});
        dis[0]=0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int node = it.first, cost = it.second;
            for (auto next:adj[node])
            {
                if (cost + next.second < dis[next.first])
                {
                    dis[next.first] = next.second+cost;
                    q.push({next.first, cost + next.second});
                }
            }
        }
        
        for (auto &it:dis)
        {
            if (it==INT_MAX)
                it=-1;
        }
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
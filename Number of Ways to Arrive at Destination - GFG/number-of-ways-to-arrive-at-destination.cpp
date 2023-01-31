//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        int mod = 1e9+7;
        
        vector<vector<int>> adj[n];
        for (auto it:roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int>dis(n,1e9);
        dis[0] = 0;
        vector<int>ways(n,0);
        ways[0] = 1;
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int cost = it.first;
            int node = it.second;
            
            for (auto child:adj[node])
            {
                if (dis[child[0]] > cost+child[1])
                {
                    dis[child[0]] = cost+child[1];
                    pq.push({dis[child[0]], child[0]});
                    ways[child[0]] = ways[node];
                }
                
                else if (dis[child[0]] == cost+child[1])
                {
                    ways[child[0]] += ways[node];
                }
            }
        }
        
        return ways[n-1];
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
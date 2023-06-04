//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        vector<pair<int,int>>adj[n+1];
        for (int i=0; i<m; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int>dis(n+1,INT_MAX);
        vector<int>par(n+1,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int curr = it.second;
            int cost = it.first;
            
            if (dis[curr]<cost)
                continue;
                
            for (auto ct:adj[curr])
            {
                int next = ct.first;
                int wgt = ct.second;
                if (dis[next] > cost + wgt)
                {
                    dis[next]=cost+wgt;
                    par[next]=curr;
                    pq.push({dis[next],next});
                }
            }
        }
        
        vector<int>ans;
        int i = n;
        while(i!=1)
        {
            if (i==-1)
                return {-1};
            ans.push_back(i);
            i=par[i];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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
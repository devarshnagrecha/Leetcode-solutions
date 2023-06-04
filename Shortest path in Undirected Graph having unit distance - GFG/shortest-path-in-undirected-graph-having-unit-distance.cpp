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
        vector<int>adj[n];
        for (int i=0; i<m; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int>q;
        //vector<int>vis(n,0);
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        q.push(src);
        int curr = 1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int x = q.front();
                q.pop();
                
                for (auto it:adj[x])
                {
                    if (dis[it]>curr)
                    {
                        q.push(it);
                        dis[it]=curr;
                    }
                }
            }
            curr++;
        }
        for (auto &it:dis)
        {
            if (it==INT_MAX)
                it = -1;
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
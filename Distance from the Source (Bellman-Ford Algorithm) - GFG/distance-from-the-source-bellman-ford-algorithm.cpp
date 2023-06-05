//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) 
    {
        vector<int>dis(v,1e8);
        dis[s]=0;
        for (int i=0; i<v; i++)
        {
            for (auto it:edges)
            {
                int x = it[0];
                int u = it[1];
                int cost = it[2];
                
                if (dis[u]>dis[x]+cost)
                {
                    if(i==v-1)
                        return {-1};
                    dis[u]=dis[x]+cost;
                }
            }
        }
        
        // for (auto it:edges)
        // {
        //     int v = it[0];
        //     int u = it[1];
        //     int cost = it[2];
            
        //     if (dis[u]>dis[v]+cost)
        //     {
        //         return {-1};
        //     }
        // }
        
        return dis;
        // Code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
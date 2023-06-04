//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        vector<int>dis(n,INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> >q;
        q.push({0,s});
        dis[s]=0;
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            
            int node = it[1], cost = it[0];
            for (auto next:adj[node])
            {
                if (cost + next[1] < dis[next[0]])
                {
                    dis[next[0]] = next[1]+cost;
                    q.push({cost + next[1],next[0]});
                }
            }
        }
        
        for (auto &it:dis)
        {
            if (it==INT_MAX)
                it=-1;
        }
        return dis;
        // Code here
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
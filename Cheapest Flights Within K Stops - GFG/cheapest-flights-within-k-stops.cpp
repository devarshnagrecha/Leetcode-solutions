//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  
    {
        vector<vector<int>> adj[n];
        
        for (auto it:flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
            //adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector <int> dist(n,1e9);
        dist[src]=0;
        k++;
        
        queue<vector<int>>q;
        q.push({src,0});
        
        while(!q.empty() && k)
        {
            int x = q.size();
            
            while(x--)
            {
                int curr = q.front()[0];
                int cost = q.front()[1];
                q.pop();
                
                for (auto it:adj[curr])
                {
                    if (dist[it[0]]>cost+it[1])
                    {
                        dist[it[0]] = cost + it[1];
                        q.push({it[0], dist[it[0]]});
                    }
                }
            }
            k--;
        }
        
        return dist[dst]==1e9?-1:dist[dst];
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
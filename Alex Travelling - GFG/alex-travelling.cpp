//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>>adj[n+1];
        for (auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dis(n+1,INT_MAX);
        pq.push({0,k});
        dis[k]=0;
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            for (auto it:adj[curr])
            {
                int edgw = it.second;
                int next = it.first;

                if (dis[next]>edgw+cost)
                {
                    dis[next]=edgw+cost;
                    pq.push({edgw+cost,next});
                }
            }
        }
        int ans = 0;
        for (int i=1; i<=n; i++)
        {
            if (dis[i]==INT_MAX)
                return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
        // code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends
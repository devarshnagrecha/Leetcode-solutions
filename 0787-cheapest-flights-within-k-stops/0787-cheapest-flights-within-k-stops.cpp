class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int,int>> adj[n];
        
        for (auto it:flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        int ans = INT_MAX;
        queue <pair<int,int>> q;
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        q.push({src,0});
        k++;
        
        while(!q.empty() && k)
        {
            int x = q.size();
            for (int i=0; i<x; i++)
            {
                auto it = q.front();
                int nodeReached = it.first;
                int costTillnow = it.second;
                //vis[node]=true;
                q.pop();
                
                for (auto neighbour:adj[nodeReached])
                {
                    int price = neighbour.second;
                    int nextNode = neighbour.first;
                    
                    if (costTillnow + price < dis[nextNode])
                    {
                        dis[nextNode] = costTillnow + price;
                        q.push({nextNode, dis[nextNode]});
                    }
                }
            }
            k--;
        }
        
        return dis[dst]==INT_MAX?-1:dis[dst];
        
        
    }
};
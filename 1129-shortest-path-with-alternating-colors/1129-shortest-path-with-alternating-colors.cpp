class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        vector <pair<int,int>> adj[n];
        
        vector <int> dis (n,-1);
        
        for (auto it: redEdges)
        {
            adj[it[0]].push_back({it[1],1});
        }
        
        for (auto it: blueEdges)
        {
            adj[it[0]].push_back({it[1],2});
        }
        
        queue<vector<int>> q;
        q.push({0,0,-1});
        
        
        while (!q.empty())
        {
            auto it = q.front();
            
            q.pop();
            int parent = it[0];
            int distance = it[1];
            int color = it[2];
            
            if (dis[parent]==-1)
                dis[parent]=distance;
            
            for (auto &child:adj[parent])
            {
                if (child.second!=color && child.first!=-1)
                {
                    q.push({child.first, distance+1, child.second});
                    child.first = -1;
                }
            }
        }
        
        return dis;
    }
};
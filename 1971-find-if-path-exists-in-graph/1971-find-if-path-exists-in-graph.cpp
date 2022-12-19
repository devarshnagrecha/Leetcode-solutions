class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int> adj[n];
        
        for (int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int>q;
        q.push(source);
        unordered_map <int,bool> vis;
        vis[source]=true;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            if (it==destination)
                return true;
            
            for (auto ct:adj[it])
            {
                if (!vis[ct])
                {
                    q.push(ct);
                    vis[ct]=true;
                }
            }
        }
        
        return false;
        
    }
};
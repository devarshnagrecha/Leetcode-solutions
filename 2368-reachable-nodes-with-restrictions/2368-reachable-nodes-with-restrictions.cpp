class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {
        int ans = 1;
        
        vector<int>adj[n];
        
        unordered_map<int,int> res, vis;
        vis[0]++;
        
        for (auto it:restricted)
            res[it]++;
        
        for (auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int>q;
        q.push(0);
        
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            
            for (auto it:adj[x])
            {
                if (!vis[it]&&!res[it])
                {
                    ans++;
                    vis[it]++;
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};
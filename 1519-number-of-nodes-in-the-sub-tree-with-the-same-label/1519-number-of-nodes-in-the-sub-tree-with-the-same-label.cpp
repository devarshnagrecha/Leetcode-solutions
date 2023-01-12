class Solution {
public:
    
    vector <int> dfs (int u, int parent, vector <int> adj[], string &labels, vector<int> &ans)
    {
        vector<int>res(26,0);
        res[labels[u]-'a']++;
        
        for (auto it:adj[u])
        {
            if (it==parent)
                continue;
            
            vector <int> temp = dfs(it,u,adj,labels,ans);
            
            for (int i=0; i<26; i++)
            {
                res[i]+=temp[i];
            }
        }
        
        ans[u] = res[labels[u]-'a'];
        
        return res;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector <bool> vis(n,false);
        
        vector <int> adj[n];
        
        for (auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>ans(n,0);
        
        dfs (0,-1,adj,labels,ans);
        
        return ans;
        
    }
};
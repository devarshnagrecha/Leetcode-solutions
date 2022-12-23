class Solution {
public:
    
    void dfs(int i,map<int,bool>&visit,vector <int> adj[])
    {
        for(auto &it:adj[i])
        {
            if(!visit[it])
            {
                visit[it]=true;
                dfs(it,visit, adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int connected = 0;
        map<int,bool>visit;
        
        vector <int> adj[n];
        
        for (int i=0; i<connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int edge=connections.size();
        int ans=0;
        for (int i=0; i<n; i++)
        {
            if (!visit[i])
            {
                visit[i]=true;
                dfs(i,visit, adj);
                ans++;
            }
        }
       // cout<<edge<<visit.size();
        if(connections.size()<n-1)
            return -1;
        return ans-1;
    }
};
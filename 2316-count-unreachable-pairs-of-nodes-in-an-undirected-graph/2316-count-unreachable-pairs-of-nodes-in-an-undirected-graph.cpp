class Solution {
public:
    
    void dfs(int u, stack<int> &topo, int v, vector<int>adj[], vector<bool> &visited)
	{
	    visited[u]=true;
	    
	    for (auto it:adj[u])
	    {
	        if (visited[it]==false)
	            dfs(it,topo,v,adj,visited);
	    }
	    
	    topo.push(u);
	}
	
	void revdfs(int u, vector<bool> &visited, int v, vector<int>transpose[], vector<int>&temp)
	{
        temp.push_back(u);
	    visited[u]=true;
	    
	    for (auto it:transpose[u])
	    {
	        if (visited[it]==false)
	            revdfs(it, visited, v, transpose, temp);
	    }
	    
	}
	
    vector<vector<int>> kosaraju(int v, vector<int> adj[])
    {
        vector<vector<int>> res;
        int ans = 0;
        
        stack <int> topo;
        vector <bool> visited(v,false);
        
        for (int i=0; i<v; i++)
        {
            if (visited[i]==false)
            {
                dfs(i,topo,v,adj,visited);
            }
        }
        
        vector<int> transpose[v];
        
        for (int i=0; i<v; i++)
        {
            visited[i]=false;
            for (auto it:adj[i])
            {
                transpose[it].push_back(i);
            }
        }
        
        while(!topo.empty())
        {
            if (visited[topo.top()]==false)
            {
                vector <int> temp;
                ans++;
                revdfs(topo.top(), visited, v, transpose, temp);
                res.push_back(temp);
                temp.clear();
            }
            
            topo.pop();
        }
        
        return res;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector <int> adj[n];
        
        for (int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<vector<int>> x = kosaraju (n,adj);
        
        long long int ans = 0, sum = 0;
        
        
        for (int i=0; i<x.size(); i++)
        {
            ans += x[i].size()*(n-x[i].size());
        }
        
        return ans/2;;
    }
};
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool dfs (int i, vector <int> adj[], vector <int> &color, int par_col)
    {
        color[i]=1-par_col;
        
        for (auto child:adj[i])
        {
            if (color[child]==-1)
            {
                if (dfs(child,adj,color,color[i])==false)
                    return false;
            }
            
            else
            {
                if (color[child]==color[i])
                    return false;
            }
        }
        
        return true;
    }
    
	bool isBipartite(int v, vector<int>adj[])
	{
	    vector <int> color(v,-1);
	    
	    for (int i=0; i<v; i++)
	    {
	        if (color[i]==-1)
	        {
	            queue<int>q;
	            
	            q.push(i);
	            color[i]=1;
	            
	            while(!q.empty())
	            {
	                int x = q.front();
	                q.pop();
	                
	                for (auto it:adj[x])
    	            {
    	                if (color[x]==color[it])
    	                    return false;
    	                    
    	                else if (color[it]==-1)
    	                {
    	                    color[it]=!color[x];
    	                    q.push(it);
    	                }
    	                    
    	            }
	            }
	        }
	    }
	    
	    return true;
	    // Code here
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int v, vector<pair<int, int> >& pre) 
	{
	    vector <int> adj[v];
	    
	    for (auto it:pre)
	    {
	        adj[it.first].push_back(it.second);
	    }
	    
	    vector <int> ans, indegree(v,0);
	    
	    for (int i=0; i<v; i++)
	    {
	        for (auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue <int> q;
	    
	    for (int i=0; i<v; i++)
	    {
	        if (indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        auto it = q.front();
	        q.pop();
	        
	        ans.push_back(it);
	        
	        for (auto ct:adj[it])
	        {
	            indegree[ct]--;
	            if (indegree[ct]==0)
	            {
	                q.push(ct);
	            }
	        }
	    }
	    
	    if (ans.size()==v)
	        return 1;
	    return 0;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
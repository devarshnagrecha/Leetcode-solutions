class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        vector <vector <int> > adj(n);
        vector <int> indegree(n,0);
        
        for (auto it:pre)
        {
            int course = it[0];
            int prerequisite = it[1];
            
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        
        queue <int> q;
        vector <int> ans;
        
        for (int i=0; i<n; i++)
        {
            if (indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            
            for (auto it:adj[curr])
            {
                indegree[it]--;
                
                if (indegree[it]==0)
                    q.push(it);
            }
        }
        
        if (ans.size()==n)
            return ans;
        return {};
        
    }
};
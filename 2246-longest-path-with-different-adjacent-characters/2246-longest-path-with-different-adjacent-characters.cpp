class Solution {
public:
    
    int dfs (int &ans, vector <int> children[], int u, string &s)
    {
        int big1 = 0, big2 = 0;
        
        for (auto it:children[u])
        {
            int curr = dfs(ans, children,it,s);
            
            if (s[u]==s[it])
                continue;
            
            if (curr>big2)
                big2=curr;
            
            if (big2>big1)
                swap (big1,big2);
        }
        
        ans = max (ans, big1+big2+1);
        
        return big1 + 1;
    }
    
    int longestPath(vector<int>& parent, string s) 
    {
        int ans = 1, n = s.size();
        
        vector <int> children[n];
        
        for (int i=1; i<n; i++)
        {
            children[parent[i]].push_back(i);
        }
        
        dfs (ans,children,0,s);
        
        return ans;
    }
};
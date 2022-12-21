class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>> graph (n+1);
        
        for (auto it:dislikes)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        vector<int> color(n+1,0); 

        queue<int> q;   

        for (int i=1; i<=n; i++)
        {
            if (color[i])
                continue;
            
            q.push(i);
            color[i]=1;
            
            while(!q.empty())
            {
                int top = q.front();
                q.pop();
                
                for (auto it:graph[top])
                {
                    if (!color[it])
                    {
                        color[it]=-color[top];
                        q.push(it);
                    }
                    
                    else if(color[it]==color[top])
                        return false;
                }
            }
        }
        
        return true;
    }
};
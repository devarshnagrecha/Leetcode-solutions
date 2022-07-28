class Solution {
public:
    bool isValid (int i, int j, vector<vector<int>>& grid)
    {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)
            return false;
        
        grid[i][j]=2;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m=grid[0].size(), ans = 0;
        queue<vector<int>>q;
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j]==2)
                {
                    q.push({i,j,0});
                }
            }
        }
        
        while(!q.empty())
        {
            auto it = q.front();
            
            int i=it[0];
            int j=it[1];
            int time=it[2];
            
            ans = max (ans,time);
            
            q.pop();
            
            if(isValid(i+1,j,grid))
                q.push({i+1,j,time+1});
            if(isValid(i-1,j,grid))
                q.push({i-1,j,time+1});
            if(isValid(i,j+1,grid))
                q.push({i,j+1,time+1});
            if(isValid(i,j-1,grid))
                q.push({i,j-1,time+1});
                   
        }
        
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        
        return ans;
        
    }
};
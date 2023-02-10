class Solution {
public:
    
    bool isValid (int i, int j, int n, int m, vector<vector<int>>& grid, int moves)
    {
        if (i<0 || j<0 || i>=n || j>=m || grid[i][j]!=0)
            return false;
        
        grid[i][j]=moves+1;
        return true;
    }
    
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        
        queue<vector<int>> q;
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j]==1)
                    q.push({i,j,1});
            }
        }
        
        if (q.size()==n*m)
            return -1;
        
        while (!q.empty())
        {
            auto it = q.front();
            
            int i = it[0];
            int j = it[1];
            int moves = it[2];
            
            q.pop();
            
            if (isValid(i+1,j,n,m,grid,moves))
                q.push({i+1,j,moves+1});
                
            if (isValid(i-1,j,n,m,grid,moves))
                q.push({i-1,j,moves+1});
                
            if (isValid(i,j+1,n,m,grid,moves))
                q.push({i,j+1,moves+1});
                
            if (isValid(i,j-1,n,m,grid,moves))
                q.push({i,j-1,moves+1});
        }
        
        int maxi = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                maxi = max(grid[i][j], maxi);
            }
            
            cout << endl;
        }
        return maxi-1;
    }
};
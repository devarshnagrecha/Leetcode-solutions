class Solution {
public:
    
    // function to iterate all 1's present on boundaries and their adjacents (4-directions) and mark each of them to 0
    void floodFill (int i, int j, int n, int m, vector<vector<int>>& grid)
    {
        if (i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1)
            return;
        
        grid[i][j]=0;
        
        floodFill (i+1, j, n, m, grid);
        floodFill (i-1, j, n, m, grid);
        floodFill (i, j+1, n, m, grid);
        floodFill (i, j-1, n, m, grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size(), count = 0;
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if ((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1)
                {
                    floodFill (i,j,n,m,grid);
                }
            }
        }
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        
        return count;
        
    }
};
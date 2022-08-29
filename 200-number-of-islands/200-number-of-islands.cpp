class Solution {
public:
    
    void solve(int i,int j,vector<vector<char>>& grid,int r,int c)
    {
        if(i < 0 or j < 0 or i >= r or j >= c or grid[i][j] != '1')
            return;
            
        grid[i][j] ='2';
        solve(i+1,j,grid,r,c);
        solve(i-1,j,grid,r,c);
        solve(i,j-1,grid,r,c);
        solve(i,j+1,grid,r,c);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int island = 0;
        
        if(row == 0)
            return 0;
            
        for(int i = 0 ; i < row;i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    island +=1 ;
                    solve(i,j,grid,row,col);
                }
            }
        }
        return island;
        
    }
};
class Solution {
public:
    
    bool isValid (int i, int j, int n, int m, vector<vector<char>>& grid)
    {
        if (i<0 || j<0 || i>=n || j>=m || grid[i][j]!='.')
            return false;
        
        grid[i][j]='+';
        return true;
    }
                
    
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int moves = 0;
        
        if(row == 0)
            return 0;
        
        queue <vector<int>> q;
        
        for(int i = 0 ; i < row;i++)
        {
            for(int j = 0; j < col; j++)
            {
                if((i==0 || j==0 || i==row-1 || j==col-1) && grid[i][j]=='.' )
                {
                    if (!(i==entrance[0] && j==entrance[1]))
                        q.push({i,j});
                }
            }
        }
        
        while (!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto it = q.front();
                q.pop();

                int i=it[0];
                int j=it[1];

                if (i==entrance[0] && j==entrance[1])
                    return moves;

                if (isValid(i+1,j,row,col,grid))
                    q.push({i+1,j});
                if (isValid(i-1,j,row,col,grid))
                    q.push({i-1,j});
                if (isValid(i,j+1,row,col,grid))
                    q.push({i,j+1});
                if (isValid(i,j-1,row,col,grid))
                    q.push({i,j-1});
            }
            
            moves++;
        }
        
        return -1;
        
    }
};
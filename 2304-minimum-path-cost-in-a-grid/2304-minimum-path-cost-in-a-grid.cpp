class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) 
    {
        int ans = INT_MAX, m = grid.size(), n = grid[0].size();
        
        vector <int> prev = grid[0], curr = prev;
        
        for (int i=1; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                curr[j] = INT_MAX;
                
                for (int k=0; k<n; k++)
                {
                    curr[j] = min (curr[j], grid[i][j] + prev[k] + moveCost[grid[i-1][k]][j]);
                }
            }
            
            prev = curr;
        }
        
        ans = *min_element(prev.begin(), prev.end());
        return ans;
        
    }
};
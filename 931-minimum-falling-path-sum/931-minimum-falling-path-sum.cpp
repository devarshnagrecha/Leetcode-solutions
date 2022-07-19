class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int r = matrix.size(), c = matrix[0].size();
        
        vector <vector <int> > dp(r,vector <int>(c));
        
        dp[0] = matrix[0];
        
        for (int i=1; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (j==0)
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
                else if (j==c-1)
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + matrix[i][j];
                else
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1])) + matrix[i][j];
            }
        }
        
        int ans = INT_MAX;
        for (int i=0; i<c; i++)
        {
            ans = min(dp[r-1][i], ans);
        }
        
        return ans;
        
    }
};
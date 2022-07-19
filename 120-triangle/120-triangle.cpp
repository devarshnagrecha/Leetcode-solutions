class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size(), ans = INT_MAX, m = triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int> (m));
        
        dp[0][0]=triangle[0][0];

        for (int i=1; i<n; i++)
        {
            for (int j=0; j<triangle[i].size(); j++)
            {
                if (j==0)
                {
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                
                else if (j==triangle[i].size()-1)
                {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                
                else
                {
                    dp[i][j] = min (dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }
            }
        }
        
        
        for (int i=0; i<m; i++)
        {
            ans = min(ans,dp[n-1][i]);
        }
        
        return ans;
    }
};
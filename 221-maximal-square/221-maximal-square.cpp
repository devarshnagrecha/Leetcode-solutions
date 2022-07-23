class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector< vector <long int> > dp(r, vector<long int> (c));
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (i==0 || j==0)
                {
                    if (matrix[i][j]=='0')
                        dp[i][j]=0;
                    else
                        dp[i][j]=1;
                }
            }
        }
        
        for (int i=1; i<r; i++)
        {
            for (int j=1; j<c; j++)
            {
                if (matrix[i][j]!='0')
                    dp[i][j] = 1 + min (dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        
        long int ans = 0;
        
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                ans = max (ans, dp[i][j]);
            }
        }
        
        return ans*ans;
    }
};
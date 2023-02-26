class Solution {
public:
    int minDistance(string s, string t) 
    {
        int x = s.size(), y= t.size();
        
        int dp[x+1][y+1];
        
        for (int i=0; i<=x; i++)
        {
            for (int j=0; j<=y; j++)
            {
                if (j==0)
                {
                    dp[i][j]=i;
                }
                
                if (i==0)
                {
                    dp[i][j]=j;
                }
            }
        }
        
        
        for (int i=1; i<=x; i++)
        {
            for (int j=1; j<=y; j++)
            {
                if (s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                
                else
                {
                    dp[i][j]= 1 + min (dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        
        return dp[x][y];
        
    }
};
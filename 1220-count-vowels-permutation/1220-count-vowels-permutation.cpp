class Solution {
public:
    int countVowelPermutation(int n) 
    {
        long int dp[n+1][5], mod = 1e9+7;
        
        for (long int i=0; i<5; i++)
        {
            dp[1][i]=1;
        }
        
        /*int prevA = 1, prevE = 1, prevI = 1, prevO = 1, prevU = 1;
        int currA = 0, currE = 0, currI = 0, currO = 0, currU = 0;*/
        
        
        for (long int i=2; i<=n; i++)
        {
            dp[i][0] = (dp[i-1][1]%mod+dp[i-1][2]%mod+dp[i-1][4]%mod)%mod;
            dp[i][1] = (dp[i-1][0]%mod+dp[i-1][2]%mod)%mod;
            dp[i][2] = (dp[i-1][1]%mod+dp[i-1][3]%mod)%mod;
            dp[i][3] = (dp[i-1][2]%mod);
            dp[i][4] = (dp[i-1][2]%mod+dp[i-1][3]%mod)%mod;
        }
        
        //cout << dp[n][0] <<" "<< dp[n][1]<<" "<<dp[n][2]<<" "<<dp[n][3]<<" "<<dp[n][4];
        return (dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4])%mod;
        
        
    }
};
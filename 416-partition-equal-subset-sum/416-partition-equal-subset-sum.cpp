class Solution {
public:
    
    bool canPartition(vector<int>& nums) 
    {
        int x = accumulate(nums.begin(), nums.end(), 0);
        if (x%2==1)
            return false;
        
        x/=2;
        vector <int> dp(x+1,false);
        dp[0] = true;
        
        for (auto it:nums)
        {
            for (int i=x; i>0; i--)
            {
                if (i>=it)
                    dp[i]=dp[i]||dp[i-it];
                
                if (dp[x])
                    return true;
            }
        }
        
        return false;
        
    }
};
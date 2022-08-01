class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size(), temp = nums[0];
        
        if (n==1)
            return 0;
        
        if (nums[0]>=n-1)
            return 1;
        
        vector <int> dp(n,INT_MAX-1);
        int k=1;
        
        dp[0]=0;
        while(temp--)
        {
            dp[k] = 1;
            k++;
        }
        
        for (int i=1; i<n; i++)
        {
            int steps = nums[i];
            
            for (int j=i+1; j<min(n,i+1+steps); j++)
            {
                dp[j]=min(dp[j], 1+dp[i]);
            }
            
        }
        
        return dp[n-1];
    }
};
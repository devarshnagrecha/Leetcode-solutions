class Solution {
public:
    
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0, ans= INT_MIN;
        
        for (int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            ans = max(ans, sum);
            
            if(sum<0)
                sum=0;
        }
        
        return ans;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int max1 = maxSubArray (nums);
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        for (int i=0; i<nums.size(); i++)
        {
            nums[i]*=-1;
        }
        
        int max2 = sum - (-1*maxSubArray (nums));
        if (max2==0)
            return max1;
        
        //cout << max1 << " " << sum << endl;
        return max(max1,max2);
        
    }
};
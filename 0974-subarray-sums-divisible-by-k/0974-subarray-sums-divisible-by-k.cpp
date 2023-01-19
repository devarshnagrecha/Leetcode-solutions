class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int ans = 0, sum = 0, n = nums.size(), rem;
        
        unordered_map <int,int> mp;
        mp[0] = 1;
        
        if (n==0)
            return 0;
        
        for (int i=0; i<n; i++)
        {
            sum += nums[i];
            
            rem = sum % k;
            
            if (rem<0)
                rem += k;
            
            ans += mp[rem];
            
            mp[rem]++;
        }
        
        return ans;
        
    }
};
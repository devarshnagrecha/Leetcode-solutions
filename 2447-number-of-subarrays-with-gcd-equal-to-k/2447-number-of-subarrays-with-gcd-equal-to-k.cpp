class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {
        int ans = 0;
        
        for (int i=0; i<nums.size(); i++)
        {
            int temp = 0;
            for (int j=i; j<nums.size(); j++)
            {
                temp = __gcd(temp, nums[j]);
                
                if (temp==k)
                    ans++;
            }
        }
        
        return ans;
    }
};
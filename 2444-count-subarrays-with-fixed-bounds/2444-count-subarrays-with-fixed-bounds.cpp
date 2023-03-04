class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        long long int ans = 0;
        int start = 0, minStart, maxStart;
        bool maxFound = false, minFound = false;
        
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            
            if (nums[i]==minK)
            {
                minFound = true;
                minStart = i;
            }
            
            if (nums[i]==maxK)
            {
                maxFound = true;
                maxStart = i;
            }
            
            if (minFound && maxFound)
            {
                ans += (min(minStart, maxStart) - start + 1);
            }
        }
        
        return ans;
    }
};
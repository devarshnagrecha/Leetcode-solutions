class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        sort (nums.begin(), nums.end());
        
        vector <int> ans;
        
        for (int i=0; i<nums.size();)
        {
            int x = nums[i], count = 1;
            i++;
            while (i<nums.size() && nums[i]==x)
            {
                count++;
                i++;
            }
                
            
            if (count>nums.size()/3)
                ans.push_back(x);
        }
        
        return ans;
    }
};
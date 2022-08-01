class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int greedy = nums[0], i;
        
        if (nums.size()<2)
            return true;
        
        for (i=0; i<nums.size(); i++)
        {
            if (greedy==0)
            {
                break;
            }
            greedy--;
            greedy = max(greedy, nums[i]);
        }
        
        if (i==nums.size())
            return true;
        else
            return false;
        
    }
};
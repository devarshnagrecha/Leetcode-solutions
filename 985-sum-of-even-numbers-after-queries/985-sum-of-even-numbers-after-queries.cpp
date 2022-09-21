class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int even=0,odd=0,currEven = 0;
        vector <int> temp = nums;
        
        for (auto it:nums)
        {
            if (it%2)
                odd+=it;
            else
                even+=it;
        }
        
        vector <int> ans;
        currEven = even;
        
        for (auto it:queries)
        {
            if (nums[it[1]]%2==0)
            {
                currEven -= (nums[it[1]]);
            }
            
            nums[it[1]] += it[0];
            
            if (nums[it[1]]%2==0)
            {
                currEven += (nums[it[1]]);
            }
            
            ans.push_back(currEven);
        }
        
        return ans;
    }
};
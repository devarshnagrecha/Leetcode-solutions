class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        priority_queue <pair <int,int> > data;
        
        for (int i=0; i<nums.size(); i++)
        {
            data.push({nums[i], i});
        }
        
        return data.top().second;
        
    }
};
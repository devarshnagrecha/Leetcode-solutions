class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort (intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        for (int i=0; i<intervals.size();)
        {
            int start1 = intervals[i][0], end1 = intervals[i][1];
            
            while (i<intervals.size() && end1 >= intervals[i][0])
            {
                end1 = max(end1,intervals[i][1]);
                i++;
            }
                
            
            ans.push_back({start1, max(intervals[i-1][1], end1)});
        }
        
        return ans;
    }
};
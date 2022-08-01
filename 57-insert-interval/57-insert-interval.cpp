class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        
        if (intervals.size()==0)
        {
            ans.push_back(newInterval);
            return ans;
        }
            
        
        for (int i=0; i<intervals.size(); i++)
        {
            if (intervals[i][1]<newInterval[0])
                ans.push_back(intervals[i]);
            
            else
            {
                int start = min(newInterval[0], intervals[i][0]);
                while(i<intervals.size() && intervals[i][1]<=newInterval[1] && intervals[i][1]>=newInterval[0])
                {
                    i++;
                }
                
                if (i==intervals.size())
                {
                    ans.push_back({start,newInterval[1]});
                    break;
                }
                
                if (intervals[i][0] > newInterval[1])
                {
                    ans.push_back({start,newInterval[1]});
                }
                
                else
                {
                    int end = max(intervals[i][1],newInterval[1]);
                    ans.push_back({start,end});
                    i++;
                }
                
                while(i!=intervals.size())
                {
                    ans.push_back(intervals[i]);
                    i++;
                }
            }
            
        }
        
        if (newInterval[0] > ans[ans.size()-1][1])
            ans.push_back(newInterval);
        
        return ans;
        
    }
};
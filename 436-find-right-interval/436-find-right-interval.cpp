class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        map <int,int> ind, end;
        
        vector<int>v,ans;
        
        for (int i=0; i<intervals.size(); i++)
        {
            v.push_back(intervals[i][0]);
            ind[intervals[i][0]]=i;
            end[intervals[i][0]]=intervals[i][1];
        }
        
        sort (v.begin(), v.end());
        
        for (int i=0; i<intervals.size(); i++)
        {
            int oldright = end[intervals[i][0]];
            
            auto it = lower_bound(v.begin(), v.end(), oldright);
            
            if (it==v.end())
                ans.push_back(-1);
            else
                ans.push_back(ind[*it]);
            
        }
        
        return ans;
    }
};
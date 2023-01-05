class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort (points.begin(), points.end());
        
        int ans = 0;
        
        for (int i=0; i<points.size(); i++)
        {
            int s1 = points[i][0];
            int e1 = points[i][1];
            int j = i+1;
            
            ans++;
            
            while(j<points.size() && points[j][0]<=e1)
            {
                e1 = min (e1, points[j][1]);
                j++;
            }
            
            i = j-1;
        }
        
        return ans;
        
    }
};
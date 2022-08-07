class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int ans = 0, maxi = 0;
        
        for (int i=0; i<values.size(); i++)
        {
            ans = max(ans, maxi+values[i]);
            maxi = max(maxi,values[i])-1;
        }
        
        return ans;
        
    }
};
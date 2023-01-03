class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int ans = 0;
        
        int r=strs.size(), c=strs[0].size();
        
        for (int i=0; i<c; i++)
        {
            string s = "";
            for (int j=0; j<r; j++)
            {
                s += strs[j][i];
            }
            
            if (!is_sorted(s.begin(),s.end()))
                ans++;
        }
        
        return ans;
        
    }
};
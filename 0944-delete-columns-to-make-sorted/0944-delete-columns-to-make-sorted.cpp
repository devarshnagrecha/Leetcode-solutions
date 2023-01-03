class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int ans = 0;
        
        int r=strs.size(), c=strs[0].size();
        
        for (int i=0; i<c; i++)
        {
            for (int j=1; j<r; j++)
            {
                if (strs[j][i]<strs[j-1][i])
                {
                    ans++;
                    break;
                }
                    
            }
        }
        
        return ans;
        
    }
};
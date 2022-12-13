class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int r = matrix.size(), c = matrix[0].size();
        
        vector <int> curr = matrix[0], prev = matrix[0];
        
        for (int i=1; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (j==0)
                    curr[j] = min(prev[j], prev[j+1]) + matrix[i][j];
                else if (j==c-1)
                    curr[j] = min(prev[j], prev[j-1]) + matrix[i][j];
                else
                    curr[j] = min(prev[j], min(prev[j-1], prev[j+1])) + matrix[i][j];
            }
            
            prev = curr;
        }
        
        int ans = INT_MAX;
        for (int i=0; i<c; i++)
        {
            ans = min(prev[i], ans);
        }
        
        return ans;
        
    }
};
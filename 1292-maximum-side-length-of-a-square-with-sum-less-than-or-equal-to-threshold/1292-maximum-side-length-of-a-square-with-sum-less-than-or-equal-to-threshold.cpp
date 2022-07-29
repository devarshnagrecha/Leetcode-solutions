class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        int n = mat.size(), m = mat[0].size();
        
        for (int i=1; i<m; i++)
        {
            mat[0][i] += mat[0][i-1];
        }
        
        for (int i=1; i<n; i++)
        {
            mat[i][0] += mat[i-1][0];
        }
        
        for (int i=1; i<n; i++)
        {
            for (int j=1; j<m; j++)
            {
                mat [i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
        }
        
        int start = 0, end = min (n,m), ans = 0;
        
        while(start!=end)
        {
            for (int i=start; i<n; i++)
            {
                for (int j=start; j<m; j++)
                {
                    int sum = mat[i][j];
                    
                    if ((i-start-1) >= 0)
                        sum -= mat[i-start-1][j];
                    
                    if ((j-start-1) >= 0)
                        sum -= mat[i][j-start-1];
                    
                    if ((i-start-1) >= 0 && (j-start-1) >= 0)
                        sum += mat[i-start-1][j-start-1];
                    
                    if (sum <= threshold)
                        ans = max (ans, start+1);
                }
            }
            
            start++;
        }
        
        return ans;
    }
};
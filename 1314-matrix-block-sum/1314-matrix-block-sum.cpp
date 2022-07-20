class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& sum, int k) 
    {
        int row = sum.size(), col = sum[0].size();
        //vector<vector<int>> sum = mat;
        
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                if (j>0)
                    sum[i][j] += sum[i][j-1];
                
                if (i>0)
                    sum[i][j] += sum[i-1][j];
                
                if (i>0 && j>0)
                    sum[i][j] -= sum[i-1][j-1];
            }
        }
        
        /*for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                cout << sum[i][j] << " ";
            }
            cout << endl;
        }*/

        vector<vector<int>> ans (row, vector<int>(col,0));
        
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                int maxRow = min(row-1,i+k);
                int maxCol = min(col-1, j+k);
                int minRow = max(0,i-k);
                int minCol = max(0,j-k);
                
               // cout << minRow << " " << maxRow << " " << minCol << " " << maxCol << endl;
                ans[i][j] += sum[maxRow][maxCol];
                
                if (minCol>0)
                    ans [i][j] -= sum[maxRow][minCol-1];
                if (minRow>0)
                    ans [i][j] -= sum[minRow-1][maxCol];
                if (minRow>0 && minCol>0)
                    ans [i][j] += sum[minRow-1][minCol-1];
                
            }
        }
        return ans;
    }
    
    
};
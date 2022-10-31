class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int r = matrix.size(), c = matrix[0].size();
        
        vector<int> prev = matrix[0];
        prev.pop_back();
        
        for (int i=1; i<r; i++)
        {
            vector <int> curr;
            
            for (int j=1; j<c; j++)
            {
                curr.push_back(matrix[i][j]);
            }
            
            if (curr!=prev)
                return false;
            prev = matrix[i];
            
            prev.pop_back();
        }
        
        return true;
        
    }
};
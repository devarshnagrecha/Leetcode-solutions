class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        map <int, vector<int> > mp;
        for (int i=0; i<mat.size(); i++)
        {
            for (int j=0; j<mat[0].size(); j++)
            {
                mp[i-j].push_back(mat[i][j]);
            }
        }
        
        for (auto &it:mp)
        {
            sort(it.second.begin(),it.second.end());
        }
        
        for (int j=0; j<mat[0].size(); j++)
        {
            int col = j, row = 0, it=0;
            vector <int> diag = mp[0-j];
            
            while (it!=diag.size())
            {
                mat[row][col]=diag[it];
                it++;
                row++;
                col++;
            }
        }
        
        for (int i=1; i<mat.size(); i++)
        {
            int col = 0, row = i, it=0;
            vector <int> diag = mp[i-0];
            
            while (it!=diag.size())
            {
                mat[row][col]=diag[it];
                it++;
                row++;
                col++;
            }
        }
        
        return mat;
        
    }
};
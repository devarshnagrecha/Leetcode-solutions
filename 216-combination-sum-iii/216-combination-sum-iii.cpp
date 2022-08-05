class Solution {
public:
    
    void solve (int k, int n, vector<vector<int>> &ans, vector<int> &temp, int ind)
    {
        if (temp.size()>k)
            return;
        
        if (temp.size()==k)
        {
            if (n!=0)
                return;
            ans.push_back(temp);
        }
        
        for (int i=ind; i<=9; i++)
        {
            temp.push_back(i);
            solve(k, n-i, ans, temp, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        
        vector<vector<int>> ans;
        vector <int> temp;
        
        solve (k, n, ans, temp, 1);
        return ans;
    }
};
class Solution {
public:
    
    void solve (vector<int>& candidates, vector<vector<int>> &ans, vector<int> &temp, int target, int ind)
    {
        if (target==0)
            ans.push_back(temp);
        
        if (target<0)
            return;
        
        for (int i=ind; i<candidates.size(); i++)
        {
            if(i > ind && candidates[i] == candidates[i-1]) 
                continue;
            
            temp.push_back(candidates[i]);
            solve(candidates, ans, temp, target-candidates[i], i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        
        vector <int> temp;
        
        sort (candidates.begin(), candidates.end());
        solve (candidates, ans, temp, target, 0);
        
        return ans;
        
    }
};
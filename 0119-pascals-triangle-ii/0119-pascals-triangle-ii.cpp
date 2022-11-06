class Solution {
public:
    vector<int> getRow(int n) 
    {
        if (n==0)
            return {1};
        
        vector <int> ans;
        ans.push_back(1);
        
        long long int temp = n;
        
        for (int i=1; i<n; i++)
        {
            ans.push_back(temp);
            temp *= (n-i);
            temp /= (i+1);
        }
        
        ans.push_back(1);
        
        return ans;
    }
};
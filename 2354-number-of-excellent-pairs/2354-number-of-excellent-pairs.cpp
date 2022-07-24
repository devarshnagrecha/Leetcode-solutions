class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) 
    {
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> v;
        
        for(auto& i: s)
        {
            int x = __builtin_popcount(i);
            v.push_back(x);
        }
        
        sort(v.begin(),v.end());
        
        long long ans = 0;
        for(int i=0;i<v.size();i++)
        {
            auto it = lower_bound(v.begin(),v.end(),k-v[i]);
            ans += (v.end()-it);
        }
        
        return ans;
    }
    
    
};
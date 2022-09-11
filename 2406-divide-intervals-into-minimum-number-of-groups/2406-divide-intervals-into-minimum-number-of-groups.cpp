class Solution {
public:
    
     int minGroups(vector<vector<int>>& intervals) 
     {
        map<int, int> A;
        for (auto& v : intervals)
            A[v[0]]++, A[v[1] + 1]--;
         
        int res = 0, cur = 0;
         
        for (auto& v : A)
            res = max(res, cur += v.second);
        return res;
    }
};
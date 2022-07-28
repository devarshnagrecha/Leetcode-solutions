class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        vector <int> data(100001,0);
        
        for (int i=0; i<profit.size(); i++)
        {
            data[difficulty[i]]=max(data[difficulty[i]], profit[i]);
        }
        
        for (int i=1; i<100001; i++)
        {
            data[i] = max (data[i], data[i-1]);
        }
        
        int ans = 0;
        
        for (int i=0; i<worker.size(); i++)
        {
            ans += data[worker[i]];
        }
        
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans = 0, cost = prices[0];
        
        for (auto it:prices)
        {
            cost = min(cost,it);
            ans = max (ans, it-cost);
        }
        
        return ans;
        
    }
};
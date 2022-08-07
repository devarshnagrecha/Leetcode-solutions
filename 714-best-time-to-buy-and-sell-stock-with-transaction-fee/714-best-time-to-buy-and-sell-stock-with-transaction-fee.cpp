class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        if (prices.size()<=1)
            return 0;
        
        int prevBuy = -prices[0]-fee, prevSell = 0, Buy, Sell;
        
        for (int i=1; i<prices.size(); i++)
        {
            Buy = max (prevBuy, prevSell-prices[i]-fee);
            Sell = max (prevSell, prevBuy+prices[i]);
            prevBuy = Buy;
            prevSell = Sell;
        }
        
        return max(prevBuy, prevSell);
        
    }
};
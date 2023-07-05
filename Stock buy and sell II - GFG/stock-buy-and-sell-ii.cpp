//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
    int solve(int i, int can_buy, vector<int>&prices, vector <vector<int>> &dp)
    {
        if (i==prices.size())
            return 0;
            
        if (dp[i][can_buy]!=-1)
            return dp[i][can_buy];
        
        if (can_buy==1)
        {
            int buy = -prices[i] + (solve(i+1,0, prices, dp));
            int not_buy = solve(i+1, 1, prices, dp);
            
            return dp[i][can_buy] = max(buy,not_buy);
        }
        
        else
        {
            int sell = prices[i] + (solve(i+1,1, prices, dp));
            int not_sell = solve(i+1, 0, prices, dp);
            
            return dp[i][can_buy] = max(sell,not_sell);
        }
    }
    
    int stockBuyAndSell(int n, vector<int> &prices) 
    {
        vector <vector<int>> dp(n, vector<int> (2,-1));
        return solve(0, 1, prices, dp);
        // code here
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
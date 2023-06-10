//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    long long maximumProfit(vector<long long>&prices, int n) 
    {
        vector<long long>prev(2,0),curr(2,0);
        for (int i=n-1; i>=0; i--)
        {
            curr[0] = max(-prices[i] + prev[1], prev[0]);
            curr[1] = max(prices[i] + prev[0], prev[1]);
            prev = curr;
        }
        return prev[0];
        // Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
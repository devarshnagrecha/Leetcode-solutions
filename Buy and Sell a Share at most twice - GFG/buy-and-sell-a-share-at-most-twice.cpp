//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price)
{
    int n = price.size();
    vector<vector<int>> dp(n+1,vector<int>(5,0));
    for (int i=n-1; i>=0; i--)
    {
        for (int transaction=3; transaction>=0; transaction--)
        {
            if (transaction%2==0)
                dp[i][transaction] = max(-price[i] + dp[i+1][transaction+1], dp[i+1][transaction]);
            else
                dp[i][transaction] = max(price[i] + dp[i+1][transaction+1], dp[i+1][transaction]);
        }
    }
    return dp[0][0];
    //Write your code here..
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
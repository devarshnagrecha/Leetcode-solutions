//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int price[]) 
    {
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        for (int i=n-1; i>=0; i--)
        {
            for (int transaction=2*k-1; transaction>=0; transaction--)
            {
                if (transaction%2==0)
                    dp[i][transaction] = max(-price[i] + dp[i+1][transaction+1], dp[i+1][transaction]);
                else
                    dp[i][transaction] = max(price[i] + dp[i+1][transaction+1], dp[i+1][transaction]);
            }
        }
        return dp[0][0];
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends
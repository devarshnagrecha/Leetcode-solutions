//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int solve(int i, int size, int price[], vector<vector<int>> &dp)
    {
        if (i==0)
            return size*price[0];
    
        if (dp[i][size]!=-1)
            return dp[i][size];
            
        int cut = INT_MIN;
        if (size>=(i+1))
            cut = price[i] + solve(i,size-(i+1),price,dp);
            
        int notCut = solve(i-1,size,price,dp);
        dp[i][size]=max(cut,notCut);
    }
    
    int cutRod(int price[], int n) 
    {
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(n-1,n,price,dp);
        //code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
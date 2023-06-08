//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&arr ,int d) 
    {
        int n = arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        int x = sum - d;
        if (x<0 || x%2)
            return 0;
        x/=2;
        vector<vector<int>> dp(n, vector<int>(x+1,0));
        
        if (x>=arr[0])
            dp[0][arr[0]]=1;
            
        if (arr[0]==0)
            dp[0][0]=2;
        else
            dp[0][0]=1;
        
            
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<=x; j++)
            {
                int take = 0;
                if (arr[i]<=j)
                    take = dp[i-1][j-arr[i]];
                int notTake = dp[i-1][j];
                dp[i][j]=(take + notTake);
            }
        }
        
        return dp[n-1][x];
        //Your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
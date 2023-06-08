//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>> dp(n, vector<int>(w+1,0));
        
        for (int i=wt[0]; i<=w; i++)
        {
            dp[0][i]=(i/wt[0])*val[0];
        }
        
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<=w; j++)
            {
                int take = INT_MIN;
                if (wt[i]<=j)
                    take = val[i] + dp[i][j-wt[i]];
                
                int notTake = dp[i-1][j];
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[n-1][w];
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
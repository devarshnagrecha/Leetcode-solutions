//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) 
    {
        int dp[n];
        dp[0]=0;
        if (n>0)
        dp[1]=abs(height[1]-height[0]);
        if(n>1)
        dp[2]=min(abs(height[1]-height[0])+abs(height[2]-height[1]),abs(height[2]-height[0]));
        for (int i=3; i<n; i++)
        {
            dp[i]=min(dp[i-1]+abs(height[i]-height[i-1]),dp[i-2]+abs(height[i]-height[i-2]));
        }
        return dp[n-1];
        // Code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
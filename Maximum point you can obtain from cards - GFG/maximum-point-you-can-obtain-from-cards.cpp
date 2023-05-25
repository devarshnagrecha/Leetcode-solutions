//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &arr, int n, int k) 
    {
        long long ans = INT_MAX, sum = 0, tot = 0;

        for (int i=0; i<n; i++)
        {
            sum += arr[i];
            tot += arr[i];
            if (i==n-k-1)
                ans = min (ans,sum);
            else if (i>=n-k)
            {
                sum-=arr[i-(n-k)];
                ans = min (ans,sum);
            }
        }
        return tot-ans;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
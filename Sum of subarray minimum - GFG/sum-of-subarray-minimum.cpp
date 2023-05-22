//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int n, vector<int> &arr) 
    {
        int mod = 1e9+7;
        long long ans = 0;
        vector<int>next_smaller(n),prev_smaller(n);
        stack <int> s1,s2;

        for (int i=n-1; i>=0; i--)
        {
            while(!s1.empty() && arr[s1.top()]>=arr[i])
                s1.pop();

            if (s1.empty())
                next_smaller[i]=(n-1-i);
            else
                next_smaller[i]=(s1.top()-i-1);
            s1.push(i);
        }
        
        for (int i=0; i<n; i++)
        {
            while(!s2.empty() && arr[s2.top()]>arr[i])
                s2.pop();

            if (s2.empty())
                prev_smaller[i]=(i);
            else
                prev_smaller[i]=(i-s2.top()-1);
            s2.push(i);
        }

        for (int i=0; i<n; i++)
        {
            //cout << prev_smaller[i] << " " << next_smaller[i] << endl;
            ans += ((long)arr[i]*((long)prev_smaller[i]+1)*((long)next_smaller[i]+1));
            ans %= mod;
        }

        return ans;
        // code here
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
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
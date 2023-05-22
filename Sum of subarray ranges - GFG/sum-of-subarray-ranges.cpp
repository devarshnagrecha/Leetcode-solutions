//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long subarrayRanges(int N, vector<int> &arr) 
    {
        int n = arr.size();
        long long ans = 0;
        vector<int>next_smaller(n),prev_smaller(n),next_greater(n),prev_greater(n);
        stack <int> s1,s2,s3,s4;

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

        for (int i=n-1; i>=0; i--)
        {
            while(!s3.empty() && arr[s3.top()]<=arr[i])
                s3.pop();

            if (s3.empty())
                next_greater[i]=(n-1-i);
            else
                next_greater[i]=(s3.top()-i-1);
            s3.push(i);
        }
        
        for (int i=0; i<n; i++)
        {
            while(!s4.empty() && arr[s4.top()]<arr[i])
                s4.pop();

            if (s4.empty())
                prev_greater[i]=(i);
            else
                prev_greater[i]=(i-s4.top()-1);
            s4.push(i);
        }

        for (int i=0; i<n; i++)
        {
            //cout << prev_smaller[i] << " " << next_smaller[i] << endl;
            ans += ((long long)arr[i]*((long long)prev_greater[i]+1)*((long long)next_greater[i]+1));
            ans -= ((long long)arr[i]*((long long)prev_smaller[i]+1)*((long long)next_smaller[i]+1));
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
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
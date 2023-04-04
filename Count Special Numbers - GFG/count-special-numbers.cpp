//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) 
    {
        map <int,int> mp;
        
        for (auto it:arr)
        {
            mp[it]++;
        }
        
        int ans = 0;
        
        for (int i=0; i<arr.size(); i++)
        {
            mp[arr[i]]--;
            
            for (int j=1; j<=sqrt(arr[i]); j++)
            {
                if (arr[i]%j==0 && (mp[j] || mp[arr[i]/j]))
                {
                    ans++;
                    break;
                }
            }
            
            mp[arr[i]]++;
        }
        
        return ans;
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

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
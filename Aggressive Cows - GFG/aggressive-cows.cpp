//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool possible (int mid, int k, vector<int>&stalls)
    {
        int i=0,n=stalls.size(),cows=1,start=stalls[0];
        while(i<n)
        {
            while(i<n && (stalls[i]-start)<mid)
                i++;
            if (i<n && (stalls[i]-start)>=mid)
            {
                cows++;
                start=stalls[i];
            }
            i++;
        }
        // cout << mid << " " << cows<< endl;
        return cows>=k;
    }

    int solve(int n, int k, vector<int> &stalls) 
    {
        int low = 0, high = 1e9,ans;
        sort(stalls.begin(), stalls.end());
        while(low<=high)
        {
            int mid = (low+high)/2;
            //cout << mid << " " << possible(mid,k,stalls) << endl;
            if (possible(mid,k,stalls))
            {
                low = mid+1;
                ans = mid;
            }
            
            else
            {
                high = mid-1;
            }
        }
        return ans;
    
        // Write your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
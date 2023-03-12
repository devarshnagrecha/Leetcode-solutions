//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int n) 
    {
        int maxi = INT_MIN, m = mat[0].size(), ans = -1;
        
        for (int i=0; i<n; i++)
        {
             for (int j=0; j<m; j++)
             {
                 if (mat[i][j])
                 {
                     if (m-j>maxi)
                     {
                         maxi = m-j;
                         ans = i;
                     }
                 }
             }
        }
        
        if (ans==-1)
            return {0,0};
        return {ans,maxi};
        //code here
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends
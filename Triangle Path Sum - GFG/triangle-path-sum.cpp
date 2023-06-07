//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) 
    {
        vector<int>prev=triangle[0],curr;
        for (int i=1; i<n; i++)
        {
            curr.resize(triangle[i].size());
            for (int j=0; j<triangle[i].size(); j++)
            {
                if (j==0)
                    curr[j]=triangle[i][j]+prev[j];
                else if (j==triangle[i].size()-1)
                    curr[j]=triangle[i][j]+prev[j-1];
                else
                    curr[j]=(triangle[i][j]+min(prev[j],prev[j-1]));
                    
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for (auto it:prev)
            mini = min(mini, it);
        return mini;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends
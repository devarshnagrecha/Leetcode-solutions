//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        for (int i=1; i<n; i++)
        {
            points[i][0]=points[i][0]+max(points[i-1][1],points[i-1][2]);
            points[i][1]=points[i][1]+max(points[i-1][0],points[i-1][2]);
            points[i][2]=points[i][2]+max(points[i-1][0],points[i-1][1]);
        }
        
        return max({points[n-1][0],points[n-1][1],points[n-1][2]});
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
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
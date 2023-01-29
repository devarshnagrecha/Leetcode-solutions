//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) 
    {
        int n = heights.size(), m = heights[0].size();
        
        int dx[] = {0,1,-1,0};
        int dy[] = {1,0,0,-1};
        
        vector< vector<int>> effort (n, vector<int>(m,INT_MAX));
        effort[0][0]=0;
        
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        
        while(!pq.empty())
        {
            int k = pq.size();
            while (k--)
            {
                auto it = pq.top();
                pq.pop();
                
                int currEffort = it[0], x = it[1], y = it[2];
                
                // if (x==n-1 && y==m-1)
                //     return currEffort;
                
                for (int i=0; i<4; i++)
                {
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    
                    if (newx>=0 && newy>=0 && newx<n && newy<m)
                    {
                        int newEffort = max (currEffort, abs(heights[x][y] - heights[newx][newy]));
                        
                        if (effort[newx][newy] > newEffort)
                        {
                            effort[newx][newy] = newEffort;
                            pq.push({newEffort, newx, newy});
                        }
                    }
                }
            }
        }
        
        // for (int i=0; i<n; i++)
        // {
        //     for (int j=0; j<m; j++)
        //     {
        //         cout << effort[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return effort[n-1][m-1]==INT_MAX?0:effort[n-1][m-1];
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
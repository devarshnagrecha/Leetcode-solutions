//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isValid (int x, int y,vector<vector<int>> &grid)
    {
        if (x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]!=1)
        {
            return false;
        }
        grid[x][y] = 2 ;
        return true;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) 
    {
        int moves = 0;
        
        queue <pair<int,int>> q;
        q.push(source);
        
        while(!q.empty())
        {
            int k = q.size();
            
            while(k--)
            {
                auto it = q.front();
                int x = it.first;
                int y = it.second;
                
                if (make_pair(x,y)==destination)
                    return moves;
                q.pop();
                
                if (isValid(x,y+1,grid))
                    q.push({x,y+1});
                if (isValid(x,y-1,grid))
                    q.push({x,y-1});
                if (isValid(x+1,y,grid))
                    q.push({x+1,y});
                if (isValid(x-1,y,grid))
                    q.push({x-1,y});
                
            }
            moves++;
        }
        
        return -1;
        // code here
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
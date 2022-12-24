// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    
    bool isValid (int i, int j, int n, int m, vector<vector<int>>&grid)
    {
        if (i<0 || j<0 || i>=n || j>=m || grid[i][j]==1)
            return false;
        grid[i][j]=1;
        return true;
    }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(), m = grid[0].size();
	    
	    vector<vector<int>> ans(n, vector<int>(m,0));
	    
	    queue<vector<int>>q;
	    
	    for (int i=0; i<n; i++)
	    {
	        for (int j=0; j<m; j++)
	        {
	            if (grid[i][j])
	            {
	                q.push({i,j});
	            }
	        }
	    }
	    
	    int moves = 1;
	    
	    while(!q.empty())
	    {
	        int k = q.size();
	        
	        for (int x=0; x<k; x++)
	        {
	            auto it=q.front();
	            q.pop();
	            
	            int i = it[0];
	            int j = it[1];
	            
	            if (isValid(i+1,j,n,m,grid))
	            {
	                ans[i+1][j]=moves;
	                q.push({i+1,j});
	            }
	            
	            if (isValid(i,j+1,n,m,grid))
	            {
	                ans[i][j+1]=moves;
	                q.push({i,j+1});
	            }
	            
	            if (isValid(i-1,j,n,m,grid))
	            {
	                ans[i-1][j]=moves;
	                q.push({i-1,j});
	            }
	            
	            if (isValid(i,j-1,n,m,grid))
	            {
	                ans[i][j-1]=moves;
	                q.push({i,j-1});
	            }
	                
	        }
	        
	        moves++;
	        
	        
	    }
	    
	    return ans;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
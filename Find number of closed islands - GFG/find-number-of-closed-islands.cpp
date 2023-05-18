//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
    void dfs1 (vector<vector<int>>& matrix, int i, int j)
    {
        int n = matrix.size(), m = matrix[0].size();
        if (i>=0 && j>=0 && i<n && j<m && matrix[i][j]==1)
        {
            matrix[i][j]=0;
            
            dfs1 (matrix,i+1,j);
            dfs1 (matrix,i-1,j);
            dfs1 (matrix,i,j+1);
            dfs1 (matrix,i,j-1);
        }
    }
    
    void dfs2 (vector<vector<int>>& matrix, int i, int j)
    {
        int n = matrix.size(), m = matrix[0].size();
        if (i>=0 && j>=0 && i<n && j<m && matrix[i][j]==1)
        {
            matrix[i][j]=2;
            
            dfs2 (matrix,i+1,j);
            dfs2 (matrix,i-1,j);
            dfs2 (matrix,i,j+1);
            dfs2 (matrix,i,j-1);
        }
    }
    
    int closedIslands(vector<vector<int>>& matrix, int n, int m) 
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if ((i==0 || i==n-1 || j==0 || j==m-1) && matrix[i][j]==1)
                {
                    dfs1(matrix,i,j);
                }
            }
        }
        
        int count = 0;
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (matrix[i][j]==1)
                {
                    dfs2(matrix,i,j);
                    count++;
                }
            }
        }
        
        return count;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
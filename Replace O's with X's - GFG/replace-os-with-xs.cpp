//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isValid (int i, int j, vector<vector<char>> &mat, vector <vector <bool> > &vis, int n, int m)
    {
        if (i<0 || j<0 || i>=n || j>=m || mat[i][j]=='X' || vis[i][j])
            return false;
        vis[i][j]=true;
        return true;
    }
    
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector <vector <bool> > vis (n, vector <bool> (m,false));
        
        queue <pair<int,int>> q;
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if (mat[i][j]=='O')
                    {
                        q.push({i,j});
                        vis[i][j]=true;
                    }
                    
                }
            }
        }
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int i = it.first;
            int j = it.second;
            
            if (isValid(i+1,j,mat,vis,n,m))
                q.push({i+1,j});
            if (isValid(i,j+1,mat,vis,n,m))
                q.push({i,j+1});
            if (isValid(i-1,j,mat,vis,n,m))
                q.push({i-1,j});
            if (isValid(i,j-1,mat,vis,n,m))
                q.push({i,j-1});
        }
        
        for (int i=1; i<n; i++)
        {
            for (int j=1; j<m; j++)
            {
                if (mat[i][j]=='O' && !vis[i][j])
                {
                    mat[i][j]='X';
                }
                
            }
        }
        return mat;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
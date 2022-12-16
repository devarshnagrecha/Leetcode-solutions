// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int m, int n, vector<vector<int>> gold)
    {

        for (int j=1; j<n; j++)
        {
            for (int i=0; i<m; i++)
            {
                int u=-1,l=-1,d=-1;
                
                l = gold[i][j-1] + gold[i][j];
                
                if (i!=0)
                    u=gold[i-1][j-1]+gold[i][j];
                if (i!=m-1)
                    d=gold[i+1][j-1]+gold[i][j];
                    
                gold[i][j] = max(l, max(u,d));
            }
        }
        
        int ans = 0;
        
        for (int i=0; i<m; i++)
        {
            ans = max(ans, gold[i][n-1]);
        }
        
        /*for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cout << gold[i][j] << " ";
            }
            cout << endl;
        }*/
        
        return ans;
 
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
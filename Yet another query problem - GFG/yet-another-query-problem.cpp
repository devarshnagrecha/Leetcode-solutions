//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &arr, vector<vector<int>> &q) 
    {
        map <int,int> freq;
        
        for (auto it:arr)
        {
            freq[it]++;
        }
        
        vector<int>test(n);
        vector<int>ans;
        
        for (int i=0; i<n; i++)
        {
            test[i] = freq[arr[i]];
            freq[arr[i]]--;
        }
        
        for (auto it:q)
        {
            int l = it[0], r = it[1], k = it[2],count=0;
            
            for (int i=l; i<=r; i++)
            {
                if (test[i]==k)
                    count++;
            }
            
            ans.push_back(count);
        }
        
        return ans;
        // code here
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) 
    {
        int i=1, j=n, count=0;
        bool sig = true;
        while(i<j)
        {
            if (sig==1)
            {
                i++;
                count++;
            }
            else
            {
                j--;
                count++;
            }
            
            if (count==k)
            {
                count = 0;
                sig = !sig;
            }
        }
        return i;
        // code here
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
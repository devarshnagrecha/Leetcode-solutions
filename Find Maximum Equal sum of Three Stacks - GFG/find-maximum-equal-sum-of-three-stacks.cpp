//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &v1,vector<int> &v2,vector<int> &v3)
    {
        int i=0,j=0,k=0;
        
        int s1 = accumulate(v1.begin(), v1.end(),0);
        int s2 = accumulate(v2.begin(), v2.end(),0);
        int s3 = accumulate(v3.begin(), v3.end(),0);
        
        while(i<n1 && j<n2 && k<n3)
        {
            
            //cout << s1 << " " << s2 << " " << s3 << endl;
            
            if (s1==s2 && s2==s3)
            {
                return s1;
            }
            
            int maxi = max (s1, max(s2,s3));
            
            if (s1==maxi)
            {
                s1-=v1[i];
                i++;
            }
            
            else if (s2==maxi)
            {
                s2-=v2[j];
                j++;
            }
            
            else if (s3==maxi)
            {
                s3-=v3[k];
                k++;
            }
            
        }
        
        if (s1==s2 && s2==s3)
            {
                return s1;
            }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
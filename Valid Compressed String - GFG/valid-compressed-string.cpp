//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) 
    {
        int j = s.size()-1;
        for (int i=t.size()-1; i>=0; i--)
        {
            if (t[i]>='A' && t[i]<='Z')
            {
                if (j>=0 && s[j]==t[i])
                {
                    j--;
                }
                
                else
                {
                    //cout << s[j] << " " << t[i] ;
                    return 0;
                }
            }
            
            else
            {
                int num = 0, mul = 1;
                while (i>=0 && t[i]>='0' && t[i]<='9')
                {
                    num += (mul*(t[i]-'0'));
                    mul *= 10;
                    i--;
                }
                
                j-=num;
                
                if (j<-1)
                    return 0;
                i++;
            }
        }
        
        return 1;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
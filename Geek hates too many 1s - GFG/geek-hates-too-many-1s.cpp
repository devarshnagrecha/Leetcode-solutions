//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) 
    {
        int count1 = 0, ans = 0;
        string s="";
        
        while(n)
        {
            s += to_string(n&1);
            n >>= 1;
        }
        
        reverse(s.begin(), s.end());
        // cout << s << endl;
        
        int power = s.size()-1;
        
        while(power>=0)
        {
            if (s[s.size()-1-power]=='1')
            {
                count1++;
                
                if (count1==3)
                    count1=0;
                
                else
                    ans += pow(2,power);
            }
            
            else
            {
                count1=0;
            }
            
            
            power--;
        }
        
        return ans;
        
        // code here
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends
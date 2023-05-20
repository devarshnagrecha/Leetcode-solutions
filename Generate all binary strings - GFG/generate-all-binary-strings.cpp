//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void solve(string temp, int num)
    {
        if (temp.size()>num)
            return;
            
        if (temp.size()==num)
            cout << temp << " ";
        
        string s = temp + "0";
        solve(s,num);
        
        if (temp.size()==0 || (temp.size()>0 && temp.back()!='1'))
        {
            string t = temp + "1";
            solve(t,num);
        }
    }
    void generateBinaryStrings(int num)
    {
        string temp = "";
        solve(temp, num);
        //Write your code
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
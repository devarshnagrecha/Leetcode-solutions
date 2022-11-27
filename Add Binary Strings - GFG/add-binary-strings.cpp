//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    string ans = "";
	    
	    int n=a.size(),m=b.size(),c=0,s=0,i=n-1,j=m-1;
	    
	    while(i>=0 || j>=0 || c)
	    {
	        if (i>=0)
	        {
	            if(a[i]=='1')
	            {
	                s+=1;
	            }
	        }
	        
	        if (j>=0)
	        {
	            if(b[j]=='1')
	            {
	                s+=1;
	            }
	        }
	        
	        if (c)
	        {
	            s+=c;
	        }
	        
	        if (s==3)
	        {
	            s=1;
	            c=1;
	        }
	        
	        else if (s==2)
	        {
	            s=0;
	            c=1;
	        }
	        
	        else if (s==1)
	        {
	            s=1;
	            c=0;
	        }
	        
	        else
	        {
	            s=0;
	            c=0;
	        }
	        
	        //cout << c << " " << s << endl;
	        ans += to_string(s);
	        i--;
	        j--;
	        s=0;
	    }
	    
	    
	    i=ans.size()-1;
	    while(i>=0 && ans[i]=='0')
	    {
	        i--;
	        ans.pop_back();
	    }
	    reverse(ans.begin(),ans.end());
	    return ans.size()==0?"0":ans;
	    // your code here
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
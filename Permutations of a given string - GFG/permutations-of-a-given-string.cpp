//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void solve(set<string> &ans,string s,int l)
	    {
	        if (l==s.size())
	            ans.insert(s);
	        
	        for (int i=l; i<s.size(); i++)
	        {
	            swap(s[i],s[l]);
	            solve(ans,s,l+1);
	            swap(s[l],s[i]);
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    set<string>ans;
		    int n = s.size();
		    solve(ans,s,0);
		    vector<string>res(ans.begin(),ans.end());
		    return res;
		    // Code here there
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
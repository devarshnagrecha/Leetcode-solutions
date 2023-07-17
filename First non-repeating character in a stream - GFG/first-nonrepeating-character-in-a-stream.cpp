//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A)
		{
		    queue<char>q;
		    map <char,int> mp;
		    string ans = "";
		    for (auto it:A)
		    {
		        if (mp.find(it)==mp.end())
		        {
		            mp[it]++;
		            q.push(it);
		        }
		        else
		        {
		            vector<char>temp;
		            while(!q.empty())
		            {
		                temp.push_back(q.front());
		                q.pop();
		            }
		            for (auto ct:temp)
		            {
		                if (ct!=it)
		                    q.push(ct);
		            }
		        }
		            
	            if (!q.empty())
	                ans += q.front();
	            else
	                ans += '#';
		    }
	        return ans;
		    // Code here
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
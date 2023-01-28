//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) 
    {
        unordered_map <string,bool> mp,vis;
        
        int moves = 1;
        
        for (auto it:wordList)
        {
            mp[it]++;
        }
        
        queue <string> q;
        q.push(startWord);
        vis[startWord]=true;
        
        while(!q.empty())
        {
            int x = q.size();
            
            while(x--)
            {
                string curr = q.front();
                q.pop();
                
                if (curr==targetWord)
                {
                    return moves;
                }
                
                for (int i=0; i<curr.size(); i++)
                {
                    for (char c='a'; c<='z'; c++)
                    {
                        char temp = curr[i];
                        curr[i]=c;
                        if (mp[curr] && !vis[curr])
                        {
                            q.push(curr);
                            vis[curr]=true;
                        }
                        curr[i]=temp;
                    }
                }
            }
            moves++;
        }
        
        return 0;
        // Code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
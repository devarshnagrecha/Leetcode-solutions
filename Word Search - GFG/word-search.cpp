//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) 
    {
        int n = board.size(), m= board[0].size();
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (solve(0,board,i,j,word))
                    return true;
            }
        }
        return false;
        
        // Code here
    }
    
    bool solve(int it, vector<vector<char>>& board, int i, int j, string word)
    {
        if (it==word.size())
            return true;
        
        if (i>=board.size() || j>=board[0].size() || i<0 || j<0 || board[i][j]!=word[it])
            return false;
        
        board[i][j]='.';
        
        if (solve(it+1,board,i+1,j,word) || solve(it+1,board,i,j+1,word) || solve(it+1,board,i-1,j,word) || solve(it+1,board,i,j-1,word))
            return true;
        
        board[i][j] = word[it];
        return false;
            
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
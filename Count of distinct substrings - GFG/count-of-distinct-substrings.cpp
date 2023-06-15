//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

class TrieNode {

    public:
    TrieNode *next[26];

    TrieNode()
    {
        for (int i=0; i<26; i++)
        {
            next[i]=NULL;
        }
    }
};

class Trie{

    public:
    TrieNode * root;

    Trie(){

        root = new TrieNode();
        // Write your code here.
    }

    void insert(string &word){

        TrieNode* temp = root;
        for (auto it:word)
        {
            if (temp->next[it-'a']==NULL)
                temp->next[it-'a']=new TrieNode();
            temp = temp->next[it-'a'];
        }
        // Write your code here.
    }
};

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    int ans = 0, n=s.size();
    Trie t;
    
    for (int i=0; i<n; i++)
    {
        TrieNode * temp = t.root;
        for (int j=i; j<n; j++)
        {
            if (temp->next[s[j]-'a']==NULL)
            {
                temp->next[s[j]-'a']=new TrieNode();
                ans++;
            }
            temp = temp->next[s[j]-'a'];
        }
    }
    
    return ans+1;
    //Your code here
}
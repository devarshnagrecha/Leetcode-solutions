class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector <string> data = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set <string> mp;
        
        for (auto word:words)
        {
            string s="";
            for (auto it:word)
            {
                s += data[it-'a'];
            }
            mp.insert(s);
        }
        
        return mp.size();
        
    }
};
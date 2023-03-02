class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int ans = 0;
        
        for (int i=0; i<chars.size(); i++)
        {
            char c = chars[i];
            int count = 0;
            while(i<chars.size() && chars[i]==c)
            {
                i++;
                count++;
            }
            
            chars[ans]=c;
            ans++;
            if (count!=1)
            {
                int dig = (to_string(count)).size();
                for (auto it:to_string(count))
                {
                    chars[ans++] = it;
                }
            }
            i--;
                
        }
        
        return ans;
        
    }
};
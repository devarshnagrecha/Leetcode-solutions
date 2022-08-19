class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map <int,int> freq, tail;
        
        for (auto it:nums)
        {
            freq[it]++;
        }
        
        for (auto i:nums)
        {
            if (!freq[i])
                continue;
            
            freq[i]--;
            
            if (tail[i-1])
            {
                tail[i-1]--;
                tail[i]++;
            }
            
            else if (freq[i+1] && freq[i+2])
            {
                freq[i+1]--;
                freq[i+2]--;
                tail[i+2]++;
            }
            
            else
                return false;
        }
        
        return true;
        
    }
};
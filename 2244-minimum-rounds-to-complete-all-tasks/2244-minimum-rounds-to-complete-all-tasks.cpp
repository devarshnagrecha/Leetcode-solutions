class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        int ans = 0;
        
        map <int,int> freq;
        for (auto it:tasks)
        {
            freq[it]++;
        }
        
        for (auto it:freq)
        {
            if (it.second==1)
            {
                return -1;
            }
            
            if (it.second%3==1 || it.second%3==2)
            {
                ans += it.second/3;
                ans++;
            }
            
            else if (it.second%3==0)
            {
                ans += it.second/3;
            }
        }
        
        return ans;
    }
};
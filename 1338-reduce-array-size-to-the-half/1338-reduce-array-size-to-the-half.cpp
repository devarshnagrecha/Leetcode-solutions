class Solution {
public:
    
    static bool comp (vector <int> a, vector<int> b)
    {
        return a[0]>b[0];
    }
    
    int minSetSize(vector<int>& arr) 
    {
        unordered_map <int,int> mp;
        
        for (auto it:arr)
        {
            mp[it]++;
        }
        
        priority_queue <int> pq;
        
        for (auto it:mp)
        {
            pq.push(it.second);
        }
        
        int size  = arr.size(), n = size, ans = 0;
        while(size>n/2)
        {
            size -= pq.top();
            pq.pop();
            ans++;
        }
        
        return ans;
    }
};
class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        int moves = 0, n = arr.size();
        
        unordered_map<int,vector<int>> mp;
        unordered_map<int,int>vis;
        
        for (int i=0; i<n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        
        queue<int>q;
        q.push(0);
        vis[0]++;
        
        while(!q.empty())
        {
            int x = q.size();
            
            while(x--)
            {
                int it = q.front();
                q.pop();
                
                if (it==n-1)
                {
                    return moves;
                }
                
                vector<int>&next = mp[arr[it]];
                next.push_back(it+1);
                next.push_back(it-1);
                
                for (auto ct:next)
                {
                    if (ct>=0 && ct<n && !vis[ct])
                    {
                        q.push(ct);
                        vis[ct]++;
                    }
                        
                }
                next.clear();
            }
            
            moves++;
        }
        
        return 0;
        
    }
};
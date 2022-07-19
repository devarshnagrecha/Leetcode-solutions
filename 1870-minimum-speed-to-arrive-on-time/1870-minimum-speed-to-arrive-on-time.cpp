class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        if (hour<=dist.size()-1)
            return -1;
        
        int start = 1, end = 1e7;
        
        while(start<end)
        {
            int mid = (start+end)/2;
            int count=0;
            
            for (int i=0; i<dist.size()-1; i++)
            {
                count += dist[i]/mid + (dist[i]%mid?1:0);
            }

            
            if ((double)dist[dist.size()-1]/mid + count<=hour)
                end = mid;
               
            else
                start = mid+1;
        }
        
        return start;
        
    }
};
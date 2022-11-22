class Solution {
public:
    int numSquares(int n) 
    {
        queue<int> q;
        q.push(0);
        int moves = 1;
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int x = q.front();
                q.pop();
                
                for (int i=1; i<=n; i++)
                {
                    int temp = x + i*i;
                    if (temp==n)
                    {
                        return moves;
                    }
                    
                    if (temp>n)
                    {
                        break;
                    }
                    
                    q.push(temp);
                }
            }
            
            moves++;
        }
        return -1;
    }
};
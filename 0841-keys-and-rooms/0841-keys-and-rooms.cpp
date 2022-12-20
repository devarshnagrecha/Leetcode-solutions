class Solution {
public:
    
    void dfs (int u, vector<vector<int>> &rooms, vector <bool> &visited)
    {
        if (!visited[u])
        {
            visited[u]=true;
            
            for (auto it:rooms[u])
                dfs (it, rooms, visited);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        vector <bool> visited(rooms.size(), false);
        
        dfs (0, rooms, visited);
        
        for (auto it:visited)
            if (!it)
                return false;
        return true;  
    }
};
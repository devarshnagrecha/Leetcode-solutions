class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) 
    {
        int n = arr.size();
        vector <int> ans(n,0);
        
        stack <int> st;
        
        st.push(n-1);
        
        for (int i=n-2; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
            {
                st.pop();
            }
            
            if (!st.empty())
                ans[i]=st.top()-i;
            st.push(i);
        }
        
        
        return ans;
        
    }
};
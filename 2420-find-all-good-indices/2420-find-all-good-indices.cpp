class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) 
    {
        
        int n = nums.size();
        vector <int> start_dsc(n), end_asc(n);
        
        start_dsc[0]=1,end_asc[n-1]=1;
        
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]<=nums[i-1])
                start_dsc[i] = start_dsc[i-1]+1;
            else
                start_dsc[i]=1;
        }
        
        for (int i=nums.size()-2; i>=0; i--)
        {
            if (nums[i]<=nums[i+1])
                end_asc[i] = end_asc[i+1]+1;
            else
                end_asc[i]=1;
        }
        
        /*for (auto it:start_dsc)
            cout << it << " ";
        cout << endl;
        
        for (auto it:end_asc)
            cout << it << " ";
        cout << endl;*/
        
        vector<int>ans;
        
        for (int i=1; i<n-1; i++)
        {
            if (end_asc[i+1]>=k && start_dsc[i-1]>=k)
                ans.push_back(i);
        }
        
        return ans;
    }
};
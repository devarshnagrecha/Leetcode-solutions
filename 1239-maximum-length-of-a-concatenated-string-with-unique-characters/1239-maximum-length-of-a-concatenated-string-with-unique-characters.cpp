class Solution {
public:
    int maxLength(vector<string>& arr) 
    {
        string str = "";
        int index = 0;
        return temp(arr,str,index);
    }
    
    int temp(vector<string>& arr, string str = "", int index = 0) 
    {
        unordered_set<char> s(str.begin(), str.end());
        if (s.size() != ((int)str.length())) 
            return 0;
        
        int ret = str.length();
        
        for (int i = index; i < arr.size(); i++)
            ret = max(ret, temp(arr, str+arr[i], i+1));

        return ret;
    }
};
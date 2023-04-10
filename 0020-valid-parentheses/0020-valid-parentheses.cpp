class Solution {
public:
    bool isValid(string s) 
    {
        stack <char> st;
        
        if(s.length() == 0)
            return true;
        
        if(s.length() == 1)
            return false;
    
        for(int i =0 ; i < s.length(); i++)
        {
            char c = s[i];
            
            if(c == '}'|| c == ')' || c == ']')
            {
                if(st.size() == 0 ) 
                    return false;
                
                if(c == '}' && st.top() != '{') 
                    return false;
                
                if(c == ')' && st.top() != '(') 
                    return false;
                
                if(c == ']' && st.top() != '[') 
                    return false;
                
                st.pop();
            
            } 
            
            else 
                st.push(c);
        }
        
            if(st.size() == 0)
                return true;
            else
                return false;
    }
};
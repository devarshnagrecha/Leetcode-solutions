/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        queue<Node*>q;
        q.push(root);
        
        if (root)
            ans.push_back({root->val});
        
        while (q.size())
        {
            int size = q.size();
            vector<int>temp;
            
            while (size--)
            {
                auto it = q.front();
                q.pop();
                
                if (it)
                {
                    for (auto child:it->children)
                    {
                        if (child)
                        {
                            temp.push_back(child->val);
                            q.push(child);
                        }
                    }
                }
                
            }
            
            ans.push_back(temp);
        }
        
        if(ans.size())
        ans.pop_back();
        return ans;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{

public:
    Node* cloneGraph(Node* node) 
    {
        if(!node)
            return NULL;
        
        unordered_map<Node*,Node*> map;
        
        Node* copy=new Node(node->val); 
        map[node]=copy; 
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty())
        {
            Node* t=q.front();
            q.pop();
            
            for(Node* x:t->neighbors)     
            {
                if(!map.count(x))        
                {
                    map[x]=new Node(x->val);   
                    q.push(x);
                }
                map[t]->neighbors.push_back(map[x]);   
            }
            
        }
        return copy;
    }
};
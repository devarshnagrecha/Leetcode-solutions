/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector <double> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        if (root)
            ans.push_back(1.0*root->val);
        
        while (!q.empty())
        {
            int size = q.size();
            double it = 0, count = 0;
            
            while (size--)
            {
                TreeNode * temp = q.front();
                q.pop();
                if (temp->left)
                {
                    q.push(temp->left);
                    it += temp->left->val;
                    count++;
                }
                
                if (temp->right)
                {
                    q.push(temp->right);
                    it += temp->right->val;
                    count++;
                }
            }
            
            if (count)
                ans.push_back(1.0*it/count);
        }
        
        return ans;
    }
};
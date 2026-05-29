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
    vector<int> largestValues(TreeNode* root) {
        vector<int>m;
        if(root==NULL)
          return m;
        queue<TreeNode*>q;
        q.push(root);
        int max;
        while(!q.empty())
        {
            int size=q.size();
            max=INT_MIN;
            while(size)
            {
              TreeNode* t=q.front();
              if(max<t->val)
                max=t->val;
              q.pop();
              size--;
              if(t->left)
                q.push(t->left);
              if(t->right)
                q.push(t->right);
            }
            m.push_back(max);
        }
        return m;
    }
};
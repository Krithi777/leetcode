/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* t, TreeNode* p, TreeNode* q)
    {
        if(t==NULL || t==p || t==q)
          return t;
        if(t->val>p->val && t->val>q->val)
           return dfs(t->left,p,q);
        else if(t->val<p->val && t->val<q->val)
           return dfs(t->right,p,q);
        return t;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};
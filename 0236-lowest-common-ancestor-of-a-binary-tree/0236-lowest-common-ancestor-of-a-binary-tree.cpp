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
    TreeNode* dfs(TreeNode* t,TreeNode* p, TreeNode* q)
    {
        if(t==NULL || t==p || t==q)
          return t;
        TreeNode* l=dfs(t->left,p,q);
        TreeNode* r=dfs(t->right,p,q);
        if(l && r)
          return t; 
        return l?l:r;    
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};
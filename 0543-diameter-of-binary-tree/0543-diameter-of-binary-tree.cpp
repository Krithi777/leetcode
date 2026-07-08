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
    int dfs(TreeNode* t,int& val)
    {
        if(t==NULL)
          return 0;
        int m=dfs(t->left,val);
        int n=dfs(t->right,val);
        int h=max(m,n)+1;
        val=max(val,m+n);
        return h;
       
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
           return 0;
        int k=0;
        int m=dfs(root,k);
        return k;
    }
};
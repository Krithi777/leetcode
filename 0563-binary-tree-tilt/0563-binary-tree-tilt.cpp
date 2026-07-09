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
    int dfs(TreeNode* t,int& v)
    {
        if(t==NULL)
          return 0;
        int m=dfs(t->left,v);
        int n=dfs(t->right,v);
        v+=abs(m-n);
        return t->val+m+n;
    }
    int findTilt(TreeNode* root) {
        int k=0;
        dfs(root,k);
        return k;
    }
};
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
    int dfs(TreeNode* t,int& k)
    {
        if(t==NULL)
          return -1;
        int m=dfs(t->left,k);
        k--;
        if(k==0)
           return t->val;
        int n=dfs(t->right,k);
        if(m!=-1)
          return m;
        return n;
    }
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root,k);
    }
};
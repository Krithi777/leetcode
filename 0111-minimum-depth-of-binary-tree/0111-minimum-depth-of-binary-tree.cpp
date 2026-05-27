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
    int dep(TreeNode* t)
    {
        if(t==NULL)
         return 0;
        if(t->left==NULL)
          return 1+dep(t->right);
        else if(t->right==NULL)
          return 1+dep(t->left);
        else 
          return 1+min(dep(t->left),dep(t->right));
    }
    int minDepth(TreeNode* root) {
        return dep(root);
    }
};
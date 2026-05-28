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
    bool sum(TreeNode* t, int s)
    {
        if(t==NULL)
         return false;
        s=s-t->val;
        if(s==0 && !t->left && !t->right)
          return true;
        return sum(t->left,s) || sum(t->right,s);          
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return sum(root,targetSum);
    }
};
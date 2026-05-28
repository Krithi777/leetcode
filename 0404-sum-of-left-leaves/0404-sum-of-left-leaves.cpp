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
    int sum(TreeNode* t)
    {
        if(t==NULL)
          return 0;
        int value=0;
        if(t->left && !t->left->right && !t->left->left)
           value=t->left->val;
        return value+sum(t->left)+sum(t->right);
    } 
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root);
    }
};
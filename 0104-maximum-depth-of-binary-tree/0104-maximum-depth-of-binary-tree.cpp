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
       return 1+max(dep(t->left),dep(t->right));
    }
    int maxDepth(TreeNode* root) {
       return dep(root);
    }
};
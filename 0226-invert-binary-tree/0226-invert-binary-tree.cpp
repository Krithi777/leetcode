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
    void invert(TreeNode* t)
    {
       if(!t)
         return;
        swap(t->left,t->right);
        invert(t->left);  
        invert(t->right); 
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
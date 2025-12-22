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
    TreeNode* min(TreeNode* t)
    {
        if(!t)
          return t;
        while(t->left!=NULL)
          t=t->left;
        return t;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
           return root;
        if(key<root->val)
          root->left=deleteNode(root->left,key);
        else if(key>root->val)
          root->right=deleteNode(root->right,key);
        else
        {
            if(root->left==NULL)
            {
                TreeNode* t=root->right;
                delete root;
                return t;
            }
            if(root->right==NULL)
            {
                TreeNode* t=root->left;
                delete root;
                return t;
            }
            TreeNode* t=min(root->right);
            root->val=t->val;
            root->right=deleteNode(root->right,t->val);
        }
        return root;
    }
};
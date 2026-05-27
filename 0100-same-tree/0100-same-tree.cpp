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
    bool issame(TreeNode* s, TreeNode* t)
    {
        if(s==NULL ^ t==NULL)
          return false;
        if(s==NULL && t==NULL)
          return true;
        return (s->val==t->val && issame(s->left,t->left) && issame(s->right,t->right));        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return issame(p,q);
    }
};
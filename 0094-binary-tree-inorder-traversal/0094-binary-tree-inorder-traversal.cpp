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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>s;
        TreeNode* t=root;
        while(t!=NULL || !s.empty())
        {
            while(t!=NULL)
            {
                s.push(t);
                t=t->left;
            }
            t=s.top();
            s.pop();
            res.push_back(t->val);
            t=t->right;
        }
        return res;
    }
};
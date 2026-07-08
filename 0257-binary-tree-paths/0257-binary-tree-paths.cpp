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
    vector<string>s;
    void dfs(TreeNode* t,string k)
    {
        if(t==NULL)
          return;
        k+=to_string(t->val);
        if(t->left==NULL && t->right==NULL)
        {
           s.push_back(k);
           return;
        }
        k+="->";
        dfs(t->left,k);
        dfs(t->right,k);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return s;
    }
};
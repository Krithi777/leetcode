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
    TreeNode* dfs(vector<int>&nums,int i,int j)
    {
        if(i>j)
           return NULL;
        int mid=i+(j-i)/2;
        TreeNode* t=new TreeNode(nums[mid]);
        t->left=dfs(nums,i,mid-1);
        t->right=dfs(nums,mid+1,j);
        return t;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1); 
    }
};
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
    int height(TreeNode *root){
        if(!root)   return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        if(!root->left && !root->right) return 0;

        int l = diameterOfBinaryTree(root->left), r = diameterOfBinaryTree(root->right);
        return max(max(l,r),height(root->left) + height(root->right));


    }
};
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
                
        TreeNode *temp;
        temp = root->left;
        root->left = root->right;//invertTree(root->right);
        root->right = temp;
        if(root->left)
            root->left = invertTree(root->left);
        if(root->right)
            root->right = invertTree(root->right);
        return root;
    }
};
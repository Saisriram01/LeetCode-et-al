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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool out = false;
        if(!root) return out;
        if(!root->left && !root->right)
            if(targetSum - root->val == 0)
                return true;
            else 
                return false;
        
        else{
            out = hasPathSum(root->left, targetSum - root->val);
            if(out)
                return true;
            out = hasPathSum(root->right, targetSum - root->val);
            return out;
        }
    }
};
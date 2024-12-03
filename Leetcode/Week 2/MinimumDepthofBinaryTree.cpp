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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int l_c = 0, r_c = 0;
        if(!root->left && !root->right)
            return 1;
        else{
            if(root->left)
                l_c = 1 + minDepth(root->left);
            if(root->right)
                r_c = 1 + minDepth(root->right);
        }
        if(!l_c)
            return r_c;
        else if(!r_c)
            return l_c;
        return l_c < r_c? l_c : r_c;
    }
};
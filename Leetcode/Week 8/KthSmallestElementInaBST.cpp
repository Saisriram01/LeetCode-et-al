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
    int answer;
    void func(TreeNode *root, int &k){
        if(!root)
            return;
        func(root->left,k);
        k--;
        if(!k){
            answer = root->val;
            return;}
        func(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        func(root,k);
        return answer;
    }
};
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
    vector<string> answers;
    bool skip = true;

    void btpath(TreeNode *root, string ans){
        // if(!root)   return;
        if(!root->left && !root->right){
            if(!skip)
            ans += "->" + to_string(root->val);
            answers.push_back(ans);
            return;
        }
        if(!skip)    ans += "->" + to_string(root->val);
        skip = false;
        if(root->left)     btpath(root->left, ans);
        if(root->right)    btpath(root->right, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string ans{""};
        ans += to_string(root->val);
        btpath(root,ans);
        // btpath(root->right,ans);
        return answers;
    }
};
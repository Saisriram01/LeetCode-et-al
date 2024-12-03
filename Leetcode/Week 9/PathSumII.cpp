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
    vector<vector<int>> ans;

    void func(TreeNode* root, vector<int>& temp, int target) {
        if (!root)
            return;
        temp.push_back(root->val); 
        
        if (!root->left && !root->right && !(target - root->val)) {
            ans.push_back(temp); 
        } 
        
        else {
            
            if (root->left) 
                func(root->left, temp, target - root->val);
            if (root->right)
                func(root->right, temp, target - root->val);
        }
        temp.pop_back();  
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> temp;
        func(root, temp, target);
        return ans;
    }
};
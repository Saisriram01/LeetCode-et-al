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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> out;
        if(!root)   return out;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> temp; //temp contains node vals at a level

            for(int i = 0; i < s; i++){
                TreeNode * tempnode = q.front();
                q.pop();
                temp.push_back(tempnode->val);

                if(tempnode->left)
                    q.push(tempnode->left);
                if(tempnode->right)
                    q.push(tempnode->right);
            }
            out.push_back(temp);
        }
        reverse(out.begin(), out.end());
        return out;
    }
};
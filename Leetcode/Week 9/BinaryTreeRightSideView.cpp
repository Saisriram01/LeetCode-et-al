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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) 
            return {};
        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        TreeNode* prev = nullptr;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == nullptr) {
                ans.push_back(prev->val);
                if (!q.empty()) 
                    q.push(nullptr);
                
            } 
            else {
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                prev = temp; 
            }
        }
        return ans;
    }
};








/*

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    vector<int> out1,out2;
    if(!root)   return {};    
    auto getrightnodes = [](TreeNode *root){
        vector<int> out;
        while(root){
            out.push_back(root->val);
            if(root->right){
                root = root->right;
            }
            else
                root = root->left;
        }
        return out;
    };

        
        out1 = getrightnodes(root->right);
        out2 = getrightnodes(root->left);
        if(out1.size() < out2.size()){
            int i = out1.size();
            while(i < out2.size())
                out1.push_back(out2[i++]);
        }
        out1.insert(out1.begin(),root->val); 
        return out1;
    }
};*/
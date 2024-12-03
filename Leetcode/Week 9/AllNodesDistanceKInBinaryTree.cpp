/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *, TreeNode *> parentlist;
    void match_parent(TreeNode* root) {
        queue<TreeNode *> temp;
        temp.push(root);

        while (!temp.empty()) {
            TreeNode* node = temp.front();
            temp.pop();

            if (node->left) {
                parentlist[node->left] = node;
                temp.push(node->left);
            }

            if (node->right) {
                parentlist[node->right] = node;
                temp.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        match_parent(root);

        queue<TreeNode *> temp;
        temp.push(target);
        unordered_map<TreeNode*, bool> seen;
        seen[target] = true;

        int curr = 0;

        while (!temp.empty()) {
            
            if (curr == k) 
                break;
            curr++;

            int size = temp.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = temp.front();
                temp.pop();

                // Checking the left child
                if (node->left && !seen[node->left]) {
                    seen[node->left] = true;
                    temp.push(node->left);
                }

                // Checking the right child
                if (node->right && !seen[node->right]) {
                    seen[node->right] = true;
                    temp.push(node->right);
                }

                // Checking the parent
                if (parentlist[node] && !seen[parentlist[node]]) {
                    seen[parentlist[node]] = true;
                    temp.push(parentlist[node]);
                }
            }
        }

        vector<int> ans;
        while (!temp.empty()) {
            ans.push_back(temp.front()->val);
            temp.pop();
        }

        return ans;
    }
};
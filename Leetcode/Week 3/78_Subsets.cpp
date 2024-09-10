class Solution {
public:
    void subset(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int i){
        if(i >= nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        subset(ans, curr, nums, i+1);
        curr.pop_back();
        subset(ans, curr, nums, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> curr;

        subset(ans, curr, nums, 0);
        return ans;
    }
};
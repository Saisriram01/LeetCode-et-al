class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dparr(nums.size(),1);
        if(nums.size() == 1)    return 1;
        int max_len_till_there = 0, ans = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            for(int j = i - 1; j >= 0; j --){
                if(nums[i] > nums[j]){
                    max_len_till_there = max(dparr[j], max_len_till_there);
                }
            }
            dparr[i] = max_len_till_there + 1;
            ans = max(ans, dparr[i]);
            max_len_till_there = 0;
        }
        return ans;
    }
};
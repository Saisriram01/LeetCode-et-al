class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], maxtillnow = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxtillnow = max(maxtillnow + nums[i], nums[i]);
            res = max(res, maxtillnow);
        }
        return res;
    }
};
// Divide and conquor method:

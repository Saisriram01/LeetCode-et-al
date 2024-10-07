class Solution {
public:
    int f(vector<int> &nums, int k, int j, int i, int size){
        int taken = 0, nottaken = 0;
        for(;i < size; i++){
            taken = nums[i] + k;
            nottaken = j;
            k = j;
            j = max(taken, nottaken);
        }
        return j;

    }
    int rob(vector<int>& nums) {
        int k = 0, j = nums[0], i = 1;
        if(nums.size() == 1)
            return nums[0];
        return max(f(nums, k, j, i, nums.size() - 1),f(nums, k, nums[1], 2, nums.size()));

    }
};
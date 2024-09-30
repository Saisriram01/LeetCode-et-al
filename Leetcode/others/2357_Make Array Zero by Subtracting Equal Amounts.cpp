class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        auto subtract = [&](int j, int val){
            for(int i = j; i < nums.size(); i++){
                nums[i] -= val;
            }
        };
        for(int i = 0; i < nums.size(); i++){
            if(!nums[i])
                continue;
            subtract(i, nums[i]);
            count++;
        }
        return count;
    }
};
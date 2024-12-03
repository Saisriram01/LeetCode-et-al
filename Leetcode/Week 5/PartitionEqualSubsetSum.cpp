class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i = 0; i< nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 == 1)    
            return false;
        int target = sum/2;
        vector<bool> arr_prev(target+1, false), arr_curr(target+1, false);
        if(nums[0]<=target)
            arr_prev[nums[0]] = true;
        bool with, without;
        for(int i = 1; i < nums.size(); i++){
            arr_prev[0] = true;
            arr_curr[0] = true;
            for(int j = 0; j <= target; j++){
                without = arr_prev[j];
                with = false;
                if(nums[i] <= j)
                    with = arr_prev[j - nums[i]];
                arr_curr[j] = without | with;
            }
            if(arr_prev[target])
                return true;
            arr_prev = arr_curr;
        }

        return arr_curr[target];
    }
};
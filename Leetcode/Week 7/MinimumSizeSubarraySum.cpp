class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = INT_MAX, l = 0, r = 0, n = nums.size(); //min==minlength
        int curr_sum = 0;
        for(; r < n; r++){
            curr_sum += nums[r];
            while(curr_sum >= target){
                if(r - l + 1 < min)
                    min = r - l + 1;
                curr_sum -= nums[l];
                l++;
            }
        }
        return min==INT_MAX ? 0 : min;
    }
};



/*
Asked for subarray....but i like an indiot sorted the array:
        sort(nums.begin(), nums.end());
        if(nums[nums.size()-1] >= target)    return 1;
        int sum = 0, n = nums.size() -1;
        while(n-- > 0){
            sum += nums[n];
            if(sum > target)
                return nums.size() - n;
        }
        return 0;
*/
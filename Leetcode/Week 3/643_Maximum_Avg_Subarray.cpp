class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, max = 0;
        for(int i = 0; i < k; i++)
            sum += nums[i];
        max = sum;
        for(int i = k; i < nums.size(); i++)
            {
                sum = sum - nums[i-k] + nums[i];
                if(sum > max)
                    max = sum;
            }
        return static_cast<double>(max) / k;
    }
};
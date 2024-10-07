class Solution {
public:
    int rob(vector<int>& nums) {
        int k = 0, j = nums[0], i = 1;
        int taken = 0, nottaken = 0;
        for(; i < nums.size(); i++){
            taken = nums[i] + k;
            nottaken = j;
            
            k = j;
            j = max(taken, nottaken);
        }   

        return j;
    }
};
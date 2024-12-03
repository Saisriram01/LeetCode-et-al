class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(),1), count(nums.size(),1);
        int glo_max = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[i] > nums[j]){
                    if(lis[j]+1 > lis[i]){
                        lis[i] = lis[j]+1;
                        count[i] = count[j];
                    }
                    else if(lis[j]+1 == lis[i])
                        count[i] += count[j];
                }
            }
            glo_max = max(glo_max, lis[i]);
        }
    int ans = 0;
    for(int i = 0; i < nums.size(); i++)
        if(lis[i] == glo_max)
            ans += count[i];
    return ans;
    }
};
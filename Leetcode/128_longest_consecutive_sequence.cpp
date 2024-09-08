class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,bool> presence;
        for(int x:nums) presence[x] = true;
        for(int i = 0;i<nums.size();i++) {
            if (!presence[nums[i] - 1]) {
                
                int len = 1;
                int next = nums[i] + 1;
                while(presence[next]) {
                    len+=1;
                    next+=1;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};
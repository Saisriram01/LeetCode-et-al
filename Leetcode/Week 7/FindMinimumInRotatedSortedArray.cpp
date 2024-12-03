class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] < nums[nums.size() - 1])
            return nums[0];
        int l = 0, r = nums.size() - 1, mid = (l + r) / 2;
        while(l < r){
                if(nums[mid] > nums[r])
                    l = mid + 1;
                else
                    r = mid;
                mid = (l + r) / 2;

        }
        
        return nums[l];
    }
};
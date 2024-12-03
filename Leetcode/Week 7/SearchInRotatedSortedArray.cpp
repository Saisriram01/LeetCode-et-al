class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l = 0, r = nums.size() - 1, mid = (l + r) / 2;
        while(l <= r){
            if(nums[mid] == t)  
                return mid;

            if(nums[l] <= nums[mid])
                if(nums[l] <= t && nums[mid] > t)
                    r = mid - 1;
                else
                    l = mid + 1;
            else{
                if(nums[mid] < t and nums[r] >= t)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            mid = (l + r) / 2;
        }
        return -1;

    }

};
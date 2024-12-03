class Solution {
public:
    int quickselect(vector<int> &nums, int l, int  r, int &k){
        int pivot = nums[r], p = l;
        for(int i = p ; i < r; i++){
            if(nums[i] <= pivot){
                swap(nums[p], nums[i]);
                p++;
            }
        }
        swap(nums[p], nums[r]);

        if(p > k)
            return quickselect(nums, l, p-1, k);
        else if (p < k)
            return quickselect(nums, p + 1, r, k);
        else
            return nums[p];
    }
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickselect(nums, 0, nums.size() - 1, k);
    }
};

/*
sort(nums.begin(),nums.end());
        return nums[nums.size() - k];
        */
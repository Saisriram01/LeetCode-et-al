class NumArray {
public:
    vector<int> nums;
    vector<int> presum;
    NumArray(vector<int>& nums) {
        this->nums.resize(nums.size());
        this->nums = nums;
        presum.resize(nums.size());
        presum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            presum[i] = nums[i] + presum[i-1];
        }
        
    }
    
    void update(int index, int val) {
        int diff = nums[index] - val;
        nums[index] = val;
        for(int i = index; i < nums.size(); i++){
            presum[i] = presum[i] - diff;
        }
    }
    
    int sumRange(int left, int right) {
        if(!left)
            return presum[right];
        return presum[right] - presum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
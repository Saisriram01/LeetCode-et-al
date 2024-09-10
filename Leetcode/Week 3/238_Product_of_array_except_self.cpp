class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> rprod (size), lprod(size);
        rprod[size - 1] = 1;
        rprod[size - 2] = nums[size - 1];
        for (int i = size - 3; i >= 0; i--){
            rprod[i] = nums[i+1] * rprod[i+1];
        }

        lprod[1] = nums[0];
        lprod[0] = 1;
        for (int i = 2; i < size; i++){
            lprod[i] = nums[i - 1] * lprod[i-1];
        }

        for(int i=0;i<size;i++)
            lprod[i] *= rprod[i]; 
    return lprod;
    }
};